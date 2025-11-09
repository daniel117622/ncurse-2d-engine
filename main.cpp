#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

#include "initialization.h"
#include "text_utils.h"
#include "background.h"


wchar_t get_piece_char(int piece_idx, int col) 
{
    switch(piece_idx) 
    {
        case 0: // ████    ████████████
            return (col < 4 || (col >= 8 && col < 20)) ? L'X' : L' ';
        case 1: // ████    ████        
            return (col < 4 || (col >= 8 && col < 12)) ? L'X' : L' ';
        case 2: // ████████████████████
            return L'X';
        case 3: //         ████    ████
            return ((col >= 8 && col < 12) || (col >= 16 && col < 20)) ? L'X' : L' ';
        case 4: // ████████████    ████
            return (col < 12 || (col >= 16 && col < 20)) ? L'X' : L' ';
        default:
            return L' ';
    }
};

void render_piece_line(int piece_idx, wchar_t *buf) 
{
    for (int c = 0; c < 20; c++) {
        buf[c] = get_piece_char(piece_idx, c);
    }
    buf[20] = 0;
}



int main()
{

    initialize_ncurses(); 

    TextStyle *text_descriptor = (TextStyle *)malloc(sizeof(TextStyle));
    text_descriptor->x = 0;

    set_background(BLACK_BACKGROUND);

    int x_position = 20 ; int y_position = 10;
    text_descriptor->y = x_position;
    text_descriptor->x = 20;
    text_descriptor->color_pair = COLOR_TEXT_ERROR;

    wchar_t linebuf[21];
    char utf8buf[128];
    for (int line = 0; line <= 9; line++)
    {
        text_descriptor->y = y_position + line;
        int idx = (line / 2) % 5;
        render_piece_line(idx, linebuf);
        wcstombs(utf8buf, linebuf, sizeof(utf8buf));
        print_text_color(utf8buf, text_descriptor);
    }


    getch();
    endwin();
    
    return 0;
}