main: main.o stack.o Node.o List.o Queue.o
	g++ -o main main.o stack.o Node.o List.o Queue.o
tests: tests.o stack.o Node.o List.o Queue.o
	g++ -o tests tests.o stack.o Node.o List.o Queue.o
main.o: main.cpp stack.h Queue.h
tests.o: tests.cpp stack.h doctest.h Queue.h
stack.o: stack.cpp stack.h List.h
List.o: List.cpp List.h Node.h
Queue.o: Queue.cpp Queue.h Node.h
Node.o: Node.cpp Node.h
clean:
	rm -f *.o main tests