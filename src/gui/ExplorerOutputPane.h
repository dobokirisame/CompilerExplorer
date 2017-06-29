#ifndef EXPLOREROUTPUTPANE_H
#define EXPLOREROUTPUTPANE_H
#include <coreplugin/ioutputpane.h>

namespace compilerExplorer {
namespace gui{
class ExplorerOutputTable;

class ExplorerOutputPane : public Core::IOutputPane
{
	Q_OBJECT
public:
	explicit ExplorerOutputPane(QObject *parent = 0);
	~ExplorerOutputPane();
public slots:
	void runCompilerExplorer();
public:
	QWidget *outputWidget(QWidget *parent) override;
	QList<QWidget *> toolBarWidgets() const override;
	QString displayName() const override;
	int priorityInStatusBar() const override;
	void clearContents() override;
	void visibilityChanged(bool visible) override;
	void setFocus() override;
	bool hasFocus() const override;
	bool canFocus() const override;
	bool canNavigate() const override;
	bool canNext() const override;
	bool canPrevious() const override;
	void goToNext() override;
	void goToPrev() override;
private:
	ExplorerOutputTable *mTableView;
};
}
}
#endif // EXPLOREROUTPUTPANE_H
