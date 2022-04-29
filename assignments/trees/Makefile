main: main.o tree.o
g++ -o main.o tree.o
tests: tests.o tree.o
	g++ -o tests tests.o tree.o
main.o: main.cpp Tree.h
tests.o: tests.cpp Tree.h doctests.h
tree.o: Tree.cpp Tree.h
clean:
	rm -rf *.o main tests