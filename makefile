CC=gcc
LIBS=-lncurses -ltinfo


sum-tycoon: main.c
	$(CC) -o sum-tycoon main.c $(LIBS)
