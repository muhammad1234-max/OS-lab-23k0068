CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -I$(INC_DIR)
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TARGET = textcounter

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

$(BIN_DIR)/$(TARGET): $(OBJ_FILES) main.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) main.o $(TARGET)
