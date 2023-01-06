// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "V.h"
#include "V__Syms.h"

//============================================================
// Constructors

V::V(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new V__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_loadingValues{vlSymsp->TOP.io_loadingValues}
    , io_outputValid{vlSymsp->TOP.io_outputValid}
    , io_value1{vlSymsp->TOP.io_value1}
    , io_value2{vlSymsp->TOP.io_value2}
    , io_outputGCD{vlSymsp->TOP.io_outputGCD}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

V::V(const char* _vcname__)
    : V(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

V::~V() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void V___024root___eval_debug_assertions(V___024root* vlSelf);
#endif  // VL_DEBUG
void V___024root___eval_static(V___024root* vlSelf);
void V___024root___eval_initial(V___024root* vlSelf);
void V___024root___eval_settle(V___024root* vlSelf);
void V___024root___eval(V___024root* vlSelf);

void V::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate V::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    V___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        V___024root___eval_static(&(vlSymsp->TOP));
        V___024root___eval_initial(&(vlSymsp->TOP));
        V___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    V___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool V::eventsPending() { return false; }

uint64_t V::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* V::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void V___024root___eval_final(V___024root* vlSelf);

VL_ATTR_COLD void V::final() {
    V___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* V::hierName() const { return vlSymsp->name(); }
const char* V::modelName() const { return "V"; }
unsigned V::threads() const { return 1; }
