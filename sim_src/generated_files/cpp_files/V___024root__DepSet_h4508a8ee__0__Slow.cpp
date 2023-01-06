// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See V.h for the primary calling header

#include "verilated.h"

#include "V___024root.h"

VL_ATTR_COLD void V___024root___eval_static(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___eval_static\n"); );
}

VL_ATTR_COLD void V___024root___eval_initial(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
}

VL_ATTR_COLD void V___024root___eval_final(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___eval_final\n"); );
}

VL_ATTR_COLD void V___024root___eval_triggers__stl(V___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void V___024root___dump_triggers__stl(V___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void V___024root___eval_stl(V___024root* vlSelf);

VL_ATTR_COLD void V___024root___eval_settle(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        V___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                V___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("sim_src/generated_files/verilog/Top.v", 7, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            V___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void V___024root___dump_triggers__stl(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void V___024root___stl_sequent__TOP__0(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->io_outputGCD = vlSelf->Top__DOT__x;
    vlSelf->io_outputValid = (0U == (IData)(vlSelf->Top__DOT__y));
    vlSelf->Top__DOT___x_T_1 = (0xffffU & ((IData)(vlSelf->Top__DOT__x) 
                                           - (IData)(vlSelf->Top__DOT__y)));
    vlSelf->Top__DOT___y_T_1 = (0xffffU & ((IData)(vlSelf->Top__DOT__y) 
                                           - (IData)(vlSelf->Top__DOT__x)));
}

VL_ATTR_COLD void V___024root___eval_stl(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        V___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void V___024root___dump_triggers__act(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void V___024root___dump_triggers__nba(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void V___024root___ctor_var_reset(V___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    V__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    V___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_value1 = VL_RAND_RESET_I(16);
    vlSelf->io_value2 = VL_RAND_RESET_I(16);
    vlSelf->io_loadingValues = VL_RAND_RESET_I(1);
    vlSelf->io_outputGCD = VL_RAND_RESET_I(16);
    vlSelf->io_outputValid = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__x = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT__y = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT___x_T_1 = VL_RAND_RESET_I(16);
    vlSelf->Top__DOT___y_T_1 = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigrprev__TOP__clock = VL_RAND_RESET_I(1);
}
