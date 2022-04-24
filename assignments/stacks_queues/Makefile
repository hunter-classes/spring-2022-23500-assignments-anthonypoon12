main: main.o stack.o Node.o List.o
	g++ -o main main.o stack.o Node.o List.o
tests: tests.o stack.o Node.o List.o
	g++ -o tests tests.o stack.o Node.o List.o
main.o: main.cpp stack.h
tests.o: tests.cpp stack.h doctest.h
stack.o: stack.cpp stack.h List.h
List.o: List.cpp List.h Node.h
Node.o: Node.cpp Node.h
clean:
	rm -f *.o main tests