#ifndef CHARRASTER_H
#define CHARRASTER_H

#include <vector>
#include "Rotation.h"
#include <ncurses.h>

using namespace std;
class CharRaster
{
    public:
        /** Default constructor */
        CharRaster(unsigned int x = 1, unsigned int y = 1, char ch = ' ');
        /** Default destructor */
        virtual ~CharRaster();
        char getChar(unsigned int x, unsigned int y) {return charImage[y][x];}
        void setChar(unsigned int x, unsigned int y, char ch) {charImage[y][x] = ch;}
        void rotate(Rotation r);
        void flipHorizontal();
        void flipVertical();
        void insertCharRaster(CharRaster, int x, int y);
        int getWidth(int y = 0) {return charImage[y].size();}
        int getHeight() {return charImage.size();}
        void print(int x = 0, int y = 0, WINDOW* win = stdscr);
        void resize(unsigned int x, unsigned int y);
    protected:
    private:
        vector<vector<char> > charImage; //!< Member variable "charImage"
};

#endif // CHARRASTER_H
