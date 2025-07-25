CC = gcc
CFLAGS = -I include/ -std=c99 -Wall -Wextra -pedantic

OS ?= linux
BUILD = build

ifeq ($(OS), linux)
	TARGET = $(BUILD)/dsa
endif

OBJ = $(BUILD)/main.o $(BUILD)/constants.o $(BUILD)/bubble_sort.o $(BUILD)/insertion_sort.o $(BUILD)/selection_sort.o $(BUILD)/merge_sort.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)
	$(MAKE) clean_objects

$(BUILD)/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o ${BUILD}/main.o

$(BUILD)/constants.o: src/constants.c
	$(CC) $(CFLAGS) -c src/constants.c -o ${BUILD}/constants.o

$(BUILD)/bubble_sort.o: src/bubble_sort.c
	$(CC) $(CFLAGS) -c src/bubble_sort.c -o ${BUILD}/bubble_sort.o

$(BUILD)/insertion_sort.o: src/insertion_sort.c
	$(CC) $(CFLAGS) -c src/insertion_sort.c -o ${BUILD}/insertion_sort.o

$(BUILD)/selection_sort.o: src/selection_sort.c
	$(CC) $(CFLAGS) -c src/selection_sort.c -o ${BUILD}/selection_sort.o

$(BUILD)/merge_sort.o: src/merge_sort.c
	$(CC) $(CFLAGS) -c src/merge_sort.c -o ${BUILD}/merge_sort.o

clean_objects:
	rm -f ${OBJ}

clean:
	rm -f $(OBJ) $(TARGET)