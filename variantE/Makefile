.PHONY: clean run leakCheck

Compiler = g++ -std=c++14 -Wall -Wextra -Wpedantic -g

define Object
$(1).o: $(1).cc $(1).h $(2)
	$(Compiler) -c $$<
endef

all: main.cc Timestamp.o Appointment.o
	$(Compiler) $^

$(eval $(call Object,Timestamp))

$(eval $(call Object,Appointment,Timestamp.o))

clean:
	rm -f *.o ./a.out

run: all
	./a.out

leakCheck: all
	valgrind ./a.out