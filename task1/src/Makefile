gcc_options = -std=c++11 -Wall --pedantic-errors
CMD=g++ $(gcc_options)
deps=Date.o Item.o Data.o

program : main.cpp $(deps)
	$(CMD) -o $@ $^

Date.o: Date.cpp
	$(CMD) -c $<

Item.o: Item.cpp
	$(CMD) -c $<
Data.o: Data.cpp
	$(CMD) -c $<

test: ./test/test.cpp $(deps)
	$(CMD) -o $@ $^ && ./test

run : program
	./program

# .PHONY targets
clean :
	rm -f ./program && rm -f ./*.o

.PHONY : clean

