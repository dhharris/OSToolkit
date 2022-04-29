#include <signal.h>
#include <stdlib.h>
#include <time.h>

#include "toolkit.h"

void do_main_loop() {
        switch(display_menu()) {
                case 'A': case 'a': display_help();
                                    break;
                case 'B': case 'b': drop_all_items();
                                    break;
                case 'C': case 'c': autoclicker(1);
                                    break;
                case 'D': case 'd': autoclicker(300);
                                    break;
                case 'Q': case 'q': PROGRAM_STATE = STATE_EXIT;
                default: ; // Do nothing
        }
}

void handle_sigint(int sig) {
        // SIGINT brings us back to the main menu
        (void)sig; // unused
        PROGRAM_STATE = STATE_MAIN;
}

int main() {
        /* Seed random numbers */
        srand(time(NULL));
        srand48(arc4random());

        /* Register signal handler */
        signal(SIGINT, &handle_sigint);

        PROGRAM_STATE = STATE_MAIN;

        /* Main loop */
        while (PROGRAM_STATE != STATE_EXIT) {
                do_main_loop();
        }
}
