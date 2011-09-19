#ifndef TERRAINTYPE_H
#define TERRAINTYPE_H

#include <iostream>
using namespace std;

class TerrainType
{
    public:
        /** char constructor */
        TerrainType(char display = '.', bool pass = true, bool see = true);
        /** Default destructor */
        virtual ~TerrainType();
        /** Access displayChar
         * \return The current value of displayChar
         */
        char getDisplayChar() const {return displayChar;}
        void setDisplayChar(char symbol) {displayChar = symbol;}
        bool isPassable() const {return passable;}
    protected:
    private:
        char displayChar; //!< Member variable "displayChar"
        bool passable;
        bool transparent;
};

#endif // TERRAINTYPE_H
