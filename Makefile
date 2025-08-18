CC = gcc
CFLAGS = -I include/ -std=c99 -Wall -Wextra -pedantic

OS ?= linux
BUILD = build

ifeq ($(OS), linux)
	TARGET = $(BUILD)/dsa
endif

OBJ = $(BUILD)/main.o $(BUILD)/constants.o $(BUILD)/data_structures.o $(BUILD)/linked_list.o $(BUILD)/stack.o $(BUILD)/sorting_algorithms.o $(BUILD)/bubble_sort.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)
	$(MAKE) clean_objects

$(BUILD)/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o ${BUILD}/main.o

$(BUILD)/constants.o: src/constants.c
	$(CC) $(CFLAGS) -c src/constants.c -o ${BUILD}/constants.o

$(BUILD)/data_structures.o: src/data_structures/data_structures.c
	$(CC) $(CFLAGS) -c src/data_structures/data_structures.c -o ${BUILD}/data_structures.o

$(BUILD)/linked_list.o: src/data_structures/linked_list.c
	$(CC) $(CFLAGS) -c src/data_structures/linked_list.c -o ${BUILD}/linked_list.o

$(BUILD)/stack.o: src/data_structures/stack.c
	$(CC) $(CFLAGS) -c src/data_structures/stack.c -o ${BUILD}/stack.o

$(BUILD)/sorting_algorithms.o: src/sorting_algorithms/sorting_algorithms.c
	$(CC) $(CFLAGS) -c src/sorting_algorithms/sorting_algorithms.c -o ${BUILD}/sorting_algorithms.o

$(BUILD)/bubble_sort.o: src/sorting_algorithms/bubble_sort.c
	$(CC) $(CFLAGS) -c src/sorting_algorithms/bubble_sort.c -o ${BUILD}/bubble_sort.o

clean_objects:
	rm -f ${OBJ}

clean:
	rm -f $(OBJ) $(TARGET)