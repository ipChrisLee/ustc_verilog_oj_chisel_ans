# Verilated -*- CMake -*-
# DESCRIPTION: Verilator output: CMake include script with class lists
#
# This CMake script lists generated Verilated files, for including in higher level CMake scripts.
# This file is meant to be consumed by the verilate() function,
# which becomes available after executing `find_package(verilator).

### Constants...
set(PERL "perl" CACHE FILEPATH "Perl executable (from $PERL)")
set(VERILATOR_ROOT "/usr/local/share/verilator" CACHE PATH "Path to Verilator kit (from $VERILATOR_ROOT)")

### Compiler flags...
# User CFLAGS (from -CFLAGS on Verilator command line)
set(V_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(V_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(V_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(V_COVERAGE 0)
# Timing mode?  0/1
set(V_TIMING 0)
# Threaded output mode?  1/N threads (from --threads)
set(V_THREADS 1)
# VCD Tracing output mode?  0/1 (from --trace)
set(V_TRACE_VCD 0)
# FST Tracing output mode? 0/1 (from --trace-fst)
set(V_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(V_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_threads.cpp")
# Generated module classes, non-fast-path, compile with low/medium optimization
set(V_CLASSES_SLOW "sim_src/generated_files/cpp_files/V___024root__Slow.cpp" "sim_src/generated_files/cpp_files/V___024root__DepSet_hd8332d84__0__Slow.cpp" "sim_src/generated_files/cpp_files/V___024root__DepSet_h4508a8ee__0__Slow.cpp")
# Generated module classes, fast-path, compile with highest optimization
set(V_CLASSES_FAST "sim_src/generated_files/cpp_files/V.cpp" "sim_src/generated_files/cpp_files/V___024root__DepSet_hd8332d84__0.cpp" "sim_src/generated_files/cpp_files/V___024root__DepSet_h4508a8ee__0.cpp")
# Generated support classes, non-fast-path, compile with low/medium optimization
set(V_SUPPORT_SLOW "sim_src/generated_files/cpp_files/V__Syms.cpp")
# Generated support classes, fast-path, compile with highest optimization
set(V_SUPPORT_FAST )
# All dependencies
set(V_DEPS "/usr/local/bin/verilator_bin" "sim_src/generated_files/verilog/Top.v")
# User .cpp files (from .cpp's on Verilator command line)
set(V_USER_CLASSES )
