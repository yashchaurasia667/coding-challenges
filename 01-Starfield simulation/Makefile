CC= gcc
CFLAGS= -Wall -Wextra
LIBS= -lraylib
DEPENDENCIES=

default: main

main: main.c
	mkdir -p build
	$(CC) $(CFLAGS) -o build/main $(DEPENDENCIES) main.c $(LIBS)

clean: build
	rm -rf build

run: build/main
	build/main