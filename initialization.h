#pragma once
#include <ncurses.h>

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

void initialize_ncurses();