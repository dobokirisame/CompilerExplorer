#ifndef COMPILEREXPLOREROPTIONSPAGE_H
#define COMPILEREXPLOREROPTIONSPAGE_H
#include <coreplugin/dialogs/ioptionspage.h>
#include <QSettings>

class CompilerExplorerOptionsWidget;
class CompilerExplorerOptionsPage : public Core::IOptionsPage
{
	Q_OBJECT
public:
	CompilerExplorerOptionsPage(QObject *parent = 0);

public:
	QWidget *widget() override;
	void apply() override;
	void finish() override;
private:
	CompilerExplorerOptionsWidget *mWidget;
	QSettings mSettings;
};

#endif // COMPILEREXPLOREROPTIONSPAGE_H
