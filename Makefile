
CXXFLAGS = -std=c++14 -lstdc++

ALL = karatsuba

all: $(ALL)

final.o : cplusplus/final.cpp
        gcc -c $(CXXFLAGS) cplusplus/final.cpp

karatsuba: final.o
        gcc $(CXXFLAGS) -o $@ final.o

clean:
        $(RM) $(ALL) *.o
