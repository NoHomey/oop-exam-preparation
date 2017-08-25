.PHONY: clean run leakCheck

Compiler = g++ -std=c++14 -Wall -Wextra -Wpedantic -g

define Object
$(1).o: $(1).cc $(1).h $(2)
	$(Compiler) -c $$<
endef

all: main.cc Company.o PrivateCompany.o StateCompany.o Consortium.o
	$(Compiler) $^

$(eval $(call Object,Company))

$(eval $(call Object,PrivateCompany,Company.o))

$(eval $(call Object,StateCompany,Company.o))

$(eval $(call Object,Consortium,Company.o))

clean:
	rm -f *.o ./a.out

run: all
	./a.out

leakCheck: all
	valgrind ./a.out