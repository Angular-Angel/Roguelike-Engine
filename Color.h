#ifndef COLOR_H
#define COLOR_H

#include <ncurses.h>

enum charAttr {
    WHITEBLACK = COLOR_PAIR(1),
    REDBLACK = COLOR_PAIR(2),
    GREENBLACK = COLOR_PAIR(3)
};

void define_color();

#endif//COLOR_H
