#ifndef COMPILEREXPLOREROPTIONSPAGE_H
#define COMPILEREXPLOREROPTIONSPAGE_H
#include <coreplugin/dialogs/ioptionspage.h>

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
	QWidget *mWidget;
};

#endif // COMPILEREXPLOREROPTIONSPAGE_H
