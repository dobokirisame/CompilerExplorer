#pragma once

#include "compilerexplorer_global.h"

#include <extensionsystem/iplugin.h>

class QProcess;
namespace compilerExplorer {
namespace gui {
class ExplorerOutputPane;
class CompilerExplorerOptionsPage;
}
namespace core {

class CompilerExplorerPlugin : public ExtensionSystem::IPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "CompilerExplorer.json")

public:
	CompilerExplorerPlugin();
	~CompilerExplorerPlugin();

	bool initialize(const QStringList &arguments, QString *errorString);
	void extensionsInitialized();
	ShutdownFlag aboutToShutdown();

private:
	void restartNodeJsServer();
private:
	gui::ExplorerOutputPane *mOutputPane;
	gui::CompilerExplorerOptionsPage *mOptionsPage;
	QProcess *mNodeJsServer;
};

} // namespace Internal
} // namespace QCompilerExplorer
