# Makefile for compiling the inflation and capital gains calculator program

# Compiler and linker
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Target executable
TARGET = outpu

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	del $(OBJS) $(TARGET).exe

# Phony targets
.PHONY: all clean
