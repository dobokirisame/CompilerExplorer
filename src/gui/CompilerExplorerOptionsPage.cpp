#include "CompilerExplorerOptionsPage.h"
#include "CompilerExplorerOptionsWidget.h"

CompilerExplorerOptionsPage::CompilerExplorerOptionsPage(QObject *parent)
    : Core::IOptionsPage(parent),
      mWidget(nullptr) {
	setId("CompilerExplorerSettings");
	setDisplayName(tr("Compiler Explorer"));
	setCategory("Compiler Explorer");
	setDisplayCategory(tr("Compiler Explorer"));
}

QWidget *CompilerExplorerOptionsPage::widget() {
	if(!mWidget) {
		mWidget = new CompilerExplorerOptionsWidget();
		mWidget->loadSettings(mSettings);
	}
	return  mWidget;
}

void CompilerExplorerOptionsPage::apply() {
	mWidget->apply(mSettings);
}

void CompilerExplorerOptionsPage::finish() {
	delete mWidget;
}
