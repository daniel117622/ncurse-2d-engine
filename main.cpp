#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

#include "initialization.h"
#include "text_utils.h"
#include "background.h"

void write_h_line(int y_pos, int COLOR_PAIR)
{
    TextStyle *t_des = (TextStyle *)malloc(sizeof(TextStyle));
    t_des->x = 0;
    t_des->y = y_pos;
    t_des->color_pair = COLOR_PAIR; 


    for (int x = 0 ; x <= 32 ; x++ ) 
    {
	t_des->x = x;
        print_text_color("#", t_des);
    }
}

int main()
{

    initialize_ncurses(); 

    TextStyle *text_descriptor = (TextStyle *)malloc(sizeof(TextStyle));
    text_descriptor->x = 0;

    set_background(BLACK_BACKGROUND);
    
    for (int y = 5; y <= 15; y++)
    {
	int color = COLOR_TEXT_NORMAL;
        write_h_line(y, COLOR_TEXT_NORMAL - 5 + y);
    }
    getch();
    endwin();
    
    return 0;
}
