#include "Body.h"
#include "Controller.h"
#include <stdlib.h>
#include "DisplayManager.h"

Body::Body(Location place, int sight, char rep, charAttr col) : location(place), sightRange(sight), symbol(rep), attr(col), control(NULL)
{
    location.getLocalArea().addBody(*this);
}

Body::~Body()
{
    //dtor
}

void Body::moveTo(int x, int y)
{
    BorderArea* border = NULL;
    Location destination(location.getLocalArea(), x, y);
    if (destination.getLocalArea().getTerrain(x,y) == NULL)
    {
        for (int i = location.getLocalArea().borders.size() - 1; i >= 0; i--)
        {
            if (location.getLocalArea().borders[i].contains(x, y) && location.getLocalArea().borders[i].getElevation() <= 25)
            {
                if (location.getLocalArea().borders[i].getLocation(x, y).getTerrain() == NULL)
                continue;
                destination = location.getLocalArea().borders[i].getLocation(x, y);
                border = &location.getLocalArea().borders[i];
                goto moving;
            }
        }
        return;
    }
    moving:
    if (destination.getTerrain()->isPassable())
    {
        location.getLocalArea().removeBody(this);
        location = destination;
        location.getLocalArea().addBody(*this);
        control->updatePos();
        if (border != NULL)
        control->updateArea(*border);
        return;
    }
}

void Body::move(int x, int y)
{
    moveTo(location.getX() + x, location.getY() + y);
    return;
}

CharRaster Body::getVision(int width, int height)
{
    CharRaster vision(width, height);
    //visionline(vision, Line(location, location.getX() - , location.getY() + i))

    for (int i = -getSightRange(); i <= getSightRange(); i++)
    {
        visionLine(vision, Line(location, location.getX() - getSightRange(), location.getY() + i));
        visionLine(vision, Line(location, location.getX() + getSightRange(), location.getY() + i));
        visionLine(vision, Line(location, location.getX() + i, location.getY() - getSightRange()));
        visionLine(vision, Line(location, location.getX() + i, location.getY() + getSightRange()));
    }
    vision.setCharAttr(getLocation().getX(), getLocation().getY(), getCharAttr(), getSymbol());
    return vision;
}

/*
CharRaster Body::getVision(int width, int height)
{
    CharRaster vision(width, height);

    //visionLine(vision, Line(location, location.getX() - getSightRange(), location.getY() - 4));
    visionLine(vision, Line(location, location.getX() - getSightRange(), location.getY()));

    vision.setCharAttr(getLocation().getX(), getLocation().getY(), getCharAttr(), getSymbol());
    return vision;
}
*/

void Body::visionLine(CharRaster& ch, Line line)
{
    for (int i = 0; i < line.size(); i++)
    {
        ch.setCharAttr(line.getX(i), line.getY(i), line.getTerrain(i)->getCharAttr(), line.getTerrain(i)->getDisplayChar());
        //cerr << i << line.getX(i) << line.getY(i) << line.getTerrain(i)->getDisplayChar();
        //getch();
        if (!line.getTerrain(i)->isTransparent())
        {
            return;
        }
    }
}
