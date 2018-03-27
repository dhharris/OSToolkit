#ifndef _toolkit_h_
#define _toolkit_h_


#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mouse.h"

#define BUFFERSIZE 10
#define AUTOCLICK_TIMER_MAX 12000 /* Stops loop after 12000 clicks = 6000 alchs */
#define SECONDS_TO_MICROSECONDS 1000000
#define ARC4RANDOM_MAX      0x100000000
#define RAND_OFFSET 10


/* Function prototypes */
// input.c
int input();

//scripts.c
void drop_all_items();
void autoclicker(int t);

//display.c
int display_menu();
void display_help();



#endif

