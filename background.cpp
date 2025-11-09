#include "background.h"

// Should be called before printing anything
void set_background(const int pair_id)
{
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    attron(COLOR_PAIR(pair_id));

    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < cols; ++x)
        {
            mvaddch(y, x, ' ');
        }
    }

    attroff(COLOR_PAIR(pair_id));
    refresh();
}
