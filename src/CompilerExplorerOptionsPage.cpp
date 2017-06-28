#include "CompilerExplorerOptionsPage.h"
#include "QLabel"

CompilerExplorerOptionsPage::CompilerExplorerOptionsPage(QObject *parent)
    : Core::IOptionsPage(parent),
      mWidget(nullptr) {
	setId("CompilerExplorerSettings");
	setDisplayName(tr("Compiler Explorer"));
	setCategory("Compiler Explorer");
	setDisplayCategory(tr("Compiler Explorer"));
//    setCategoryIcon(Utils::Icon(Constants::ICON_TODO));
}

QWidget *CompilerExplorerOptionsPage::widget() {
	if(!mWidget)
		mWidget = new QLabel("CompilerExplorerOptionsPage");
	return  mWidget;
}

void CompilerExplorerOptionsPage::apply() {
}

void CompilerExplorerOptionsPage::finish() {
}
