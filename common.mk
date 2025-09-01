TOP_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
# common.mk is included from cpp/, but always located at repo root
REPO_ROOT := $(abspath $(TOP_DIR))

CXX = g++
CXXFLAGS = -Wall -g -I$(REPO_ROOT)
SRC = $(wildcard *.cpp)
EXE = $(basename $(SRC))
BUILD_DIR = $(TOP_DIR)/build
BIN = $(addprefix $(BUILD_DIR)/,$(EXE))

all: $(BUILD_DIR) $(BIN) link-latest

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


$(BUILD_DIR)/%: %.cpp $(REPO_ROOT)/lc_test_utils.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

link-latest: $(BIN)
	@echo "Linking $(REPO_ROOT)/solution -> $(lastword $(BIN))"
	@ln -sf $(lastword $(BIN)) $(REPO_ROOT)/solution

clean:
	rm -f $(BIN)
