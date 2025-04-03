# Compiler and flags ---> being honest this is help from stack overflow and chegg
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Directories
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests

# Source files
SRC_FILES = $(SRC_DIR)/main.cpp $(SRC_DIR)/matrix.cpp
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable name
EXEC = matrix_program

# Targets

# Default target (build the executable)
all: $(BUILD_DIR)/$(EXEC)

# Link the object files to create the final executable
$(BUILD_DIR)/$(EXEC): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(BUILD_DIR)/$(EXEC)

# Compile each source file into an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/$(EXEC)

# Run the program (this assumes the executable is in the build folder)
run: $(BUILD_DIR)/$(EXEC)
	./$(BUILD_DIR)/$(EXEC)

# Test (optional, assumes you have a separate test setup)
test:
	@echo "Running tests..."
	# Assuming your tests are in a separate folder and you are using gtest
	cd $(TEST_DIR) && ./run_tests.sh

# Install dependencies or additional tasks (if any)
install:
	@echo "Install tasks go here..."
	# Example: make install packages

# Phony targets (not actual files)
.PHONY: all clean run test install
