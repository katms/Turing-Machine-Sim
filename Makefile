CXX := g++
CXXFLAGS += -std=c++11 -Wall

OBJECT_FILE = $(CXX) $^ $(CXXFLAGS) -c -o $@
OBJECTS := main.o Stack.o Turing_Machine.o
EXE := tmsim

build: $(OBJECTS)
	$(CXX) $^ -o $(EXE)

main.o: main.cpp
	$(OBJECT_FILE)

Stack.o: Stack.cpp
	$(OBJECT_FILE)

Turing_Machine.o: Turing_Machine.cpp
	$(OBJECT_FILE)
