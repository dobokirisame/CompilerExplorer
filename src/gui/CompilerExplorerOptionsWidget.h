#ifndef COMPILEREXPLOREROPTIONSWIDGET_H
#define COMPILEREXPLOREROPTIONSWIDGET_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class CompilerExplorerOptionsWidget;
}
namespace compilerExplorer {
namespace gui{
class CompilerExplorerOptionsWidget : public QWidget
{
	Q_OBJECT

public:
	explicit CompilerExplorerOptionsWidget(QWidget *parent = 0);
	~CompilerExplorerOptionsWidget();
	void loadSettings(const QSettings &settings);
	void apply(QSettings &settings);
signals:
	void settingsChanged();
private slots:
	void on_toolButton_clicked();
	void on_toolButton_2_clicked();

private:
	Ui::CompilerExplorerOptionsWidget *ui;
};
}
}
#endif // COMPILEREXPLOREROPTIONSWIDGET_H
