CXX = g++
CXXFLAGS = -std=c++20 -Wall -c
LXXFLAGS = -std=c++20
OBJECTS = BFS.o another_way_BFS.o apmidproject.o DFS.o Node.o main.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS)
BFS.o: BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp -o BFS.o
another_way_BFS.o: another_way_BFS.cpp another_way_BFS.h BFS.h BFS.cpp Node.cpp Node.h
	$(CXX) $(CXXFLAGS) another_way_BFS.cpp -o another_way_BFS.o
apmidproject.o: apmidproject.cpp apmidproject.h
	$(CXX) $(CXXFLAGS) apmidproject.cpp -o apmidproject.o
DFS.o: DFS.cpp DFS.h
	$(CXX) $(CXXFLAGS) DFS.cpp -o DFS.o
Node.o: Node.cpp Node.h
	$(CXX) $(CXXFLAGS) Node.cpp -o Node.o
main.o: main.cpp BFS.cpp BFS.h another_way_BFS.cpp another_way_BFS.h apmidproject.cpp apmidproject.h DFS.cpp DFS.h Node.cpp Node.h
	$(CXX) $(CXXFLAGS) main.cpp -o main.o
clean:
	rm -f $(TARGET) $(OBJECTS)