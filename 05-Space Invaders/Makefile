CC= g++
CFLAGS= -Wall -Wextra
LIBS= -lraylib -lGL
DEPENDENCIES= src/sprite.cpp src/bullet.cpp

default: build/main

build/main: src/main.cpp src/sprite.cpp src/bullet.cpp
	mkdir -p build
	$(CC) $(CFLAGS) -o $@ $(DEPENDENCIES) $< $(LIBS)

clean: build
	rm -rf build

run: build/main
	build/main