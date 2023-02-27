OBJECTS=List.o main.o Node.o

debug: CXXFLAGS += -g

main: $(OBJECTS)
	$(CXX) -o main $(OBJECTS)

debug: $(OBJECTS)
	$(CXX) -o debug $(OBJECTS)

List.o: List.cpp Node.h List.h

main.o: main.cpp List.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS)

