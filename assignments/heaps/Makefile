main: main.o heap.o
	g++ -o main main.o heap.o
tests: tests.o heap.o
	g++ -o tests tests.o heap.o
main.o: main.cpp heap.h
tests.o: tests.cpp doctest.h heap.h
heap.o: heap.cpp heap.h
clean:
	rm -rf *.o main tests