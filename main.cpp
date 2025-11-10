#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

#include "initialization.h"
#include "text_utils.h"
#include "background.h"

void write_h_line(int y_pos)
{
    TextStyle *t_des = (TextStyle *)malloc(sizeof(TextStyle));
    t_des->x = 0;
    t_des->y = y_pos;
    t_des->color_pair = COLOR_TEXT_NORMAL; 


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

    write_h_line(3);

    getch();
    endwin();
    
    return 0;
}
