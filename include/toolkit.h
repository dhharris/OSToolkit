#pragma once

enum state {
  STATE_MENU,
  STATE_SCRIPT,
  STATE_EXIT,
};

enum state PROGRAM_STATE;

// input.c
int input();

//scripts.c
void drop_all_items();
void autoclicker(int t);

//display.c
int display_menu();
void display_help();
void wait_for_input();


