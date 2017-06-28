#include "CompilerExplorerPlugin.h"
#include "compilerexplorerconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <projectexplorer/projectpanelfactory.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

#include "ExplorerOutputPane.h"

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

	auto action = new QAction(tr("QCompilerExplorer Action"), this);
	Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
	                                                         Core::Context(Core::Constants::C_GLOBAL));
	cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
	connect(action, &QAction::triggered, this, &CompilerExplorerPlugin::triggerAction);

	Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
	menu->menu()->setTitle(tr("QCompilerExplorer"));
	menu->addAction(cmd);
	Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);
	//	auto outPane = new ExplorerOutputPane(this);
	//	addAutoReleasedObject(outPane);

	auto panelFactory = new ProjectExplorer::ProjectPanelFactory;
	panelFactory->setPriority(100);
	panelFactory->setDisplayName(tr("Compile Explorer"));
//	panelFactory->setCreateWidgetFunction([this, panelFactory](ProjectExplorer::Project *project) {
//		auto widget = new TodoProjectSettingsWidget(project);
//		connect(widget, &TodoProjectSettingsWidget::projectSettingsChanged,
//		        m_todoItemsProvider, [this, project] { m_todoItemsProvider->projectSettingsChanged(project); });
//		return widget;
//	});
	ProjectExplorer::ProjectPanelFactory::registerFactory(panelFactory);
	return true;
}

void CompilerExplorerPlugin::extensionsInitialized()
{
	// Retrieve objects from the plugin manager's object pool
	// In the extensionsInitialized function, a plugin can be sure that all
	// plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag CompilerExplorerPlugin::aboutToShutdown()
{
	// Save settings
	// Disconnect from signals that are not needed during shutdown
	// Hide UI (if you add UI that is not in the main window directly)
	return SynchronousShutdown;
}

void CompilerExplorerPlugin::triggerAction()
{
	QMessageBox::information(Core::ICore::mainWindow(),
	                         tr("Action Triggered"),
	                         tr("This is an action from QCompilerExplorer."));
}

} // namespace Internal
} // namespace QCompilerExplorer
