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
}

void CompilerExplorerOptionsWidget::apply(QSettings &settings) {
	const auto nodejsLocation = settings.value(constants::nodejsFileNameKey, QString()).toString();
	settings.setValue(constants::nodejsFileNameKey,ui->nodejsLocation->text());
	if(nodejsLocation != ui->nodejsLocation->text()) {
		emit settingsChanged();
	}
}

void CompilerExplorerOptionsWidget::on_toolButton_clicked() {
	QString res = QFileDialog::getOpenFileName(this, tr("NodeJS"),
	                                           QString(), tr("nodejs ") + "(nodejs**)");
	ui->nodejsLocation->setText(res);
}
}
}
