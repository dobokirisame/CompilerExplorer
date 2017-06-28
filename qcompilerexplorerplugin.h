#pragma once

#include "qcompilerexplorer_global.h"

#include <extensionsystem/iplugin.h>

namespace QCompilerExplorer {
namespace Internal {

class QCompilerExplorerPlugin : public ExtensionSystem::IPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "QCompilerExplorer.json")

public:
	QCompilerExplorerPlugin();
	~QCompilerExplorerPlugin();

	bool initialize(const QStringList &arguments, QString *errorString);
	void extensionsInitialized();
	ShutdownFlag aboutToShutdown();

private:
	void triggerAction();
};

} // namespace Internal
} // namespace QCompilerExplorer
