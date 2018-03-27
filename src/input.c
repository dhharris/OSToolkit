#include "toolkit.h"

int input() {
	char ch;
	scanf("%c", &ch);

	switch(ch) {
		case 'd': printf("D key pressed\n");
			break;
		case 'D': printf("D key pressed\n");
			break;
	}
	return 1;
}