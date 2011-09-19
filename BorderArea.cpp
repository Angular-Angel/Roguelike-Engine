#include "BorderArea.h"
#include "LocalArea.h"
#include "Location.h"

BorderArea::BorderArea(LocalArea& borderArea, int X, int Y, int elev, Rotation rot, bool mirrorx, bool mirrory):
area(&borderArea), x(X), y(Y), depth(elev), rotation(rot), xmirroring(mirrorx), ymirroring(mirrory)
{
    //ctor
}

BorderArea::~BorderArea()
{
    //dtor
}

bool BorderArea::contains(int x, int y)
{
    if (getRotation() == DEGREE_270 || getRotation() == DEGREE_90)
    {
        if (getX() <= x && static_cast<signed int>(getX() + getArea().getHeight() - 1) >= x && getY() <= y && static_cast<signed int>(getY() + getArea().getWidth() - 1) >= y)
        return true;
    }
    else
    {
        if (getX() <= x && static_cast<signed int>(getX() + getArea().getWidth() - 1) >= x && getY() <= y && static_cast<signed int>(getY() + getArea().getHeight() - 1) >= y)
        return true;
    }
    return false;
}

Location BorderArea::getLocation(int x, int y)
{
    int getx = 0, gety = 0;
    switch (getRotation())
    {
        case DEGREE_0:
        {
            if (isMirroredX())
            getx = getArea().getWidth() - 1 - (x - getX());
            else
            getx = x - getX();
            if (isMirroredY())
            gety = getArea().getHeight() - 1 - (y - getY());
            else
            gety = y - getY();
            return Location(getArea(), getx, gety);
        }
        case DEGREE_90:
        {
            if (isMirroredX())
            getx = getArea().getHeight() - 1 - (y - getY());
            else
            getx = y - getY();
            if (isMirroredY())
            gety = x - getX();
            else
            gety = getArea().getWidth() - 1 - (x - getX());
            return Location(getArea(), getx, gety);
        }
        case DEGREE_180:
        {
            if (isMirroredX())
            getx = x - getX();
            else
            getx = getArea().getWidth() - 1 - (x - getX());
            if (isMirroredY())
            gety = y - getY();
            else
            gety = getArea().getHeight() - 1 - (y - getY());
            return Location(getArea(), getx, gety);
        }
        case DEGREE_270:
        {
            if (isMirroredX())
            getx = y - getY();
            else
            getx = getArea().getHeight() - 1 - (y - getY());
            if (isMirroredY())
            gety = getArea().getWidth() - 1 - (x - getX());
            else
            gety = x - getX();
            return Location(getArea(), getx, gety);
        }
        return Location(getArea(), getx, gety);
    }
}
