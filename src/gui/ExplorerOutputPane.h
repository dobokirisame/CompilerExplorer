#ifndef EXPLOREROUTPUTPANE_H
#define EXPLOREROUTPUTPANE_H
#include <coreplugin/ioutputpane.h>

class QToolButton;
class QLineEdit;
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
	void createTableView();
	void createCompilerOptions();
	void createButtons();
	QToolButton *createButton(const QString &text, const QString &tooltip);
private:
	ExplorerOutputTable *mTableView;
	QLineEdit *mCompilerOptions;
	QToolButton *mBinary;
	QToolButton *mLabel;
	QToolButton *mDirectives;
	QToolButton *mCommentOnly;
	QToolButton *mIntel;
};
}
}
#endif // EXPLOREROUTPUTPANE_H
