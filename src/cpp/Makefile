SHELL := /bin/bash

CXX ?= g++
# Release vs Debug flags
CXXFLAGS_RELEASE ?= -std=gnu++20 -O2 -pipe -Wall -Wextra -Wno-unused-parameter -I. -DLC_LOCAL_TEST
CXXFLAGS_DEBUG   ?= -std=gnu++20 -O0 -g -fno-omit-frame-pointer -pipe -Wall -Wextra -Wno-unused-parameter -I. -DLC_LOCAL_TEST -DDEBUG -rdynamic
LDFLAGS ?=

ROOT := $(abspath $(CURDIR)/../..)
SRC_DIR := $(CURDIR)
BIN_DIR := $(ROOT)/build/cpp
CENTRAL := $(BIN_DIR)/runner
BIN_DIR_DBG := $(BIN_DIR)/dbg
CENTRAL_DBG := $(BIN_DIR)/runner.dbg

CATEGORY_DIRS := hash list sliding_window misc two_pointer tree stack
PROBLEM_SRCS := $(filter-out $(SRC_DIR)/main.cpp, \
	$(wildcard $(SRC_DIR)/*.cpp) \
	$(foreach d,$(CATEGORY_DIRS),$(wildcard $(SRC_DIR)/$(d)/*.cpp)))
PROBLEM_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(PROBLEM_SRCS))
PROBLEM_OBJS_DBG := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR_DBG)/%.o,$(PROBLEM_SRCS))


.PHONY: all build build-all dbg clean help
.NOTPARALLEL:

build: $(CENTRAL)
all: build

$(BIN_DIR):
	mkdir -p $(BIN_DIR)
	@for d in $(CATEGORY_DIRS); do mkdir -p $(BIN_DIR)/$$d; done

$(BIN_DIR_DBG):
	mkdir -p $(BIN_DIR_DBG)
	@for d in $(CATEGORY_DIRS); do mkdir -p $(BIN_DIR_DBG)/$$d; done


$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/lc_test_utils.h | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS_RELEASE) -c $< -o $@

# Pattern rule for category subdirectories (ensure target dir exists)
$(BIN_DIR)/%.o: $(SRC_DIR)/*/%.cpp $(SRC_DIR)/lc_test_utils.h | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS_RELEASE) -c $< -o $@

# Debug object pattern rules
$(BIN_DIR_DBG)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/lc_test_utils.h | $(BIN_DIR_DBG)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS_DEBUG) -c $< -o $@

$(BIN_DIR_DBG)/%.o: $(SRC_DIR)/*/%.cpp $(SRC_DIR)/lc_test_utils.h | $(BIN_DIR_DBG)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS_DEBUG) -c $< -o $@

$(CENTRAL): $(BIN_DIR)/main.o $(PROBLEM_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS_RELEASE) -o $@ $^ $(LDFLAGS)

build-all: $(CENTRAL)
	@echo "Built $(CENTRAL)"

# Debug binary
dbg: $(CENTRAL_DBG)
	@echo "Built $(CENTRAL_DBG)"

$(CENTRAL_DBG): $(BIN_DIR_DBG)/main.o $(PROBLEM_OBJS_DBG) | $(BIN_DIR_DBG)
	$(CXX) $(CXXFLAGS_DEBUG) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(BIN_DIR_DBG)

help:
	@echo "C++ Harness (build-only). Use ./run for execution and submit."
	@echo "Targets:"
	@echo "  make / make build       # build optimized runner -> $(CENTRAL)"
	@echo "  make dbg                # build debug runner    -> $(CENTRAL_DBG)"
	@echo "  make clean              # remove build artifacts"
	@echo "Run examples (repo root): ./run 1 | ./run -c tree | ./run -a"
	@echo "Submit (repo root): ./run --submit 9 -l cpp  # writes build/cpp/submit.9.cpp"
