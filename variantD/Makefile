.PHONY: clean run leakCheck

Compiler = g++ -std=c++14 -Wall -Wextra -Wpedantic -g

define Object
$(1).o: $(1).cc $(1).h $(2)	
	$(Compiler) -c $$<
endef

all: main.cc String.o WritingInstrument.o Marker.o Pencil.o
	$(Compiler) $^

$(eval $(call Object,String))

$(eval $(call Object,WritingInstrument,String.o))

$(eval $(call Object,Marker,WritingInstrument.o))

$(eval $(call Object,Pencil,WritingInstrument.o))

run:
	./a.out < all.txt

clean:
	rm -f *.o ./a.out

leakCheck:
	valgrind ./a.out < all.txt