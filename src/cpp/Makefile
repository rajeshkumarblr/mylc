%:
	@:
run.%:
	@$(MAKE) run $(subst run.,,$@)
SHELL := /bin/bash

CXX ?= g++
CXXFLAGS ?= -std=gnu++20 -pipe -Wall -Wextra -Wno-unused-parameter -I. -DLC_LOCAL_TEST
CXXFLAGS += -g -O0 -fno-omit-frame-pointer -DDEBUG -rdynamic
LDFLAGS ?=


SHELL := /bin/bash
CXX ?= g++
CXXFLAGS ?= -std=gnu++20 -O2 -pipe -Wall -Wextra -Wno-unused-parameter -I. -DLC_LOCAL_TEST
LDFLAGS ?=

ROOT := $(abspath $(CURDIR)/../..)
SRC_DIR := $(CURDIR)
BIN_DIR := $(ROOT)/build/cpp
CENTRAL := $(BIN_DIR)/runner

CATEGORY_DIRS := hash list sliding_window misc two_pointer tree
PROBLEM_SRCS := $(filter-out $(SRC_DIR)/main.cpp, \
	$(wildcard $(SRC_DIR)/*.cpp) \
	$(foreach d,$(CATEGORY_DIRS),$(wildcard $(SRC_DIR)/$(d)/*.cpp)))
PROBLEM_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(PROBLEM_SRCS))


.PHONY: all build build-all clean submit help
.NOTPARALLEL:

build: $(CENTRAL)
all: build

$(BIN_DIR):
	mkdir -p $(BIN_DIR)
	@for d in $(CATEGORY_DIRS); do mkdir -p $(BIN_DIR)/$$d; done


$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/lc_test_utils.h | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pattern rule for category subdirectories (ensure target dir exists)
$(BIN_DIR)/%.o: $(SRC_DIR)/*/%.cpp $(SRC_DIR)/lc_test_utils.h | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(CENTRAL): $(BIN_DIR)/main.o $(PROBLEM_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

build-all: $(CENTRAL)
	@echo "Built $(CENTRAL)"

submit:
	@if [ -z "$(NUM)" ]; then echo "Usage: make submit NUM=<id>"; exit 2; fi; \
	src=""; \
	for f in $(PROBLEM_SRCS); do \
	  base=$$(basename $$f); id=$${base%%.*}; \
	  if [ "$$id" = "$(NUM)" ]; then src="$$f"; fi; \
	done; \
	if [ -z "$$src" ]; then echo "No source for problem $(NUM)"; exit 3; fi; \
	out="$(BIN_DIR)/submit.$(NUM).cpp"; \
	mkdir -p "$(BIN_DIR)"; \
	awk '/@lc code=start/{flag=1; print; next} /@lc code=end/{print; flag=0} flag' "$$src" > "$$out"; \
	echo "Wrote $$out (exact @lc code block)."

clean:
	rm -rf $(BIN_DIR)

help:
	@echo "Usage (build only; use ./run script to execute):"
	@echo "  make / make build       # build central runner"
	@echo "  make build-all          # same as build"
	@echo "  make submit NUM=1       # extract @lc code block -> build/cpp/submit.1.cpp"
	@echo "  ./run 1 | ./run -c tree | ./run -a  # execute via top-level script"
	mkdir -p "$(BIN_DIR)"; \
