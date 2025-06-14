cc = gcc
CFLAGS = -I include/ -std=99 -Wall -Wextra -pedantic

OS ?= linux
BUILD = build

ifeq ($(OS), linux)
	LDFLAGS = -lraylib -lGl -lm -lpthread
	TARGET = $(BUILD)/dsa
endif

ifeq ($(OS), windows)
	LDFLAGS = -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
	TARGET = $(BUILD)/dsa.exe
endif

OBJ = ${BUILD}/main.o

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)
	$(MAKE) clean_objects

${BUILD}/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o ${BUILD}/main.o

clean_objects:
	rm -f $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)