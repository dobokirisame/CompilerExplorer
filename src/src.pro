include (src.pri)
DEFINES += COMPILEREXPLORER_LIBRARY

isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = $$QTC_SOURCE
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = $$QTC_BUILD

USE_USER_DESTDIR = no


QTC_PLUGIN_NAME = CompilerExplorer
QTC_LIB_DEPENDS += \
    extensionsystem

QTC_PLUGIN_DEPENDS += \
    coreplugin \
    projectexplorer

QTC_PLUGIN_RECOMMENDS += \

include($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri)

DISTFILES += \
    src.pri

SOURCES += \
    CompilerExplorerPlugin.cpp \
    gui/ExplorerOutputPane.cpp \
    gui/ExplorerOutputTable.cpp \
    gui/CompilerExplorerOptionsPage.cpp \
    gui/CompilerExplorerOptionsWidget.cpp \
    network/RequestSender.cpp \
    network/Request.cpp \
    network/GetRequest.cpp \
    network/PostJsonRequest.cpp

HEADERS += \
    compilerexplorerconstants.h \
    compilerexplorer_global.h \
    CompilerExplorerPlugin.h \
    gui/ExplorerOutputPane.h \
    gui/ExplorerOutputTable.h \
    gui/CompilerExplorerOptionsPage.h \
    gui/CompilerExplorerOptionsWidget.h \
    network/RequestSender.h \
    network/Request.h \
    network/GetRequest.h \
    network/PostJsonRequest.h

FORMS += \
    gui/CompilerExplorerOptionsWidget.ui
