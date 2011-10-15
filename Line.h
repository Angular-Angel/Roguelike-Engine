#ifndef LINE_H
#define LINE_H

#include <vector>
#include "Location.h"

class Line
{
    public:
    /** Default constructor */
        Line(Location, int, int);
        /** Default destructor */
        virtual ~Line();
        int getX(int);
        int getY(int);
        int size() {return line.size();}
        TerrainType* getTerrain(int index) {line[index].getTerrain();}
        char getChar(int i) {if (line[i].getTerrain() == NULL) return ' '; return line[i].getTerrain()->getDisplayChar();}
        void addLocation(Location loc) {line.push_back(loc);}
    protected:
    private:
        /** Default constructor */
        Line(int, int, int, int);
        vector<Location> line;
        int x1, y1, x2, y2;
};

#endif // LINE_H
