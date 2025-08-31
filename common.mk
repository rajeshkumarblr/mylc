TOP_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
CXX = g++
CXXFLAGS = -Wall -g -I$(TOP_DIR)
SRC = $(wildcard *.cpp)
EXE = $(basename $(SRC))

all: $(EXE)

%: %.cpp $(TOP_DIR)/lc_test_utils.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXE)