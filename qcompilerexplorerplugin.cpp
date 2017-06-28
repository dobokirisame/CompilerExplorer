#include "qcompilerexplorerplugin.h"
#include "qcompilerexplorerconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

namespace QCompilerExplorer {
namespace Internal {

QCompilerExplorerPlugin::QCompilerExplorerPlugin()
{
	// Create your members
}

QCompilerExplorerPlugin::~QCompilerExplorerPlugin()
{
	// Unregister objects from the plugin manager's object pool
	// Delete members
}

bool QCompilerExplorerPlugin::initialize(const QStringList &arguments, QString *errorString)
{
	// Register objects in the plugin manager's object pool
	// Load settings
	// Add actions to menus
	// Connect to other plugins' signals
	// In the initialize function, a plugin can be sure that the plugins it
	// depends on have initialized their members.

	Q_UNUSED(arguments)
	Q_UNUSED(errorString)

	auto action = new QAction(tr("QCompilerExplorer Action"), this);
	Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
	                                                         Core::Context(Core::Constants::C_GLOBAL));
	cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
	connect(action, &QAction::triggered, this, &QCompilerExplorerPlugin::triggerAction);

	Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
	menu->menu()->setTitle(tr("QCompilerExplorer"));
	menu->addAction(cmd);
	Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

	return true;
}

void QCompilerExplorerPlugin::extensionsInitialized()
{
	// Retrieve objects from the plugin manager's object pool
	// In the extensionsInitialized function, a plugin can be sure that all
	// plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag QCompilerExplorerPlugin::aboutToShutdown()
{
	// Save settings
	// Disconnect from signals that are not needed during shutdown
	// Hide UI (if you add UI that is not in the main window directly)
	return SynchronousShutdown;
}

void QCompilerExplorerPlugin::triggerAction()
{
	QMessageBox::information(Core::ICore::mainWindow(),
	                         tr("Action Triggered"),
	                         tr("This is an action from QCompilerExplorer."));
}

} // namespace Internal
} // namespace QCompilerExplorer
