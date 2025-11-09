#include "text_utils.h"
#include <ncurses.h>
#include <cwchar>
#include <cstdlib>

void print_text_color(const char *text, const TextStyle *style)
{
    if (!text || !style)
        return;

    size_t wlen = mbstowcs(NULL, text, 0);
    if (wlen == (size_t)-1)
        return;

    wchar_t *wtext = (wchar_t*)malloc((wlen + 1) * sizeof(wchar_t));
    if (!wtext)
        return;

    mbstowcs(wtext, text, wlen + 1);

    attron(COLOR_PAIR(style->color_pair));
    mvaddwstr(style->y, style->x, wtext);
    attroff(COLOR_PAIR(style->color_pair));
    refresh();

    free(wtext);
}