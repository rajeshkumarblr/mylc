# common.mk  (included from src/cpp/<category>/Makefile via ../../common.mk)
# Layout:
#   REPO_ROOT/
#     build/
#     src/
#       common/cpp/lc_test_utils.h
#       cpp/<category>/*.cpp

TOP_DIR   := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
REPO_ROOT := $(abspath $(TOP_DIR)/../..)
BUILD_DIR := $(REPO_ROOT)/build

CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wshadow -Wconversion -g \
            -I$(REPO_ROOT)/src/common/cpp -I$(REPO_ROOT)

# Sources in the current problem/category dir
SRC       := $(wildcard *.cpp)

# Executable names: strip dir + .cpp
NAMES     := $(notdir $(basename $(SRC)))

# Binaries go under REPO_ROOT/build/<name>
BINS      := $(addprefix $(BUILD_DIR)/,$(NAMES))

.PHONY: all clean link-latest

all: $(BUILD_DIR) $(BINS) link-latest

$(BUILD_DIR):
	@mkdir -p $@

# Build rule: compile each current-dir source into REPO_ROOT/build/<name>
$(BUILD_DIR)/%: %.cpp $(REPO_ROOT)/src/common/cpp/lc_test_utils.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# Optional convenience: symlink the most-recent target to REPO_ROOT/solution
link-latest: $(BINS)
	@if [ -n "$(lastword $(BINS))" ]; then \
	  ln -sf $(lastword $(BINS)) $(REPO_ROOT)/solution; \
	fi

clean:
	@rm -f $(BINS)

$(info SRC=$(SRC))
