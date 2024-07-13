SRC_DIR = src
BUILD_DIR = build
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
INCLUDE_PATHS = -Iinclude/ -Iinclude/SDL2
LIBRARY_PATHS = -Llib/SDL2
COMPILER_FLAGS = -Wall -g -std=c++17
LINKER_FLAGS = -lSDL2
CC = g++ 

compile: $(SRC_FILES)
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) src/glad.c -o $(BUILD_DIR)/main

clean:
	rm -rf $(BUILD_DIR)/*
