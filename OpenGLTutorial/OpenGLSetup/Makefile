CC= gcc
CFLAGS= -Wall -Wextra
LIBS= -L ./dependencies/lib -lglfw3 -lopengl32 -lgdi32
DEPENDENCIES= -I ./dependencies/include

default: main

main: main.c
	mkdir -p build
	$(CC) $(CFLAGS) -o build/main $(DEPENDENCIES) main.c $(LIBS)

clean: build
	rm -rf build

run: build/main.exe
	build/main.exe