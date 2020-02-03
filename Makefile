
CXXFLAGS = -g -Wall -Wfatal-errors -std=c++14

ALL = karatsuba

all: $(ALL)

karatsuba: cplusplus/final.cpp Makefile
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp

clean:
	$(RM) $(ALL) *.o
