#ifndef EXPLOREROUTPUTPANE_H
#define EXPLOREROUTPUTPANE_H
#include <coreplugin/ioutputpane.h>
#include <QIcon>
#include <memory>

class QToolButton;
class QLineEdit;
class QTextEdit;
class QSettings;
class QLabel;
class QComboBox;

namespace compilerExplorer {
namespace network {
class RequestSender;
class RequestGenerator;
}
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
	void updateSettings(const QSettings &settings);
private:
	void createTableView();
	void createCompilerOptions();
	void createButtons();
	QToolButton *createButton(const QString &text, const QString &tooltip,
	                          bool checkable = true, const QIcon &icon = QIcon());
	void createCompilersList();
	QStringList filters() const;
	void updateCompilersList(const QString &address);
	std::map<QString, QString> compilersList(const QString &address) const;
	void setCompilers(const std::map<QString, QString> &compilers);
private slots:
	void onRunClicked();
private:
//	ExplorerOutputTable *mTableView;
	QTextEdit *mExplorer;
	QLineEdit *mCompilerOptions;
	QToolButton *mRunButton;
	QToolButton *mBinary;
	QToolButton *mLabel;
	QToolButton *mDirectives;
	QToolButton *mCommentOnly;
	QToolButton *mIntel;
	QLabel *mCurrentCompilerLabel;
	QComboBox *mCompilersList;
	std::unique_ptr<network::RequestSender> mRequestSender;
	std::unique_ptr<network::RequestGenerator> mRequestGenerator;
	std::map<QToolButton *, QString> mOptions;
};
}
}
#endif // EXPLOREROUTPUTPANE_H
