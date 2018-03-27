#include "toolkit.h"

int main()
{

        /* Seed random numbers */
        srand(time(NULL));
        srand48(arc4random());

        /* Main loop */
        while(1)
                switch(display_menu()) {
                        case 'A': case 'a': display_help();
                                            break;
                        case 'B': case 'b': drop_all_items();
                                            break;
                        case 'C': case 'c': autoclicker(1);
                                            break;
                        case 'D': case 'd': autoclicker(300);
                                            break;
                        case 'Q': case 'q': return 0;
                        default: ; // Do nothing
                }
}
