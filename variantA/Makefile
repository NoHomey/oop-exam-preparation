.PHONY: clean run leackCheck

Compiler = g++ -std=c++14 -Wall -Wextra -Wpedantic -g

all: main.cc Timestamp.o TimestampWithDescription.o
	$(Compiler) $^

Timestamp.o: Timestamp.cc Timestamp.h
	$(Compiler) -c $<

TimestampWithDescription.o: TimestampWithDescription.cc TimestampWithDescription.h
	$(Compiler) -c $<

run:
	./a.out

leackCheck:
	valgrind ./a.out

clean:
	rm -f ./a.out *.o