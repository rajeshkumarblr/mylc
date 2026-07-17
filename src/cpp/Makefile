SHELL := /bin/bash

CXX ?= g++
# Release vs Debug flags
CXXFLAGS_RELEASE ?= -std=gnu++20 -g -O0 -pipe -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -I. -Ithird_party -DLC_LOCAL_TEST
CXXFLAGS_DEBUG   ?= -std=gnu++20 -O0 -g -fno-omit-frame-pointer -pipe -Wall -Wextra -Wno-unused-parameter -Wno-sign-compare -I. -Ithird_party -DLC_LOCAL_TEST -DDEBUG -rdynamic
LDFLAGS ?=

ROOT := $(abspath $(CURDIR)/../..)
SRC_DIR := $(CURDIR)
BIN_DIR := $(ROOT)/build/cpp
BIN_DIR_DBG := $(BIN_DIR)/dbg

CATEGORY_DIRS := backtracking binary_search bit_manipulation concurrency dp graphs greedy hash heap intervals list math misc prefix_sum sliding_window stack tree trie two_pointer

# Collect all problem source files (exclude main.cpp, lc_test_utils.cpp, stubs.cpp)
PROBLEM_SRCS := $(filter-out $(SRC_DIR)/main.cpp $(SRC_DIR)/lc_test_utils.cpp $(SRC_DIR)/stubs.cpp, \
	$(foreach d,$(CATEGORY_DIRS),$(wildcard $(SRC_DIR)/$(d)/*.cpp)))

# Standalone binaries: each .cpp -> one executable
PROBLEM_BINS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%,$(PROBLEM_SRCS))
PROBLEM_BINS_DBG := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR_DBG)/%,$(PROBLEM_SRCS))

# Utility object (list/tree helpers)
UTILS_OBJ := $(BIN_DIR)/lc_test_utils.o
UTILS_OBJ_DBG := $(BIN_DIR_DBG)/lc_test_utils.o

.PHONY: all build build-all dbg clean help

$(BIN_DIR):
	mkdir -p $(BIN_DIR)
	@for d in $(CATEGORY_DIRS); do mkdir -p $(BIN_DIR)/$$d; done

$(BIN_DIR_DBG):
	mkdir -p $(BIN_DIR_DBG)
	@for d in $(CATEGORY_DIRS); do mkdir -p $(BIN_DIR_DBG)/$$d; done

# Compile lc_test_utils.o (shared helpers for list/tree)
$(UTILS_OBJ): $(SRC_DIR)/lc_test_utils.cpp $(SRC_DIR)/lc_test_utils.h | $(BIN_DIR)
	$(CXX) $(CXXFLAGS_RELEASE) -c $< -o $@

$(UTILS_OBJ_DBG): $(SRC_DIR)/lc_test_utils.cpp $(SRC_DIR)/lc_test_utils.h | $(BIN_DIR_DBG)
	$(CXX) $(CXXFLAGS_DEBUG) -c $< -o $@

# Build a standalone release binary for a solution
$(BIN_DIR)/%: $(SRC_DIR)/%.cpp $(UTILS_OBJ) | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS_RELEASE) $< $(UTILS_OBJ) -o $@ $(LDFLAGS)

# Build a standalone debug binary for a solution
$(BIN_DIR_DBG)/%: $(SRC_DIR)/%.cpp $(UTILS_OBJ_DBG) | $(BIN_DIR_DBG)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS_DEBUG) $< $(UTILS_OBJ_DBG) -o $@ $(LDFLAGS)

# Default: build all standalone release binaries
all: build-all

build-all: $(PROBLEM_BINS)
	@echo "Built $(words $(PROBLEM_BINS)) standalone binaries"

# Debug: build all standalone debug binaries
dbg: $(PROBLEM_BINS_DBG)
	@echo "Built $(words $(PROBLEM_BINS_DBG)) standalone debug binaries"

# Build a single solution (use: make build-one P=hash/1.two-sum)
build-one: $(BIN_DIR)/$(P)

# Build a single solution in debug mode (use: make dbg-one P=hash/1.two-sum)
dbg-one: $(BIN_DIR_DBG)/$(P)

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(BIN_DIR_DBG)

help:
	@echo "C++ Harness. Use ./run for execution and submit."
	@echo "Targets:"
	@echo "  make / make build-all    # build all standalone binaries -> $(BIN_DIR)/<category>/<problem>"
	@echo "  make dbg                 # build all debug binaries     -> $(BIN_DIR_DBG)/<category>/<problem>"
	@echo "  make build-one P=hash/1.two-sum  # build one solution"
	@echo "  make dbg-one P=hash/1.two-sum    # build one debug solution"
	@echo "  make clean               # remove build artifacts"
	@echo "Run examples (repo root): ./run 1 | ./run -c tree | ./run -a"
