// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_V__SYMS_H_
#define VERILATED_V__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "V.h"

// INCLUDE MODULE CLASSES
#include "V___024root.h"

// SYMS CLASS (contains all model state)
class V__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    V* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    V___024root                    TOP;

    // CONSTRUCTORS
    V__Syms(VerilatedContext* contextp, const char* namep, V* modelp);
    ~V__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
