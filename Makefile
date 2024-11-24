
CC=gcc
CFLAGS=-lncurses

OBJ_DIR=objs

SRC=main.c board.c game.c
OBJ=$(SRC:%.c=$(OBJ_DIR)/%.o)

TARGET=main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)


