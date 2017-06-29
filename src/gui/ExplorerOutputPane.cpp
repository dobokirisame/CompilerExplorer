#include "ExplorerOutputPane.h"
#include "ExplorerOutputTable.h"
#include <QMessageBox>
#include <coreplugin/icore.h>
namespace compilerExplorer {
namespace gui{
ExplorerOutputPane::ExplorerOutputPane(QObject *parent)
    : Core::IOutputPane(parent) {
	mTableView = new ExplorerOutputTable();
}

ExplorerOutputPane::~ExplorerOutputPane() {
	delete  mTableView;
}

void ExplorerOutputPane::runCompilerExplorer() {
	QMessageBox::information(Core::ICore::mainWindow(),
	                         tr("Action Triggered"),
	                         tr("This is an action from CompilerExplorer."));

}

QWidget *ExplorerOutputPane::outputWidget(QWidget *parent) {
	Q_UNUSED(parent);
	return mTableView;
//	return new QLabel("ExplorerOutputPane", parent);
}

QList<QWidget *> ExplorerOutputPane::toolBarWidgets() const {
	return {};
}

QString ExplorerOutputPane::displayName() const {
	return QString("Compiler Explorer");
}

int ExplorerOutputPane::priorityInStatusBar() const {
	return 1;
}

void ExplorerOutputPane::clearContents() {
}

void ExplorerOutputPane::visibilityChanged(bool visible) {
	Q_UNUSED(visible);
}

void ExplorerOutputPane::setFocus() {
}

bool ExplorerOutputPane::hasFocus() const{
	return false;
}

bool ExplorerOutputPane::canFocus() const {
	return false;
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
}
}
