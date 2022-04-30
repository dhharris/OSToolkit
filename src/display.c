#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "toolkit.h"

#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#define BUFFERSIZE 10

int display_menu()
{
	int choice;
	int i;
	char *in = malloc(BUFFERSIZE * sizeof(char));
	system("clear");

	/* Print the menu */
	printf("Welcome to the Runescape Toolkit!\n\nq. Quit\na. Help\nb. Drop all "
	       "items\nc. Autoclicker\nd. Slow autoclicker\n\nPlease select one of "
	       "the options: ");

	while (fgets(in, BUFFERSIZE, stdin) && !strstr(in, "\n"))
		/* keep reading in char until new line is reached */;

	for (i = 0; in[i] == ' '; ++i)
		; /* Skips any spaces the user may have typed before the char */
	choice = in[i];

	free(in);
	clrscr();
	return choice;
}

void display_help()
{
	printf("If the program is not working properly, make sure you are using the "
	       "official\nOSRS client and that the top left edge of the game window "
	       "is in the top left\ncorner of your screen.\n");
	wait_for_input();
}

void wait_for_input()
{
	printf("Press the RETURN key to continue...");
	getchar(); // wait for anything
}
