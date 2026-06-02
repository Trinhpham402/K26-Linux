CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

OBJ_DIR = obj
LIB_DIR = lib
APP_DIR = app
SRC_DIR = src

LIB_NAME = libmathutils.a
EXEC = main

all: $(EXEC)

$(OBJ_DIR)/mathutils.o: $(SRC_DIR)/mathutils.c include/mathutils.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/mathutils.c -o $(OBJ_DIR)/mathutils.o

$(LIB_DIR)/$(LIB_NAME): $(OBJ_DIR)/mathutils.o
	ar rcs $(LIB_DIR)/$(LIB_NAME) $(OBJ_DIR)/mathutils.o

$(OBJ_DIR)/main.o: $(APP_DIR)/main.c include/mathutils.h
	$(CC) $(CFLAGS) -c $(APP_DIR)/main.c -o $(OBJ_DIR)/main.o

$(EXEC): $(LIB_DIR)/$(LIB_NAME) $(OBJ_DIR)/main.o
	$(CC) $(OBJ_DIR)/main.o -L$(LIB_DIR) -lmathutils -o $(EXEC)

run: all
	./$(EXEC)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(LIB_DIR)/*.a
	rm -f $(EXEC)