CC= gcc
CFLAGS= -Wall -Wextra
LIBS= -lraylib -lGL
DEPENDENCIES=

default: main

main: main.c
	mkdir -p build
	$(CC) $(CFLAGS) -o build/snake $(DEPENDENCIES) main.c $(LIBS)

clean: build
	rm -rf build

run: build/snake
	build/snake