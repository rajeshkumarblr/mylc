# Makefile for sliding_window directory

SRC = $(wildcard *.cpp)
EXES = $(SRC:.cpp=)
CXX = g++
CXXFLAGS = -Wall -Wno-sign-compare -g

all: $(EXES)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXES) *.o
