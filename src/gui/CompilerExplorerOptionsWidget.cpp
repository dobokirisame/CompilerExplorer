#include "CompilerExplorerOptionsWidget.h"
#include "ui_CompilerExplorerOptionsWidget.h"
#include <QFileDialog>

CompilerExplorerOptionsWidget::CompilerExplorerOptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompilerExplorerOptionsWidget) {
	ui->setupUi(this);
}

CompilerExplorerOptionsWidget::~CompilerExplorerOptionsWidget() {
	delete ui;
}

void CompilerExplorerOptionsWidget::loadSettings(const QSettings &settings) {
	Q_UNUSED(settings);
}

void CompilerExplorerOptionsWidget::apply(QSettings &settings) {
	Q_UNUSED(settings);
}

void CompilerExplorerOptionsWidget::on_toolButton_clicked() {
	QString res = QFileDialog::getOpenFileName(this, tr("NodeJS"),
	                                           QString(), tr("nodejs ") + "(nodejs**)");
	ui->nodejsLocation->setText(res);
}
