#pragma once

#include <memory>
#include "compilerexplorer_global.h"
#include <extensionsystem/iplugin.h>

namespace ProjectExplorer {
class ProjectPanelFactory;
}
class QProcess;
namespace compilerExplorer {
namespace gui {
class ExplorerOutputPane;
class CompilerExplorerOptionsPage;
}
namespace core {

class COMPILEREXPLORERSHARED_EXPORT CompilerExplorerPlugin : public ExtensionSystem::IPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "CompilerExplorer.json")

public:
	CompilerExplorerPlugin();
	~CompilerExplorerPlugin();

	bool initialize(const QStringList &arguments, QString *errorString);
	void extensionsInitialized();
	ShutdownFlag aboutToShutdown();
signals:
	void serverChanged();
private:
	void restartNodeJsServer();
	void updateGui();
private:
	gui::ExplorerOutputPane *mOutputPane;
	gui::CompilerExplorerOptionsPage *mOptionsPage;
	QProcess *mNodeJsServer;
	std::shared_ptr<ProjectExplorer::ProjectPanelFactory> mPanelFactory;
};

} // namespace Internal
} // namespace QCompilerExplorer
