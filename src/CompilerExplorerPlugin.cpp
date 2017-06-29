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
#include <QSettings>
#include <QProcess>

#include "gui/ExplorerOutputPane.h"
#include "gui/CompilerExplorerOptionsPage.h"

namespace compilerExplorer {
namespace core {

CompilerExplorerPlugin::CompilerExplorerPlugin()
    : mOutputPane(nullptr),
      mOptionsPage(nullptr),
      mNodeJsServer(nullptr) {

}

CompilerExplorerPlugin::~CompilerExplorerPlugin() {
//	mNodeJsServer->close();
//	mNodeJsServer->kill();
	qDebug() << mNodeJsServer->pid() << mNodeJsServer->processId();
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
	mOptionsPage = new gui::CompilerExplorerOptionsPage(this);
	connect(mOptionsPage, &gui::CompilerExplorerOptionsPage::settingsChanged,
	        this, &CompilerExplorerPlugin::restartNodeJsServer);
	addAutoReleasedObject(mOptionsPage);
	mNodeJsServer = new QProcess(this);
	restartNodeJsServer();
	return true;
}

void CompilerExplorerPlugin::extensionsInitialized() {
}

ExtensionSystem::IPlugin::ShutdownFlag CompilerExplorerPlugin::aboutToShutdown() {
	return SynchronousShutdown;
}

void CompilerExplorerPlugin::restartNodeJsServer() {
	const auto &settings = mOptionsPage->settings();
	const auto nodeJsLocation = settings.value(constants::nodejsFileNameKey).toString();
	const auto compilerExplorerLocation = settings.value(constants::compilerExplorerLocationKey,
	                                                     QString()).toString();
	qDebug() << mNodeJsServer->state();
	mNodeJsServer->setProcessChannelMode(QProcess::ForwardedChannels);
	if(mNodeJsServer->state() == QProcess::Running) {
		mNodeJsServer->kill();
	}
//	/usr/bin/nodejs ./node_modules/.bin/supervisor -w app.js,lib,etc/config -e 'js|node|properties' --exec /usr/bin/node -- ./app.js --language C++
	QStringList args;
	args
//	        << compilerExplorerLocation + "/node_modules/.bin/supervisor" <<
//	        "-w" << compilerExplorerLocation +"/app.js,lib,etc/config" <<
//	        "-e" << "\'js|node|properties\'" << "--exec"
//	     << nodeJsLocation << "--"
	        << compilerExplorerLocation +"/app.js" << "--language C++";
	qDebug() << "result command:";
	qDebug() << nodeJsLocation + " " + args.join(" ");
	mNodeJsServer->setWorkingDirectory(compilerExplorerLocation);
	mNodeJsServer->start(nodeJsLocation + " " + args.join(" "));
}

}
}
