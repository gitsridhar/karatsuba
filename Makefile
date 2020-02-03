
CXXFLAGS = -g -Wall -Wfatal-errors -std=c++14

ALL = hello

all: $(ALL)

karatsuba: cplusplus/final.cpp Makefile
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp

clean:
	$(RM) $(ALL) *.o