CC=gcc
CFLAGS=-Wno-write-strings -O3

all: unicode

unicode:
	$(CC) src/unicode.h $(CFLAGS)

clean:
	\rm -rf src/*.gch
