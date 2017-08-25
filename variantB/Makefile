.PHONY: clean run leakCheck

Compiler = g++ -std=c++14 -Wall -Wextra -Wpedantic -g

define Object
$(1).o: $(1).cc $(1).h $(2)
	$(Compiler) -c $$<
endef

all: main.cc String.o Publication.o Book.o Magazine.o
	$(Compiler) $^

$(eval $(call Object,String))

$(eval $(call Object,Publication,String.o))

$(eval $(call Object,Book,Publication.o))

$(eval $(call Object,Magazine,Publication.o))

run: all
	./a.out

clean:
	rm -f *.o ./a.out

leakCheck: all
	valgrind ./a.out