#ifndef COMPILEREXPLOREROPTIONSWIDGET_H
#define COMPILEREXPLOREROPTIONSWIDGET_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class CompilerExplorerOptionsWidget;
}

class CompilerExplorerOptionsWidget : public QWidget
{
	Q_OBJECT

public:
	explicit CompilerExplorerOptionsWidget(QWidget *parent = 0);
	~CompilerExplorerOptionsWidget();
	void loadSettings(const QSettings &settings);
	void apply(QSettings &settings);
private slots:
	void on_toolButton_clicked();

private:
	Ui::CompilerExplorerOptionsWidget *ui;
};

#endif // COMPILEREXPLOREROPTIONSWIDGET_H
