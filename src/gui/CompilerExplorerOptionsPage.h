#ifndef COMPILEREXPLOREROPTIONSPAGE_H
#define COMPILEREXPLOREROPTIONSPAGE_H
#include <coreplugin/dialogs/ioptionspage.h>
#include <QSettings>
#include "compilerexplorer_global.h"

namespace compilerExplorer {
namespace gui{
class CompilerExplorerOptionsWidget;
class COMPILEREXPLORERSHARED_EXPORT CompilerExplorerOptionsPage : public Core::IOptionsPage
{
	Q_OBJECT
public:
	CompilerExplorerOptionsPage(QObject *parent = 0);

public:
	QWidget *widget() override;
	void apply() override;
	void finish() override;
	QSettings &settings();
signals:
	void settingsChanged();
private:
	CompilerExplorerOptionsWidget *mWidget;
	QSettings mSettings;
};
}
}
#endif // COMPILEREXPLOREROPTIONSPAGE_H
