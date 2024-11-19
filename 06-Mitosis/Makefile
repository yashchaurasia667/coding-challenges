CC= gcc
CFLAGS= -Wall -Wextra
LIBS= -lraylib -lGL
DEPENDENCIES=

default: main

main: src/main.c
	mkdir -p build
	$(CC) $(CFLAGS) -o $@ $(DEPENDENCIES) $< $(LIBS)

clean: build
	rm -rf build

run: build/main
	build/main