// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See V.h for the primary calling header

#include "verilated.h"

#include "V___024root.h"

void V___024root___eval_act(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___eval_act\n"); );
}

VL_INLINE_OPT void V___024root___nba_sequent__TOP__0(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __Vdly__Top__DOT__x;
    __Vdly__Top__DOT__x = 0;
    SData/*15:0*/ __Vdly__Top__DOT__y;
    __Vdly__Top__DOT__y = 0;
    // Body
    __Vdly__Top__DOT__y = vlSelf->Top__DOT__y;
    __Vdly__Top__DOT__x = vlSelf->Top__DOT__x;
    if (vlSelf->io_loadingValues) {
        __Vdly__Top__DOT__x = vlSelf->io_value1;
        __Vdly__Top__DOT__y = vlSelf->io_value2;
    } else {
        if (((IData)(vlSelf->Top__DOT__x) > (IData)(vlSelf->Top__DOT__y))) {
            __Vdly__Top__DOT__x = vlSelf->Top__DOT___x_T_1;
        }
        if (((IData)(vlSelf->Top__DOT__x) <= (IData)(vlSelf->Top__DOT__y))) {
            __Vdly__Top__DOT__y = vlSelf->Top__DOT___y_T_1;
        }
    }
    vlSelf->Top__DOT__x = __Vdly__Top__DOT__x;
    vlSelf->Top__DOT__y = __Vdly__Top__DOT__y;
    vlSelf->io_outputGCD = vlSelf->Top__DOT__x;
    vlSelf->io_outputValid = (0U == (IData)(vlSelf->Top__DOT__y));
    vlSelf->Top__DOT___x_T_1 = (0xffffU & ((IData)(vlSelf->Top__DOT__x) 
                                           - (IData)(vlSelf->Top__DOT__y)));
    vlSelf->Top__DOT___y_T_1 = (0xffffU & ((IData)(vlSelf->Top__DOT__y) 
                                           - (IData)(vlSelf->Top__DOT__x)));
}

void V___024root___eval_nba(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        V___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void V___024root___eval_triggers__act(V___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void V___024root___dump_triggers__act(V___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void V___024root___dump_triggers__nba(V___024root* vlSelf);
#endif  // VL_DEBUG

void V___024root___eval(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            V___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    V___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("sim_src/generated_files/verilog/Top.v", 7, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                V___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                V___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("sim_src/generated_files/verilog/Top.v", 7, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            V___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void V___024root___eval_debug_assertions(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_loadingValues & 0xfeU))) {
        Verilated::overWidthError("io_loadingValues");}
}
#endif  // VL_DEBUG
