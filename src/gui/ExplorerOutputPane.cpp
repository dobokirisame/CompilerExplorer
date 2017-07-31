#include "ExplorerOutputPane.h"
#include "ExplorerOutputTable.h"
#include <QMessageBox>
#include <coreplugin/icore.h>
#include <QLineEdit>
#include <QToolButton>
#include <QLabel>
#include <QDebug>
#include <QTextCodec>
#include <QTextEdit>
#include <QComboBox>

#include "network/Request.h"
#include "network/RequestSender.h"
#include "network/RequestGenerator.h"
#include "network/CompilersListReplyParser.h"

#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/editormanager/ieditor.h>

namespace compilerExplorer {
namespace gui{
ExplorerOutputPane::ExplorerOutputPane(QObject *parent)
    : Core::IOutputPane(parent),
      mExplorer(nullptr),
      mCompilerOptions(nullptr),
      mRunButton(nullptr),
      mBinary(nullptr),
      mLabel(nullptr),
      mDirectives(nullptr),
      mCommentOnly(nullptr),
      mIntel(nullptr),
      mCurrentCompilerLabel(nullptr),
      mCompilersList(nullptr),
      mRequestSender(std::make_unique<network::RequestSender>(this)),
      mRequestGenerator(std::make_unique<network::RequestGenerator>()){
	createTableView();
	createCompilerOptions();
	createButtons();
	createCompilersList();
}

ExplorerOutputPane::~ExplorerOutputPane() {
}

void ExplorerOutputPane::runCompilerExplorer() {
	popup(0);
	onRunClicked();
}

QWidget *ExplorerOutputPane::outputWidget(QWidget *parent) {
	Q_UNUSED(parent);
	return mExplorer.get();
}

QList<QWidget *> ExplorerOutputPane::toolBarWidgets() const {
	QList<QWidget *> result;
	result << mRunButton.get() << mCompilerOptions.get() << mBinary.get()
	       << mLabel.get() << mDirectives.get() << mCommentOnly.get()
	       << mIntel.get() << mCurrentCompilerLabel.get() << mCompilersList.get();
	return result;
}

QString ExplorerOutputPane::displayName() const {
	return QString("Compiler Explorer");
}

int ExplorerOutputPane::priorityInStatusBar() const {
	return 1;
}

void ExplorerOutputPane::clearContents() {
	mExplorer->clear();
}

void ExplorerOutputPane::visibilityChanged(bool visible) {
	Q_UNUSED(visible);
}

void ExplorerOutputPane::setFocus() {
	mExplorer->setFocus();
}

bool ExplorerOutputPane::hasFocus() const{
	return mExplorer->window()->focusWidget() == mExplorer.get();
}

bool ExplorerOutputPane::canFocus() const {
	return true;
}

bool ExplorerOutputPane::canNavigate() const {
	return false;
}

bool ExplorerOutputPane::canNext() const {
	return false;
}

bool ExplorerOutputPane::canPrevious() const{
	return false;
}

void ExplorerOutputPane::goToNext() {
}

void ExplorerOutputPane::goToPrev() {
}

void ExplorerOutputPane::updateSettings(const QSettings &settings) {
	if(mRequestGenerator)
		mRequestGenerator->updateSettings(settings);
	updateCompilersList(mRequestGenerator->address());
}

void ExplorerOutputPane::setCompilers(const std::map<QString, QString> &compilers) {
	if(compilers.empty())
		return;
	mCompilersList->setEnabled(true);
	for(const auto &compiler : compilers) {
		mCompilersList->addItem(compiler.second, compiler.first);
	}
}

void ExplorerOutputPane::createTableView() {
	mExplorer = std::make_shared<QTextEdit>();
	mExplorer->setReadOnly(true);
}

void ExplorerOutputPane::createCompilerOptions() {
	mCompilerOptions = std::make_shared<QLineEdit>("-std=c++1y -O3");
	mCompilerOptions->setPlaceholderText(tr("Compiler options..."));
}

void ExplorerOutputPane::createButtons() {
	mRunButton = createButton(tr("Run"), tr("Send request"),
	                          false, QIcon(":/images/run.png"));
	mBinary = createButton(tr("11010"),
	                       tr("Compile to binary and disassemble the output"));
	mOptions.insert({mBinary, "binary"});
	mLabel = createButton(tr(".LX0:"),
	                      tr("Filter unused labels from the output"));
	mOptions.insert({mLabel, "labels"});
	mDirectives = createButton(tr(".text"),
	                           tr("Filter all assembler directives from the output"));
	mOptions.insert({mDirectives, "directives"});
	mCommentOnly = createButton(tr("//"),
	                            tr("Remove all lines which are only comments from the output"));
	mOptions.insert({mCommentOnly, "commentOnly"});
	mIntel = createButton(tr("Intel"),
	                      tr("Output disassembly in Intel syntax"));
	mOptions.insert({mIntel, "intel"});
	connect(mRunButton.get(), &QToolButton::clicked, this, &ExplorerOutputPane::onRunClicked);
}

std::unique_ptr<QToolButton> ExplorerOutputPane::createButton(const QString &text, const QString &tooltip, bool checkable, const QIcon &icon) {
	auto btn = std::make_unique<QToolButton>();
	btn->setText(text);
	btn->setToolTip(tooltip);
	btn->setCheckable(checkable);
	if(!icon.isNull()) {
		btn->setIcon(icon);
		btn->setToolButtonStyle(Qt::ToolButtonIconOnly);
	}
	return std::move(btn);
}

void ExplorerOutputPane::createCompilersList() {
	mCurrentCompilerLabel = std::make_shared<QLabel>(tr(" Current Compiler: "));
	mCompilersList = std::make_shared<QComboBox>();
}

void ExplorerOutputPane::onRunClicked() {
	if(!mRequestSender)
		return;
	mRequestGenerator->setCompilerOptions(mCompilerOptions->text());
	mRequestGenerator->setFilters(filters());
	QByteArray source;
	if(auto currentDocument = Core::EditorManager::currentDocument())
		source = currentDocument->contents();
	auto unicodeSource = QTextCodec::codecForMib(106)->toUnicode(source); // 106 - utf8
	mRequestGenerator->setSourceCode(unicodeSource);
	mRequestGenerator->setCompilerLocation(mCompilersList->currentData().toString());
	auto request = mRequestGenerator->createCompilerRequest();
	auto reply = mRequestSender->sendRequest(std::move(request));
	mExplorer->clear();
	mExplorer->setText(QTextCodec::codecForMib(106)->toUnicode(reply));
}

QStringList ExplorerOutputPane::filters() const {
	QStringList result;
	for(auto filter : mOptions) {
		if(filter.first->isChecked())
			result.append(filter.second);
	}
	return result;

}

void ExplorerOutputPane::updateCompilersList(const QString &address) {
	auto compilers = compilersList(address);
	mCompilersList->clear();
	if(compilers.empty()) {
		mCompilersList->setEnabled(false);
		mCompilersList->addItem(tr("No Compilers found in server PATH"));
		return;
	}
	setCompilers(compilers);
}

std::map<QString, QString> ExplorerOutputPane::compilersList(const QString &address) const {
	auto request = network::RequestGenerator::comilersListRequest(address);
	auto reply = mRequestSender->sendRequest(std::move(request));
	auto parsedCompilersList = network::CompilersListReplyParser::parse(reply);
	return parsedCompilersList;
}

}
}
