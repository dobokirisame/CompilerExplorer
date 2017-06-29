#include "CompilerExplorerOptionsWidget.h"
#include "ui_CompilerExplorerOptionsWidget.h"
#include <QFileDialog>
#include "compilerexplorerconstants.h"
#include <QDebug>

namespace compilerExplorer {
namespace gui{

CompilerExplorerOptionsWidget::CompilerExplorerOptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompilerExplorerOptionsWidget) {
	ui->setupUi(this);
}

CompilerExplorerOptionsWidget::~CompilerExplorerOptionsWidget() {
	delete ui;
}

void CompilerExplorerOptionsWidget::loadSettings(const QSettings &settings) {
	auto nodejsLocation = settings.value(constants::nodejsFileNameKey, QString()).toString();
	ui->nodejsLocation->setText(nodejsLocation);
	const auto compilerExplorerLocation = settings.value(constants::compilerExplorerLocationKey,
	                                                     QString()).toString();
	ui->compilerExplorerLocation->setText(compilerExplorerLocation);
}

void CompilerExplorerOptionsWidget::apply(QSettings &settings) {
	qDebug() <<"apply";
	const auto nodejsLocation = settings.value(constants::nodejsFileNameKey, QString()).toString();
	const auto compilerExplorerLocation = settings.value(constants::compilerExplorerLocationKey,
	                                                     QString()).toString();
	settings.setValue(constants::nodejsFileNameKey,ui->nodejsLocation->text());
	qDebug() <<"nodejsFileNameKey";
	settings.setValue(constants::compilerExplorerLocationKey,ui->compilerExplorerLocation->text());
	qDebug() <<"compilerExplorerLocationKey";
	if((nodejsLocation != ui->nodejsLocation->text()) ||
	        (compilerExplorerLocation != ui->compilerExplorerLocation->text()) ) {
		emit settingsChanged();
	}
	qDebug() <<"apply finished";
}

void CompilerExplorerOptionsWidget::on_toolButton_clicked() {
	QString res = QFileDialog::getOpenFileName(this, tr("NodeJS"),
	                                           QString(), tr("node ") + "(node**)");
	ui->nodejsLocation->setText(res);
}

void CompilerExplorerOptionsWidget::on_toolButton_2_clicked() {
	QString res = QFileDialog::getExistingDirectory(this);
	ui->compilerExplorerLocation->setText(res);
}
}
}
