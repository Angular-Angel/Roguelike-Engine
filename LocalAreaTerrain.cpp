#include "LocalArea.h"
#include "Body.h"

/*
The magic number 1's are to account for width and height measuring the number of items,
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
    CharRaster output = CharRaster(getWidth(), getHeight(), ' ', WHITEBLACK);
    for (unsigned int i = 0; i < getHeight(); i++)
    {
        for (unsigned int j = 0; j < getWidth(); j++)
        {
            if (getTerrain(j, i) != NULL)
            {
                output.setCharAttr(j, i, getTerrain(j, i)->getCharAttr(), getTerrain(j, i)->getDisplayChar());
            }

        }
    }
    for (unsigned int i; i < occupants.size(); i++)
    output.setCharAttr(occupants[i]->getLocation().getX(), occupants[i]->getLocation().getY(), occupants[i]->getCharAttr(), occupants[i]->getSymbol());
    return output;
}
