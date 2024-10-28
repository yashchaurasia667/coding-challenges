CC= g++
CFLAGS= -Wall -Wextra -I ./dependencies/include
LIBS= -L ./dependencies/lib -lglfw3 -lopengl32 -lgdi32 
OJB = build/main.o build/glad.o
GLAD_SRC= src/glad.c
TARGET = build/main.exe

default: $(TARGET)

$(TARGET): $(OJB)
	mkdir -p build
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

build/main.o: src/main.cpp
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

build/glad.o: $(GLAD_SRC)
	mkdir -p build
	gcc $(CFLAGS) -c $< -o $@

clean: build
	rm -rf build

run: $(TARGET)
	$(TARGET)