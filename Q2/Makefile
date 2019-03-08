CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o Arr.o Vec.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
Arr.o: Arr.cpp Arr.h
	$(CXX) $(CXXFLAGS) Arr.cpp
Vec.o: Vec.cpp Vec.h
	$(CXX) $(CXXFLAGS) Vec.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)

