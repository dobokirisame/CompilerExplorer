#pragma once

#include <QtGlobal>

#if defined(COMPILEREXPLORER_LIBRARY)
#  define COMPILEREXPLORERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define COMPILEREXPLORERSHARED_EXPORT Q_DECL_IMPORT
#endif
