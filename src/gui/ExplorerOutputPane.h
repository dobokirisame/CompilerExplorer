#ifndef EXPLOREROUTPUTPANE_H
#define EXPLOREROUTPUTPANE_H
#include <coreplugin/ioutputpane.h>
#include <QIcon>
#include <memory>
#include "compilerexplorer_global.h"

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

class COMPILEREXPLORERSHARED_EXPORT ExplorerOutputPane : public Core::IOutputPane
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
	std::unique_ptr<QToolButton> createButton(const QString &text, const QString &tooltip,
	                          bool checkable = true, const QIcon &icon = QIcon());
	void createCompilersList();
	QStringList filters() const;
	void updateCompilersList(const QString &address);
	std::map<QString, QString> compilersList(const QString &address) const;
	void setCompilers(const std::map<QString, QString> &compilers);
private slots:
	void onRunClicked();
private:
	std::shared_ptr<QTextEdit> mExplorer;
	std::shared_ptr<QLineEdit> mCompilerOptions;
	std::shared_ptr<QToolButton> mRunButton;
	std::shared_ptr<QToolButton> mBinary;
	std::shared_ptr<QToolButton> mLabel;
	std::shared_ptr<QToolButton> mDirectives;
	std::shared_ptr<QToolButton> mCommentOnly;
	std::shared_ptr<QToolButton> mIntel;
	std::shared_ptr<QLabel> mCurrentCompilerLabel;
	std::shared_ptr<QComboBox> mCompilersList;
	std::unique_ptr<network::RequestSender> mRequestSender;
	std::unique_ptr<network::RequestGenerator> mRequestGenerator;
	std::map<std::shared_ptr<QToolButton> , QString> mOptions;
};
}
}
#endif // EXPLOREROUTPUTPANE_H
