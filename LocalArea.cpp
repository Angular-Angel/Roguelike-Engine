#include "LocalArea.h"
#include "Body.h"

LocalArea::LocalArea(const TerrainType& type, int width, int height)
{
    terrain = vector<vector<const TerrainType*> >();
    borders = vector<BorderArea>();
    occupants = vector<Body*>();
    int i, j;
    for (i = 0; i < height; i++)
    {
        terrain.push_back(vector<const TerrainType*> ());
    }
    unsigned int k;
    for (k = 0; k < terrain.size(); k++)
    {
        for (j = 0; j < width; j++)
        {
            terrain[k].push_back(&type);
        }
    }
}

void LocalArea::addBody(Body& bod)
{
    occupants.push_back(&bod);
}

void LocalArea::removeBody(Body* bod)
{
    for (unsigned int i = 0; i < occupants.size(); i++)
    {
        if (occupants[i] == bod)
        occupants.erase(occupants.begin() + i);
    }
}

LocalArea::~LocalArea()
{
    //dtor
}
