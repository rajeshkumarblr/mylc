# Makefile for compiling independent sample C and C++ programs
# Each .cpp or .c file in this directory will be compiled into its own executable in the same directory.

CC ?= gcc
CFLAGS ?= -O2 -Wall -Wextra -I.. -I../third_party -DLC_LOCAL_TEST

CXX ?= g++
CXXFLAGS ?= -std=gnu++20 -O2 -Wall -Wextra -Wno-unused-parameter -I.. -I../third_party -DLC_LOCAL_TEST

# Find all C and C++ source files in the current directory
C_SRCS   := $(wildcard *.c)
CPP_SRCS := $(wildcard *.cpp)

# Map each source file to an executable in the same directory
C_BINS   := $(patsubst %.c,%,$(C_SRCS))
CPP_BINS := $(patsubst %.cpp,%,$(CPP_SRCS))
BINS     := $(C_BINS) $(CPP_BINS)

.PHONY: all clean help

# Default target builds all C and C++ binaries
all: $(BINS)

# Rule for building C executables
$(C_BINS): %: %.c
	@echo "Compiling C $< -> $@"
	$(CC) $(CFLAGS) $< -o $@

# Rule for building C++ executables
$(CPP_BINS): %: %.cpp
	@echo "Compiling C++ $< -> $@"
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean up build artifacts
clean:
	@echo "Cleaning up binaries..."
	@if [ -n "$(BINS)" ]; then rm -f $(BINS); fi

# Help target to explain usage
help:
	@echo "Independent C/C++ Samples Makefile"
	@echo "Targets:"
	@echo "  make         # Compile all .c and .cpp files into independent binaries"
	@echo "  make clean   # Remove all compiled binaries"
	@echo "  make help    # Show this message"


