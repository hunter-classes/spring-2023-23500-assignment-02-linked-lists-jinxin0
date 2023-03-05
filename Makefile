OBJECTS=List.o Node.o OList.o

main: $(OBJECTS) main.o
	$(CXX) -o main main.o $(OBJECTS)

tests: $(OBJECTS) tests.o
	$(CXX) -o tests tests.o $(OBJECTS)

debug: CXXFLAGS += -g
debug: $(OBJECTS) main.o
	$(CXX) -o debug main.o $(OBJECTS)

List.o: List.cpp Node.h List.h

OList.o: OList.cpp OList.h Node.h

main.o: main.cpp List.h Node.h

tests.o: tests.cpp OList.h

Node.o: Node.cpp Node.h

clean:
	rm -f main.o tests.o debug.o $(OBJECTS)

