#pragma once
typedef struct 
{
    int y;
    int x;
    int color_pair;
} TextStyle;

void print_text_color(const char *text, const TextStyle *style);