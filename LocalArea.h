#ifndef LOCALAREA_H
#define LOCALAREA_H

#include "TerrainType.h"
#include <vector>
#include <iostream>
#include <ncurses.h>
#include <stdexcept>
#include "Rotation.h"
#include "CharRaster.h"
#include "BorderArea.h"

class Body;
/*
This class represents a small chunk of terrain. These LocalAreas remember what they've got inside them and what other LocalAreas border them.
*/

enum Direction
{
    NO_DIRECTION = -1,
    DIRECTION_NORTH = 0,
    DIRECTION_EAST,
    DIRECTION_SOUTH,
    DIRECTION_WEST
};

class Location;

class LocalArea
{

private:
    vector<vector<const TerrainType*> > terrain; //!< Member variable "terrain"
    vector<Body*> occupants;
public:
    /** Default constructor */
    LocalArea(const TerrainType& = TerrainType(' '), int width = 1, int height = 1);
    /** Default destructor */
    virtual ~LocalArea();
    /** Fill terrain with char */
    void fillTerrain(const TerrainType &type);
    /** Access single tile of terrain */
    const TerrainType* getTerrain(int x, int y);
    /** Set single tile of terrain */
    void setTerrain(const TerrainType& type, int x, int y)
    {
        terrain[y][x] = &type;
    }
    void nullTerrain(int x, int y) {terrain[y][x] = NULL;}
    /** Add BorderArea to borders */
    void addBorderArea(BorderArea);
    /** Access width
    * \return The current value of width
    */
    unsigned int getWidth(unsigned int y = 0)
    {
        return terrain[y].size();
    }
    /** Access height
    * \return The current value of width
    */
    unsigned int getHeight()
    {
        return terrain.size();
    }
    BorderArea& getBorder(int x, int y, bool checkborders = true);
    CharRaster getCharMap();
    bool outsideArea(int x, int y)
    {
        return (x < 0 || x >= getWidth() || y < 0 || y >= getHeight());
    }
    Location getBorderingLocation(int x, int y);
    void addBody(Body& ent);
    void removeBody(Body* ent);
    vector<BorderArea> borders;
protected:
private:
    /*
        void printDegree_0(WINDOW* output, bool mirroredx = false, bool mirroredy = false);
        void printDegree_90(WINDOW* output, bool mirroredx = false, bool mirroredy = false);
        void printDegree_180(WINDOW* output, bool mirroredx = false, bool mirroredy = false);
        void printDegree_270(WINDOW* output, bool mirroredx = false, bool mirroredy = false);
    */
};

#endif // LOCALAREA_H
