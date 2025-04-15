CXX = g++
CXXFLAGS = -std=c++17 -O2

SRC_DIR = src
BIN_DIR = bin

SRC_FILES = $(SRC_DIR)/main.cpp \
            $(SRC_DIR)/RiskCalculator.cpp \
            $(SRC_DIR)/MonteCarloSimulator.cpp \
            $(SRC_DIR)/Utils.cpp \
            $(SRC_DIR)/Portfolio.cpp \
            $(SRC_DIR)/DataLoader.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)

TARGET = $(BIN_DIR)/var_calculator.exe

$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir  $(BIN_DIR)

clean:
	del /Q $(SRC_DIR)\\*.o 

.PHONY: clean