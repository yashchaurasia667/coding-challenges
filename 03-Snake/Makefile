CC= g++
CFLAGS= -Wall -Wextra
LIBS= -lraylib -lGL
DEPENDENCIES= src/snake.cpp

default: main

main: src/main.cpp
	mkdir -p build
	$(CC) $(CFLAGS) -o build/snake $(DEPENDENCIES) src/main.cpp $(LIBS)

clean: build
	rm -rf build

run: build/snake
	build/snake