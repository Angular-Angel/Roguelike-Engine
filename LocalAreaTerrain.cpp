#include "LocalArea.h"
#include "Body.h"

/*
This next function is an unholy moster. Basically, what it does, is it goes through the LocalArea and gets the specified peice of terrain.
however, if that piece of terrain is outside the LocalArea and the function is told to look for it, it will check the neighboring LocalAreas.
The part where this becomes a pain is where we take into account that those can be rotated and flipped.
This means a giant block of code to account for every possible combination. Which means massive nested switch statements. Which are ugly.

Also take note, most if not all of the magic number 1's are to account for width and height measuring the number of items,
while the coordinates have a zero and are thus offset by 1.
*/
const TerrainType* LocalArea::getTerrain(int x, int y)
{
    if (outsideArea(x,y))
    return NULL;
    else
    return (terrain[y][x]);
}

void LocalArea::fillTerrain(const TerrainType& type)
{
    unsigned int i, j;
    for (i = 0; i < terrain.size(); i++)
    {
        for (j = 0; j < terrain[i].size(); j++)
        {
            terrain[i][j] = &type;
        }
    }
}

CharRaster LocalArea::getCharMap()
{
    CharRaster output = CharRaster(getWidth(), getHeight());
    for (unsigned int i = 0; i < getHeight(); i++)
    {
        for (unsigned int j = 0; j < getWidth(); j++)
        {
            if (getTerrain(j, i) != NULL)
            output.setChar(j, i, getTerrain(j, i)->getDisplayChar());
        }
    }
    for (unsigned int i; i < occupants.size(); i++)
    output.setChar(occupants[i]->getLocation().getX(), occupants[i]->getLocation().getY(), occupants[i]->getSymbol());
    return output;
}
