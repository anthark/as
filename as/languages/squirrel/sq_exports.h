//
// Created by Anton A. Vasilev on 28.02.2025
//
// Exports for Squirrel run-time (see core_exports.h)
// 

#ifndef AS_SQ_EXPORTS_H
#define AS_SQ_EXPORTS_H

#ifdef _MSC_VER

#define EXPORT_FUNC(name) __pragma(comment(linker, "/EXPORT:"#name"="#name))

EXPORT_FUNC(sq_pushobject_apapter)
EXPORT_FUNC(sq_getinteger)
EXPORT_FUNC(sq_pushroottable)
EXPORT_FUNC(sq_call)
EXPORT_FUNC(sq_pushinteger)
EXPORT_FUNC(sq_getfloat)
EXPORT_FUNC(sq_pushfloat)

#undef EXPORT_FUNC

#endif // _MSC_VER

#endif // AS_SQ_EXPORTS_H
