TOP_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
# common.mk is included from cpp/, but always located at repo root
REPO_ROOT := $(abspath $(TOP_DIR))

CXX = g++
CXXFLAGS = -Wall -g -I$(REPO_ROOT)
SRC = $(wildcard *.cpp)
EXE = $(basename $(SRC))

all: $(EXE) link-latest

%: %.cpp $(REPO_ROOT)/lc_test_utils.h
	$(CXX) $(CXXFLAGS) $< -o $@

link-latest: $(EXE)
	@echo "Linking $(REPO_ROOT)/solution -> $(abspath $(firstword $(EXE)))"
	@ln -sf $(abspath $(firstword $(EXE))) $(REPO_ROOT)/solution

clean:
	rm -f $(EXE)
