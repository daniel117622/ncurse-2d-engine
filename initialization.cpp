#include <ncurses.h>
#include "initialization.h"

#define WHITE_BACKGROUND    10
#define BLACK_BACKGROUND    11
#define RED_BACKGROUND      12
#define GREEN_BACKGROUND    13
#define YELLOW_BACKGROUND   14
#define BLUE_BACKGROUND     15
#define MAGENTA_BACKGROUND  16
#define CYAN_BACKGROUND     17

#define COLOR_TEXT_NORMAL      20   // White on black (default terminal look)
#define COLOR_TEXT_DIM         21   // Black on white
#define COLOR_TEXT_WARNING     22   // Yellow on black
#define COLOR_TEXT_ERROR       23   // Red on black
#define COLOR_TEXT_SUCCESS     24   // Green on black
#define COLOR_TEXT_INFO        25   // Cyan on black
#define COLOR_TEXT_HIGHLIGHT   26   // Blue on white
#define COLOR_TEXT_TITLE       27   // Magenta on black

void initialize_ncurses() 
{
    initscr();
    start_color();

    init_pair(WHITE_BACKGROUND,   COLOR_WHITE,   COLOR_WHITE);
    init_pair(BLACK_BACKGROUND,   COLOR_BLACK,   COLOR_BLACK);
    init_pair(RED_BACKGROUND,     COLOR_WHITE,   COLOR_RED);
    init_pair(GREEN_BACKGROUND,   COLOR_BLACK,   COLOR_GREEN);
    init_pair(YELLOW_BACKGROUND,  COLOR_BLACK,   COLOR_YELLOW);
    init_pair(BLUE_BACKGROUND,    COLOR_WHITE,   COLOR_BLUE);
    init_pair(MAGENTA_BACKGROUND, COLOR_WHITE,   COLOR_MAGENTA);
    init_pair(CYAN_BACKGROUND,    COLOR_BLACK,   COLOR_CYAN);

    init_pair(COLOR_TEXT_NORMAL,    COLOR_WHITE,   COLOR_BLACK);
    init_pair(COLOR_TEXT_DIM,       COLOR_BLACK,   COLOR_BLACK);
    init_pair(COLOR_TEXT_WARNING,   COLOR_YELLOW,  COLOR_BLACK);
    init_pair(COLOR_TEXT_ERROR,     COLOR_RED,     COLOR_BLACK);
    init_pair(COLOR_TEXT_SUCCESS,   COLOR_GREEN,   COLOR_BLACK);
    init_pair(COLOR_TEXT_INFO,      COLOR_CYAN,    COLOR_BLACK);
    init_pair(COLOR_TEXT_HIGHLIGHT, COLOR_BLUE,    COLOR_BLACK);
    init_pair(COLOR_TEXT_TITLE,     COLOR_MAGENTA, COLOR_BLACK);

    noecho();
    curs_set(0);
    
}
