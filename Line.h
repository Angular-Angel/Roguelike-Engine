#ifndef LINE_H
#define LINE_H

#include <vector>
#include "Location.h"

class Line
{
    public:
        Line(Location, int, int);
        virtual ~Line();
        int getX(int);
        int getY(int);
        int size() {return line.size();}
        const TerrainType* getTerrain(int index) {return line[index].getTerrain();}
        char getChar(int i) {if (line[i].getTerrain() == NULL) return ' '; return line[i].getTerrain()->getDisplayChar();}
        void addLocation(Location loc) {line.push_back(loc);}
        void cutOff(int);
    protected:
    private:
        Line(int, int, int, int);
        vector<Location> line;
        int x1, y1, x2, y2;
        int dx, dy, ax, ay, sx, sy;
};

#endif // LINE_H
