main: mode.o sorts.o
	g++ -o main mode.o sorts.o
mode.o: mode.cpp sorts.h
	g++ -c mode.cpp
sorts.o: sorts.cpp sorts.h
	g++ -c sorts.cpp
clean:
	rm -f *.o main
