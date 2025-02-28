//
// Created by Anton A. Vasilev on 28.02.2025
//
// Exports for IVN script run-time (see core_exports.h)
// 

#ifndef AS_IS_EXPORTS_H
#define AS_IS_EXPORTS_H

#ifdef _MSC_VER

#define EXPORT_FUNC(name) __pragma(comment(linker, "/EXPORT:"#name"="#name))

EXPORT_FUNC(__isRuntimeOnEnter)

#undef EXPORT_FUNC

#endif // _MSC_VER

#endif // AS_IS_EXPORTS_H
