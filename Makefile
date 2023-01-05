TOPNAME = Top
NVBOARD_SUP_DIR=./nvboard-sup
NXDC_FILES = $(NVBOARD_SUP_DIR)/constr/Top.nxdc
BUILD_DIR = $(NVBOARD_SUP_DIR)/build
OBJ_DIR = $(BUILD_DIR)/obj_dir
VSRC_DIR = $(BUILD_DIR)/vsrc
CSRC_DIR = $(BUILD_DIR)/csrc
BIN = $(BUILD_DIR)/$(TOPNAME)
ifneq ($(shell mkdir -p $(NVBOARD_SUP_DIR) $(BUILD_DIR) $(OBJ_DIR) $(VSRC_DIR) $(CSRC_DIR); echo $$?),0)
$(error !)
endif

INC_PATH ?=

VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc -O3 --x-assign fast --x-initial fast --noassert

default: $(BIN)

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

ifneq ($(shell sbt "runMain $(TOPNAME) --target-dir $(VSRC_DIR)"),0)
$(error !)
endif

# project source
VSRCS = $(shell find $(VSRC_DIR) -name "*.v")
CSRCS = $(shell find $(CSRC_DIR) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
CSRCS += $(SRC_AUTO_BIND)

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
LDFLAGS += -lSDL2 -lSDL2_image

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		$(addprefix -CFLAGS , $(CFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

all: default

run: $(BIN)
	@$^

clean:
	rm -rf $(NVBOARD_SUP_DIR)

.PHONY: default all clean run