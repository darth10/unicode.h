CC=gcc
CFLAGS=-Wno-write-strings -O3

all: unicode

unicode:
	$(CC) src/unicode.h $(CGLAGS)

clean:
	\rm -rf src/*.gch
