.PHONY: clean

Compiler = g++ -std=c++14 -Wall -Wextra -Wpedantic -g

all: test.cc String.o
	$(Compiler) test.cc String.o

String.o: DynamicArray.h DynamicArray.cc String.h String.cc
	$(Compiler) -c String.cc

clean:
	rm -f ./a.out *.o