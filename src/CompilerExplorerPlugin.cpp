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

#include "gui/ExplorerOutputPane.h"
#include "gui/CompilerExplorerOptionsPage.h"

namespace compilerExplorer {
namespace core {

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

	mOutputPane = new gui::ExplorerOutputPane(this);
	addAutoReleasedObject(mOutputPane);

	auto action = new QAction(tr("Run Compiler Explorer"), this);
	Core::Command *cmd = Core::ActionManager::registerAction(action, constants::ACTION_ID,
	                                                         Core::Context(Core::Constants::C_GLOBAL));
	connect(action, &QAction::triggered, mOutputPane, &gui::ExplorerOutputPane::runCompilerExplorer);

	Core::ActionContainer *menu = Core::ActionManager::createMenu(constants::MENU_ID);
	menu->menu()->setTitle(tr("Compiler Explorer"));
	menu->addAction(cmd);
	Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

	auto panelFactory = new ProjectExplorer::ProjectPanelFactory;
	panelFactory->setPriority(0);
	panelFactory->setDisplayName(tr("Compile Explorer"));
	ProjectExplorer::ProjectPanelFactory::registerFactory(panelFactory);

	auto mOptionsPage = new gui::CompilerExplorerOptionsPage(this);
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
