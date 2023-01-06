// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See V.h for the primary calling header

#include "verilated.h"

#include "V__Syms.h"
#include "V___024root.h"

void V___024root___ctor_var_reset(V___024root* vlSelf);

V___024root::V___024root(V__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    V___024root___ctor_var_reset(this);
}

void V___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

V___024root::~V___024root() {
}
