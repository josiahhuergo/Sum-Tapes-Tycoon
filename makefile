CC=gcc
LIBS=-lncurses -ltinfo -lm


sum-tycoon: main.c
	$(CC) -o sum-tycoon main.c $(LIBS)
