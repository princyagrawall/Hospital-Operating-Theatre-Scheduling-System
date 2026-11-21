
CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Iinclude -g

TARGET = hospital_scheduler

SRC = src/main.c \
      src/domain.c \
      src/validation.c \
      src/io.c \
      src/scheduling.c \
      src/backtracking_scheduler.c \
      src/benchmark.c \
      algorithms/branch_bound/least_cost_branch_bound.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

test-scheduling:
	$(CC) $(CFLAGS) tests/test_scheduling.c \
	src/domain.c src/scheduling.c src/validation.c \
	-o test_scheduling
	./test_scheduling

test-edge-cases:
	$(CC) $(CFLAGS) tests/test_scheduling_edge_cases.c \
	src/domain.c src/backtracking_scheduler.c \
	-o test_edge_cases
	./test_edge_cases

test-algorithms:
	$(CC) $(CFLAGS) tests/test_algorithms.c \
	src/domain.c src/scheduling.c src/validation.c \
	-o test_algorithms
	./test_algorithms

test-all: test-scheduling test-algorithms test-edge-cases

clean:
	rm -f $(TARGET) test_edge_cases test_scheduling test_algorithms *.o
	rm -rf $(TARGET).dSYM test_edge_cases.dSYM test_scheduling.dSYM test_algorithms.dSYM

.PHONY: all run clean test-scheduling test-edge-cases test-algorithms test-all
