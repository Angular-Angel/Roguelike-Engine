#include "CurrentArea.h"

CurrentArea::CurrentArea(LocalArea& local, int X, int Y, Rotation r, bool mirrorx, bool mirrory)
: area(&local), x(X), y(Y), rot(r), mirroredX(mirrorx), mirroredY(mirrory)
{
}

CurrentArea::CurrentArea(Location& loc, Rotation r, bool mirrorx, bool mirrory)
: area(&(loc.getLocalArea())), x(loc.getX()), y(loc.getY()), rot(r), mirroredX(mirrorx), mirroredY(mirrory)
{
}

void CurrentArea::rotate(Rotation r)
{
    int ir = static_cast<int>(rot) + static_cast<int>(r);
    while(ir > 3)
    ir -= 4;
    while(ir < 0)
    ir += 4;
    rot = static_cast<Rotation>(ir);
}

int CurrentArea::getDrawX()
{
    switch (getRotation())
    {
        case DEGREE_0:
        {
            if (isMirroredX())
            return getArea().getWidth() - 1 - getX();
            else
            return getX();
        }
        case DEGREE_90:
        {
            if (isMirroredX())
            return getY();
            else
            return getArea().getHeight() - 1 - getY();
        }
        case DEGREE_180:
        {
            if (isMirroredX())
            return getX();
            else
            return getArea().getWidth() - 1 - getX();
        }
        case DEGREE_270:
        {

        }
    }
}

int CurrentArea::getDrawY()
{
    switch (getRotation())
    {
        case DEGREE_0:
        {
            if (isMirroredY())
            return getArea().getHeight() - 1 - getY();
            else
            return getY();
        }
        case DEGREE_90:
        {
            if (isMirroredY())
            return getArea().getWidth() - 1 - getX();
            else
            return getX();
        }
        case DEGREE_180:
        {
            if (isMirroredY())
            return getY();
            else
            return getArea().getHeight() - 1 - getY();
        }
        case DEGREE_270:
        {

        }
    }
}

/*

CurrentArea::print() creates a CharRaster and inserts the localArea the player is in
and all of the localareas bordering it into the  CharRaster and prints that to terrain.
*/

void CurrentArea::print()
{
    CharRaster scrn = CharRaster(21, 21);
    CharRaster areaRaster = area->getCharMap();
    CharRaster border;
    bool areaPrinted = false;
    for (unsigned int i = 0; i < area->borders.size(); i++)
    {
        if (area->borders[i].getElevation() > 25)
        break;
        if (!areaPrinted && area->borders[i].getElevation() <= 0 && area->borders[i+1].getElevation() > 0)
        {
            scrn.insertCharRaster(areaRaster, scrn.getWidth()/2 - getX(), scrn.getHeight()/2 - getY());
            areaPrinted = true;
        }
        border = area->borders[i].getArea().getCharMap();
        border.rotate(area->borders[i].getRotation());
        if (area->borders[i].isMirroredY())
        border.flipVertical();
        if (area->borders[i].isMirroredX())
        border.flipHorizontal();
        scrn.insertCharRaster(border, (scrn.getWidth()/2 - getX()) + area->borders[i].getX(), (scrn.getHeight()/2 - getY()) + area->borders[i].getY());
    }
    if (!areaPrinted)
    scrn.insertCharRaster(areaRaster, scrn.getWidth()/2 - getX(), scrn.getHeight()/2 - getY());
    scrn.rotate(getRotation());
    if (isMirroredX())
    scrn.flipHorizontal();
    if (isMirroredY())
    scrn.flipVertical();
    DisplayManager::getDisplayManager().printTerrain(scrn);
}

CurrentArea::~CurrentArea()
{
    //dtor
}
