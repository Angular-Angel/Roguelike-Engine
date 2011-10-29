#include "Location.h"

Location::Location(LocalArea& area, int X, int Y) :localArea(&area), x(X), y(Y)
{

}

Location::~Location()
{
    //dtor
}

/*
This function is supposed to correct for the transition between LocalAreas.
*/



bool Location::correct()
{
    if (getTerrain() == NULL)
    {
        for (int i = 0; i < getLocalArea().borders.size(); i++)
        {
            if (getLocalArea().borders[i].getLocation(x, y).getTerrain() != NULL)
            {
                *this = getLocalArea().borders[i].getLocation(x, y);
                return true;
            }
        }
        return false;
    }
    return true;
}
