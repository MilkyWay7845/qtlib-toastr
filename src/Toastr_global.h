#ifndef TOASTR_GLOBAL_H
#define TOASTR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TOASTR_LIBRARY)
#  define TOASTR_EXPORT Q_DECL_EXPORT
#else
#  define TOASTR_EXPORT Q_DECL_IMPORT
#endif

#endif // TOASTR_GLOBAL_H
