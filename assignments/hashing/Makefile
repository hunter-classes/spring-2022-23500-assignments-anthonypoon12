main: main.o Dictionary.o List.o Node.o Person.o
	g++ -o main main.o Dictionary.o List.o Node.o Person.o
tests: tests.o Dictionary.o List.o Node.o Person.o
	g++ -o tests tests.o Dictionary.o List.o Node.o Person.o
main.o: main.cpp Dictionary.h List.h Node.h Person.h
tests.o: tests.cpp doctest.h Dictionary.h List.h Node.h Person.h
Dictionary.o: Dictionary.cpp Dictionary.h List.h Node.h Person.h
List.o: List.cpp List.h Node.h Person.h
Node.o: Node.cpp Node.h Person.h
Person.o: Person.cpp Person.h
clean:
	rm -rf *.o main tests