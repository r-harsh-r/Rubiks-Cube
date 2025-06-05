# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++17

# Source files
SRCS = main.cpp rubiksCube.cpp rubiksCube3d.cpp rubiksCubeArr.cpp rubiksCubeBitBoard.cpp
OBJS = $(SRCS:.cpp=.o)

# Header dependencies (rubiksCube.h is shared)
HEADERS = rubiksCube.h

# Executable name
TARGET = a.out

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp file into .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)
