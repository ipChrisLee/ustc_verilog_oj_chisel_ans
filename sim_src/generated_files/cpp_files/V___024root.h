// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See V.h for the primary calling header

#ifndef VERILATED_V___024ROOT_H_
#define VERILATED_V___024ROOT_H_  // guard

#include "verilated.h"

class V__Syms;

class V___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_loadingValues,0,0);
    VL_OUT8(io_outputValid,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clock;
    CData/*0:0*/ __VactContinue;
    VL_IN16(io_value1,15,0);
    VL_IN16(io_value2,15,0);
    VL_OUT16(io_outputGCD,15,0);
    SData/*15:0*/ Top__DOT__x;
    SData/*15:0*/ Top__DOT__y;
    SData/*15:0*/ Top__DOT___x_T_1;
    SData/*15:0*/ Top__DOT___y_T_1;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    V__Syms* const vlSymsp;

    // CONSTRUCTORS
    V___024root(V__Syms* symsp, const char* name);
    ~V___024root();
    VL_UNCOPYABLE(V___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
