cmake_minimum_required(VERSION 3.22)
project(Test)

# sbt
set(SBT_PATH "/home/iplee/.local/share/coursier/bin/sbt")

if (NOT SBT_PATH)
	message(FATAL_ERROR "Install sbt and run startup.sh first!")
endif ()

find_package(verilator HINTS $ENV{VERILATOR_ROOT} ${VERILATOR_ROOT})
if (NOT verilator_FOUND)
	message(FATAL_ERROR "Verilator was not found. Either install it, or set the VERILATOR_ROOT environment variable")
endif ()

set(GEN_VERILOG_TOP_FILE sim_src/generated_files/verilog/Top.v)
file(GLOB_RECURSE ALL_CHISEL_SRC src/*.scala)

message($ENV{PATH})

add_custom_command(
		OUTPUT ${GEN_VERILOG_TOP_FILE}
		COMMAND ${SBT_PATH} "runMain TopApp --target-dir sim_src/generated_files/verilog"
		DEPENDS ${ALL_CHISEL_SRC}
		WORKING_DIRECTORY ../
		VERBATIM
)

add_executable(
		test
		sim_src/src/main.cpp
)
verilate(
		test
		SOURCES sim_src/generated_files/verilog/Top.v
		TOP_MODULE Top
		PREFIX V
		INCLUDE_DIRS sim_src/generated_files/cpp_files
)