main: main.o Tree.o Node.o
	g++ -o main main.o Tree.o Node.o
tests: tests.o Tree.o Node.o
	g++ -o tests tests.o Tree.o Node.o
main.o: main.cpp Tree.h
tests.o: tests.cpp Tree.h doctest.h
Tree.o: Tree.cpp Tree.h Node.h
Node.o: Node.cpp Node.h
clean:
	rm -rf *.o main tests