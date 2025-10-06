# === Makefile for Bubble Sort Project ===

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = bubble_sort
SRC = bubble_sort.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
