CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
PICFLAGS = -fPIC
LDFLAGS = -Llib
LDLIBS = -lcalc -llogger

SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

STATIC_LIB = $(LIB_DIR)/libcalc.a
SHARED_LIB = $(LIB_DIR)/liblogger.so
EXEC = $(BIN_DIR)/main

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CALC_OBJ = $(OBJ_DIR)/calc.o
LOGGER_OBJ = $(OBJ_DIR)/logger.o
MAIN_OBJ = $(OBJ_DIR)/main.o

all: libs $(EXEC)

libs: static shared

static: $(STATIC_LIB)

shared: $(SHARED_LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/logger.o: $(SRC_DIR)/logger.c
	$(CC) $(CFLAGS) $(PICFLAGS) -c $< -o $@

$(STATIC_LIB): $(CALC_OBJ)
	ar rcs $(STATIC_LIB) $(CALC_OBJ)

$(SHARED_LIB): $(LOGGER_OBJ)
	$(CC) -shared -o $(SHARED_LIB) $(LOGGER_OBJ)

$(EXEC): $(MAIN_OBJ) $(STATIC_LIB) $(SHARED_LIB)
	$(CC) $(MAIN_OBJ) $(LDFLAGS) $(LDLIBS) -o $(EXEC)

run: all
	LD_LIBRARY_PATH=$(LIB_DIR) ./$(EXEC)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(LIB_DIR)/*.a
	rm -f $(LIB_DIR)/*.so
	rm -f $(BIN_DIR)/*
	rm -f app.log

rebuild: clean all