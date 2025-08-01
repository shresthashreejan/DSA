CC = gcc
CFLAGS = -I include/ -std=c99 -Wall -Wextra -pedantic

OS ?= linux
BUILD = build

ifeq ($(OS), linux)
	TARGET = $(BUILD)/dsa
endif

OBJ = $(BUILD)/main.o $(BUILD)/constants.o $(BUILD)/bubble_sort.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)
	$(MAKE) clean_objects

$(BUILD)/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o ${BUILD}/main.o

$(BUILD)/constants.o: src/constants.c
	$(CC) $(CFLAGS) -c src/constants.c -o ${BUILD}/constants.o

$(BUILD)/bubble_sort.o: src/sorting/bubble_sort.c
	$(CC) $(CFLAGS) -c src/sorting/bubble_sort.c -o ${BUILD}/bubble_sort.o

clean_objects:
	rm -f ${OBJ}

clean:
	rm -f $(OBJ) $(TARGET)