#include "toolkit.h"
#include "mouse.h"

/*
 * Move to a relative location then click.
 * Parameters are change in x and change in y.
 */

void move_and_left_click(Mouse *mouse, float dx, float dy)
{
        /* Create events */
        CGEventRef move = CGEventCreateMouseEvent(
                        NULL, kCGEventMouseMoved,
                        CGPointMake(mouse->x += dx, mouse->y += dy),
                        kCGMouseButtonLeft // ignored
                        );
        CGEventRef left_click_down = CGEventCreateMouseEvent(
                        NULL, kCGEventLeftMouseDown,
                        CGPointMake(mouse->x, mouse->y),
                        kCGMouseButtonLeft
                        );
        // Left button up at 250x250
        CGEventRef left_click_up = CGEventCreateMouseEvent(
                        NULL, kCGEventLeftMouseUp,
                        CGPointMake(mouse->x, mouse->y),
                        kCGMouseButtonLeft
                        );

        /* Execute events */
        CGEventPost(kCGHIDEventTap, move);
        usleep(100000);
        CGEventPost(kCGHIDEventTap, left_click_down);
        CGEventPost(kCGHIDEventTap, left_click_up);

        /* Release events */
        CFRelease(move);
        CFRelease(left_click_down);
        CFRelease(left_click_up);
}

void left_click()
{
        Mouse *mouse = malloc(sizeof(Mouse));
        get_mouse_pos(mouse);
        move_and_left_click(mouse, 0.0, 0.0);

}

void move_and_right_click(Mouse *mouse, float dx, float dy)
{
        /* Create events */
        CGEventRef move = CGEventCreateMouseEvent(
                        NULL, kCGEventMouseMoved,
                        CGPointMake(mouse->x += dx, mouse->y += dy),
                        kCGMouseButtonRight // ignored
                        );
        CGEventRef right_click_down = CGEventCreateMouseEvent(
                        NULL, kCGEventRightMouseDown,
                        CGPointMake(mouse->x, mouse->y),
                        kCGMouseButtonRight
                        );
        CGEventRef right_click_up = CGEventCreateMouseEvent(
                        NULL, kCGEventRightMouseUp,
                        CGPointMake(mouse->x, mouse->y),
                        kCGMouseButtonRight
                        );

        /* Execute events */
        CGEventPost(kCGHIDEventTap, move);

        CGEventPost(kCGHIDEventTap, right_click_down);
        CGEventPost(kCGHIDEventTap, right_click_up);
        usleep(100000);

        /* Release events */
        CFRelease(move);
        CFRelease(right_click_down);
        CFRelease(right_click_up);
}

/**
 * Gets mouse position and assigns the result to mouse struct
 */
void get_mouse_pos(Mouse *mouse)
{

        CGEventRef temp = CGEventCreate(NULL);
        CGPoint point = CGEventGetLocation ( temp );
        mouse->x = point.x, mouse->y = point.y;


}

/**
 * Sets mouse location using the given x,y parameters
 */
void set_mouse_pos(Mouse *mouse, float x, float y)
{
        mouse->x = x;
        mouse->y = y;

}
/**
 * Gets mouse position and prints it to standard output
 */
void print_mouse_pos()
{
        CGEventRef temp = CGEventCreate(NULL);
        CGPoint point = CGEventGetLocation ( temp );
        printf("(%f, %f)\n", point.x, point.y);
}

void print_mouse(Mouse *mouse) {
        printf("(%f, %f)\n", mouse->x, mouse->y);
}

