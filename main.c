// Yesssssssss Sum Tapes 2023
// Official license:
// Sum tapes
// David
// Law

#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void init();
void close_game();
void *read_input();

float money;
pthread_t input_thread;

int main()
{
	init();

	// Create separate thread for reading user input
	pthread_create(&input_thread, NULL, read_input, NULL);
	
	close_game();

	return 0;
}

void display()
{
	clear();
	
	printw("SPACE - HACK (+$0.01)\n\n");
	printw("MONEY: %.2f\n\n", money);
	printw("q - QUIT");
	
	refresh();
}

void init()
{
	money = 0.00;
	
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	
	display();
}

void close_game()
{
	pthread_join(input_thread, NULL);
	endwin();
	exit(0);
}

void *read_input()
{
	char key;

	while (1) {
		key = getch();
		switch (key) {
			case ' ':
				money += 0.01;
				display();
				break;
			case 'q':
				close_game();
		}
	}

	return NULL;
}
