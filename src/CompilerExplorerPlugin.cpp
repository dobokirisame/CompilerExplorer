#include "CompilerExplorerPlugin.h"
#include "compilerexplorerconstants.h"


#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <projectexplorer/projectpanelfactory.h>

#include <QAction>
#include <QMainWindow>
#include <QMenu>

#include "ExplorerOutputPane.h"
#include "CompilerExplorerOptionsPage.h"

namespace CompilerExplorer {
namespace Internal {

CompilerExplorerPlugin::CompilerExplorerPlugin()
{
	// Create your members
}

CompilerExplorerPlugin::~CompilerExplorerPlugin()
{
	// Unregister objects from the plugin manager's object pool
	// Delete members
}

bool CompilerExplorerPlugin::initialize(const QStringList &arguments, QString *errorString)
{
	Q_UNUSED(arguments)
	Q_UNUSED(errorString)

	auto outPane = new ExplorerOutputPane(this);
	addAutoReleasedObject(outPane);

	auto action = new QAction(tr("Run Compiler Explorer"), this);
	Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
	                                                         Core::Context(Core::Constants::C_GLOBAL));
	connect(action, &QAction::triggered, outPane, &ExplorerOutputPane::runCompilerExplorer);

	Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
	menu->menu()->setTitle(tr("Compiler Explorer"));
	menu->addAction(cmd);
	Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

	auto panelFactory = new ProjectExplorer::ProjectPanelFactory;
	panelFactory->setPriority(0);
	panelFactory->setDisplayName(tr("Compile Explorer"));
	ProjectExplorer::ProjectPanelFactory::registerFactory(panelFactory);

	auto mOptionsPage = new CompilerExplorerOptionsPage(this);
	addAutoReleasedObject(mOptionsPage);
	return true;
}

void CompilerExplorerPlugin::extensionsInitialized() {
}

ExtensionSystem::IPlugin::ShutdownFlag CompilerExplorerPlugin::aboutToShutdown() {
	return SynchronousShutdown;
}


} // namespace Internal
} // namespace QCompilerExplorer
