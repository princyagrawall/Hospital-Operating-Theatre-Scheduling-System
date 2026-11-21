
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
	rm -f $(TARGET) test_edge_cases *.o
	rm -rf $(TARGET).dSYM

.PHONY: all run clean

test-edge-cases:
	$(CC) $(CFLAGS) tests/test_scheduling_edge_cases.c \
	src/domain.c src/backtracking_scheduler.c \
	-o test_edge_cases
	./test_edge_cases