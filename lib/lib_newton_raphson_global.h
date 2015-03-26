#ifndef LIB_NEWTON_RAPHSON_GLOBAL_H
#define LIB_NEWTON_RAPHSON_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIB_NEWTON_RAPHSON_LIBRARY)
#  define LIB_NEWTON_RAPHSONSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIB_NEWTON_RAPHSONSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIB_NEWTON_RAPHSON_GLOBAL_H
