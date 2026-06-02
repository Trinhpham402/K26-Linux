CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
PICFLAGS = -fPIC
SHARED_FLAGS = -shared

BUILD_DIR = build
BIN_DIR = bin
SRC_DIR = src

LIB_NAME = libstringutils.so
EXEC = main

all: $(BIN_DIR)/$(LIB_NAME) $(BIN_DIR)/$(EXEC)

$(BUILD_DIR)/stringutils.o: $(SRC_DIR)/stringutils.c include/stringutils.h
	$(CC) $(CFLAGS) $(PICFLAGS) -c $(SRC_DIR)/stringutils.c -o $(BUILD_DIR)/stringutils.o

$(BIN_DIR)/$(LIB_NAME): $(BUILD_DIR)/stringutils.o
	$(CC) $(SHARED_FLAGS) -o $(BIN_DIR)/$(LIB_NAME) $(BUILD_DIR)/stringutils.o

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c include/stringutils.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/main.o

$(BIN_DIR)/$(EXEC): $(BUILD_DIR)/main.o $(BIN_DIR)/$(LIB_NAME)
	$(CC) $(BUILD_DIR)/main.o -L$(BIN_DIR) -lstringutils -o $(BIN_DIR)/$(EXEC)

run: all
	LD_LIBRARY_PATH=$(BIN_DIR) ./$(BIN_DIR)/$(EXEC) "helloLinux"

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BIN_DIR)/*