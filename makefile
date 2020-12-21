CXX = g++
CXXFLAGS = -std=c++20 -Wall -c
LXXFLAGS = -std=c++20
OBJECTS = BFS.o main.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS)
BFS.o: BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) BFS.cpp -o BFS.o
main.o: main.cpp BFS.cpp BFS.h
	$(CXX) $(CXXFLAGS) main.cpp -o main.o
clean:
	rm -f $(TARGET) $(OBJECTS)