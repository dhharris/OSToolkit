#include "toolkit.h"

// TODO: Shift click drop instead of right click
void drop_all_items() {

        Mouse *mouse = malloc(sizeof(Mouse));

        set_mouse_pos(mouse, TITLEBAR_POS_X, TITLEBAR_POS_Y); //set to the titlebar pos
        move_and_left_click(mouse,0,0); // Get window focus

        /* First column */
        // Drop first item
        move_and_right_click(mouse,202.0,241.0);

        float x_offset = 40, y_offset = -242.5, i, j;
        for (i = 0; i < 4; ++i) {
                move_and_left_click(mouse,0.0,28.0);

                // Drop until last item
                for (j = 0; j < 10; ++j) {

                        move_and_right_click(mouse,0,-15);
                        move_and_left_click(mouse,0,35);
                        usleep(100000);
                }
                // drop last item
                move_and_right_click(mouse,0,0);
                move_and_left_click(mouse,0,19);
                usleep(100000);
                if (i != 3)
                        move_and_right_click(mouse, x_offset, y_offset);

        }
        free(mouse);
}

void autoclicker(int t) {

        int counter = 0;
        Mouse *mouse = malloc(sizeof(Mouse));

        printf("Press CTRL+C to stop\n");

        /* Loop runs for a finite number of times unless using slow autoclicker */
        while(counter < AUTOCLICK_TIMER_MAX || t > 1) {

                double my_rand = ((double)arc4random() / ARC4RANDOM_MAX);

                get_mouse_pos(mouse);
                move_and_left_click(mouse, 0.0, 0.0);

                // Sleep for a fraction of t seconds
                double interval = my_rand * t;
                printf("Clicking again in %lf seconds\n", interval);
                usleep(interval * SECONDS_TO_MICROSECONDS);
                if (((int)(my_rand * 10) % 2) && t == 1)
                        usleep(my_rand * SECONDS_TO_MICROSECONDS); /* If the first digit of my_rand is odd, and using normal autoclicker, sleep again (lets user end program if needed) */
                if ((!(counter % 9)) && t == 1)
                        sleep((int)my_rand * RAND_OFFSET); // Sleep for random amount of seconds between 0 and RAND_OFFSET every 9 clicks (normal autoclicker only)

                ++counter;
        }
        free(mouse);
}
