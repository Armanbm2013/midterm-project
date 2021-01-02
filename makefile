CXX = g++
CXXFLAGS = -std=c++20 -Wall -c
LXXFLAGS = -std=c++20
OBJECTS = ./obj/BFS.o ./obj/apmidproject.o ./obj/DFS.o ./obj/Node.o ./obj/main.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS)
./obj/BFS.o: BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp -o ./obj/BFS.o
./obj/apmidproject.o: apmidproject.cpp apmidproject.h
	$(CXX) $(CXXFLAGS) apmidproject.cpp -o ./obj/apmidproject.o
./obj/DFS.o: DFS.cpp DFS.h
	$(CXX) $(CXXFLAGS) DFS.cpp -o ./obj/DFS.o
./obj/Node.o: Node.cpp Node.h
	$(CXX) $(CXXFLAGS) Node.cpp -o ./obj/Node.o
./obj/main.o: main.cpp BFS.cpp BFS.h apmidproject.cpp apmidproject.h DFS.cpp DFS.h Node.cpp Node.h
	$(CXX) $(CXXFLAGS) main.cpp -o ./obj/main.o
clean:
	rm -f $(TARGET) $(OBJECTS)