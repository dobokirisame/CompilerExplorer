#include "CompilerExplorerOptionsPage.h"
#include "CompilerExplorerOptionsWidget.h"
#include <QSettings>

namespace compilerExplorer {
namespace gui{
CompilerExplorerOptionsPage::CompilerExplorerOptionsPage(QObject *parent)
    : Core::IOptionsPage(parent),
      mWidget(nullptr) {
	setId("CompilerExplorerSettings");
	setDisplayName(tr("Compiler Explorer"));
	setCategory("Compiler Explorer");
	setDisplayCategory(tr("Compiler Explorer"));
	setCategoryIcon(Utils::Icon("qrc:/images/gcc.png"));
}

QWidget *CompilerExplorerOptionsPage::widget() {
	if(!mWidget) {
		mWidget = new CompilerExplorerOptionsWidget;
		mWidget->loadSettings(mSettings);
		connect(mWidget, SIGNAL(settingsChanged()), this, SIGNAL(settingsChanged()));
	}
	return  mWidget;
}

void CompilerExplorerOptionsPage::apply() {
	if(mWidget)
		mWidget->apply(mSettings);
}

void CompilerExplorerOptionsPage::finish() {
	disconnect(mWidget, SIGNAL(settingsChanged()), this, SIGNAL(settingsChanged()));
	delete mWidget;
	mWidget = nullptr;
}

QSettings &CompilerExplorerOptionsPage::settings() {
	return mSettings;
}
}
}
