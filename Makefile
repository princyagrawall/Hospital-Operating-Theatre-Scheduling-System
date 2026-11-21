
CC = gcc

CFLAGS = -std=c17 -Wall -Wextra -Iinclude -g

TARGET = hospital_scheduler

SRC = src/main.c \
      src/domain.c \
      src/validation.c \
      src/io.c \
      src/scheduling.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o
	rm -rf $(TARGET).dSYM

.PHONY: all run clean
