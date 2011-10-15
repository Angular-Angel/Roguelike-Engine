#ifndef TERRAINTYPE_H
#define TERRAINTYPE_H

#include <iostream>
#include "Color.h"
using namespace std;

class TerrainType
{
    public:
        /** char constructor */
        TerrainType(char display = '.', charAttr chAt = WHITEBLACK, bool pass = true, bool see = true);
        /** Default destructor */
        virtual ~TerrainType();
        /** Access displayChar
         * \return The current value of displayChar
         */
        char getDisplayChar() const {return displayChar;}
        void setDisplayChar(char symbol) {displayChar = symbol;}
        charAttr getCharAttr() const {return attr;}
        void setCharAttr(charAttr symbol) {attr = symbol;}
        bool isPassable() const {return passable;}
        bool isTransparent() const {return transparent;}
    protected:
    private:
        char displayChar; //!< Member variable "displayChar"
        bool passable;
        bool transparent;
        charAttr attr;
};

#endif // TERRAINTYPE_H
