# Makefile for two_pointers directory

SRC = $(wildcard *.cpp)
EXES = $(SRC:.cpp=)
CXX = g++
CXXFLAGS = -Wall -O2

all: $(EXES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXES) *.o
