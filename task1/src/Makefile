gcc_options = -std=c++11 -Wall --pedantic-errors
COMPILE=g++ $(gcc_options)

program : main.cpp Date.o Item.o
	$(COMPILE) -o $@ $^

Date.o: Date.cpp
	$(COMPILE) -c $<

Item.o: Item.cpp
	$(COMPILE) -c $<
Data.o: Data.cpp
	$(COMPILE) -c $<

# .PHONY targets
run : program
	./program

clean :
	rm -f ./program && rm -f ./*.o

.PHONY : run clean

