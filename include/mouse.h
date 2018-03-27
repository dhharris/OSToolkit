#ifndef _mouse_h_
#define _mouse_h_

#include "toolkit.h"

typedef struct {
	float x;
	float y;
} Mouse;

#define TITLEBAR_POS_X 405.0
#define TITLEBAR_POS_Y 32.0

void get_mouse_pos(Mouse *mouse);
void set_mouse_pos(Mouse *mouse, float x, float y);
void move_and_left_click(Mouse *mouse, float dx, float dy);
void move_and_right_click(Mouse *mouse, float dx, float dy);
void left_click();
void print_mouse_pos();
void print_mouse(Mouse *mouse);

#endif
