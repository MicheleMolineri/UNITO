# Compiler and flags
CC = gcc
all: bin/main_ex1 bin/test_ex1

CFLAGS = -g -Wall -Wextra -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/main_ex1: build/sorting.o build/generic_sort_main.o $(COMMON_DEPS)
	$(CC) -o bin/main_ex1 build/generic_sort.o build/generic_sort_main.o

bin/test_ex1: build/generic_sort_test.o build/generic_sort.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/test_ex1  build/generic_sort_test.o build/generic_sort.o build/unity.o

clean:
	rm -f build/* bin/*