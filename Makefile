
CXXFLAGS = -std=c++11 -lstdc++

ALL = karatsuba

all: $(ALL)

final.o : cplusplus/final.cpp
	g++ -c $(CXXFLAGS) cplusplus/final.cpp

karatsuba: final.o
	g++ $(CXXFLAGS) -o $@ final.o

clean:
	$(RM) $(ALL) *.o
