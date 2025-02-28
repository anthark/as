//
// Created by Anton A. Vasilev on 28.02.2025
//
// This file contains the list of linker directives for explicit export of run-time used functions
// LLVM Orc2 JIT only sees function exported from executable or dynamic library, so they must be
// specified for OS that need explicit export directive
// 

#ifndef AS_CORE_EXPORTS_H
#define AS_CORE_EXPORTS_H

#ifdef _MSC_VER

#define EXPORT_FUNC(name) __pragma(comment(linker, "/EXPORT:"#name"="#name))

EXPORT_FUNC(__asRegisterVTable)
EXPORT_FUNC(__asRequireRuntime)
EXPORT_FUNC(__asRegisterInit)

#undef EXPORT_FUNC

#endif // _MSC_VER

#endif // AS_CORE_EXPORTS_H
