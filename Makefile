# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17 -g -Iinclude

# Source and object files
SRC_DIR = src
OBJ_DIR = obj
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Output executable
TARGET = main

# Create obj directory if it doesn’t exist
$(shell mkdir -p $(OBJ_DIR))

# Default target
all: $(TARGET)

# Linking the final executable
$(TARGET): $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean compiled files
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)