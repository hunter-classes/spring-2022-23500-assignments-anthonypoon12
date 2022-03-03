OBJECTS = main.o OList.o List.o Node.o 
TESTOBJECTS = tests.o OList.o Node.o 
CXXFLAGS = 
LDFLAGS=
CXX = g++

main: main.o OList.o List.o Node.o
	$(CXX) -o main $(OBJECTS)
tests: tests.o OList.o Node.o
	$(CXX) -o tests $(TESTOBJECTS)
main.o: main.cpp List.h OList.h
tests.o: tests.cpp OList.h
List.o: List.cpp List.h Node.h
OList.o: OList.cpp OList.h Node.h
Node.o: Node.cpp Node.h
clean:
	rm -f $(OBJECTS) *.o main tests