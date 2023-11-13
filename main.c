// Yesssssssss Sum Tapes 2023
// Official license:
// Sum tapes
// David
// Law

#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>

void init();
void close_game();
void *read_input();

float money;
float money_per_hack;
float e_exp;
int per_hack_cost;
int mult_cost;
float E = 2.71828;
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
	
	printw("+--------------------------------------------+\n");
	printw("|                                            |\n");
	printw("|             MONEY: %.2f                    |\n", money);
	printw("|                                            |\n");
	printw("+--------------------------------------------+\n");
	printw("|============================================|\n");
	printw("+--------------------------------------------+\n");
	printw("|                                            |\n");
	printw("|   SPACEBAR - HACK (+$%.2f * e^(%.2f))      |\n", money_per_hack, e_exp);
	printw("|                                            |\n");
	printw("+--------------------------------------------+\n");
	printw("|              UPGRADES                      |\n");
	printw("+--------------------------------------------+\n");
	printw("|                                            |\n");
	printw("| b - Money Per Hack (-$%d)                   |\n", per_hack_cost);
	printw("| v - Hack Multiplier (-$%d)                  |\n", mult_cost);
	printw("|                                            |\n");
	printw("+--------------------------------------------+\n");
	printw("| q - QUIT |\n");
	printw("+----------+\n");
	
	refresh();
}

void init()
{
	money = 0.00;
	money_per_hack = 0.01;
	e_exp = 0.00;
	per_hack_cost = 2;
	mult_cost = 5;
	
	initscr();
	raw();
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
				money += (money_per_hack * pow(E, e_exp));
				display();
				break;
			case 'b':
				if (money > per_hack_cost) {
					money -= per_hack_cost;
					money_per_hack += 0.01;
					display();
				}
				break;
			case 'v':
				if (money > mult_cost) {
					money -= mult_cost;
					e_exp += 0.02;
					display();
				}
				break;
			case 'q':
				close_game();
		    	break;
		}
	}

	return NULL;
}









