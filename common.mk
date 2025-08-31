CXX = g++
CXXFLAGS = -Wall -g
SRC = $(wildcard *.cpp)
EXE = $(basename $(SRC))

all: $(EXE)

%: %.cpp ../../lc_test_utils.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXE)