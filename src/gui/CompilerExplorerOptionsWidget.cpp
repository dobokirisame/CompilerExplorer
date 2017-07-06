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
	const auto nodejsLocation = settings.value(constants::nodejsFileNameKey, QString()).toString();
	ui->nodejsLocation->setText(nodejsLocation);
	const auto compilerExplorerLocation = settings.value(constants::compilerExplorerLocationKey,
	                                                     QString()).toString();
	ui->compilerExplorerLocation->setText(compilerExplorerLocation);
	const auto useLocalServer = settings.value(constants::useLocalServerKey, true).toBool();
	ui->useLocalServerButton->setChecked(useLocalServer);
	ui->useRemoteServer->setChecked(!useLocalServer);
	const auto localPort = settings.value(constants::localServerPortKey,
	                                            10240).toInt();
	ui->localPort->setValue(localPort);
	const auto remoteServerUrl = settings.value(constants::remoteServerUrlKey,
	                                            QString("https://gcc.godbolt.org/")).toString();
	ui->remoteServerUrl->setText(remoteServerUrl);
	ui->localServerGroupBox->setEnabled(useLocalServer);
	ui->remoteServerUrl->setEnabled(!useLocalServer);
}

void CompilerExplorerOptionsWidget::apply(QSettings &settings) {
	const auto nodejsLocation = settings.value(constants::nodejsFileNameKey, QString()).toString();
	const auto compilerExplorerLocation = settings.value(constants::compilerExplorerLocationKey,
	                                                     QString()).toString();
	const auto useLocalServer = settings.value(constants::useLocalServerKey).toBool();
	const auto remoteServerUrl = settings.value(constants::remoteServerUrlKey, QString()).toString();
	const auto localPort = settings.value(constants::localServerPortKey, 10240).toInt();

	settings.setValue(constants::useLocalServerKey ,ui->useLocalServerButton->isChecked());
	settings.setValue(constants::nodejsFileNameKey, ui->nodejsLocation->text());
	settings.setValue(constants::compilerExplorerLocationKey, ui->compilerExplorerLocation->text());
	settings.setValue(constants::localServerPortKey, ui->localPort->value());
	settings.setValue(constants::remoteServerUrlKey, ui->remoteServerUrl->text());

	if((nodejsLocation != ui->nodejsLocation->text()) ||
	        (compilerExplorerLocation != ui->compilerExplorerLocation->text()) ||
	        useLocalServer != ui->useLocalServerButton->isChecked() ||
	        localPort != ui->localPort->value() ||
	        remoteServerUrl != ui->remoteServerUrl->text()) {
		emit settingsChanged();
	}
}

void CompilerExplorerOptionsWidget::on_toolButton_clicked() {
	QString res = QFileDialog::getOpenFileName(this, tr("NodeJS"),
	                                           QString(), tr("node ") + "(node**)");
	if(!res.isEmpty())
		ui->nodejsLocation->setText(res);
}

void CompilerExplorerOptionsWidget::on_toolButton_2_clicked() {
	QString res = QFileDialog::getExistingDirectory(this);
	if(!res.isEmpty())
		ui->compilerExplorerLocation->setText(res);
}
}
}
