DEFINES += COMPILEREXPLORER_LIBRARY
exists(qt_deps.pri) {
    include (qt_deps.pri)
}
QTC_PLUGIN_NAME = CompilerExplorer
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = $$QTC_SOURCE
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = $$QTC_BUILD

QTC_LIB_DEPENDS += \
    extensionsystem

QTC_PLUGIN_DEPENDS += \
    coreplugin \
    projectexplorer

include($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri)

include (src.pri)


USE_USER_DESTDIR = YES

QT += network

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
    network/PostJsonRequest.cpp \
    network/RequestGenerator.cpp \
    network/CompilersListReplyParser.cpp

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
    network/PostJsonRequest.h \
    network/RequestGenerator.h \
    network/CompilersListReplyParser.h

FORMS += \
    gui/CompilerExplorerOptionsWidget.ui

LISB +=-L$$IDE_BUILD_TREE/bin
LISB +=-L$$IDE_BUILD_TREE/lib

RESOURCES += \
    gui/images.qrc
