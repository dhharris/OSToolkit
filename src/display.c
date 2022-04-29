#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "toolkit.h"

int display_menu() {

	int choice;
	int i;
	char *in = malloc(BUFFERSIZE * sizeof(char));
	system("clear");

	/* Print the menu */
	printf("Welcome to the Runescape Toolkit!\n\nq. Quit\na. Help\nb. Drop all items\nc. Autoclicker\nd. Slow autoclicker\n\nPlease select one of the options: ");

	while(fgets(in, BUFFERSIZE, stdin) && !strstr(in, "\n"))
		/* keep reading in char until new line is reached */;

	for (i = 0; in[i] == ' '; ++i); /* Skips any spaces the user may have typed before the char */
	choice = in[i];

	system("clear");

	return choice;
}

void display_help() {

	printf("If the program is not working properly, make sure you are using the official\nOSRS client and that the top left edge of the game window is in the top left\ncorner of your screen.\n");
	printf("Press the RETURN key to continue...");

	char *in = malloc(BUFFERSIZE * sizeof(char));
	while(fgets(in, BUFFERSIZE, stdin) && !strstr(in, "\n")); // infinite loop until a key is pressed

}

// void find_rs_window() {
// 	CGRect rect;
// 	char *name;
// 	CFDictionaryRef window_description = (CFDictionaryRef)CFArrayGetValueAtIndex ((CFArrayRef)window_description, 0);
// 	CFArrayRef window_list = CGWindowListCreateDescriptionFromArray(CGWindowListCopyWindowInfo(kCGWindowListExcludeDesktopElements , kCGNullWindowID));
// 	int i;
// 	for (i = 0; window_description != NULL; ++i) {
// 		window_description = (CFDictionaryRef)CFArrayGetValueAtIndex ((CFArrayRef)window_description, 1); // Get description at ith window
// 		CFDictionaryRef name_ref = (CFDictionaryRef)CFDictionaryGetValue (window_description, kCGWindowName);
// 		CFDictionaryRef bounds = (CFDictionaryRef)CFDictionaryGetValue (window_description, kCGWindowBounds);
// 		if (strcmp(name, "Old School Runescape") == 0)
// 			break;
// 	}
// 	CFRelease(window_list);
// }
