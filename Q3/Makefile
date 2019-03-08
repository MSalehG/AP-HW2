CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o func.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
func.o: func.cpp func.h
	$(CXX) $(CXXFLAGS) func.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)

