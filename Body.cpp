#include "Body.h"
#include "Controller.h"
#include <stdlib.h>
#include "Line.h"
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
    vector<Location> line;
    for (int i = -getSightRange(); i <= getSightRange(); i++)
    {
        visionLine(vision, lineTo(location, location.getX() - getSightRange(), location.getY() + i));
        visionLine(vision, lineTo(location, location.getX() + getSightRange(), location.getY() + i));
        visionLine(vision, lineTo(location, location.getX() + i, location.getY() - getSightRange()));
        visionLine(vision, lineTo(location, location.getX() + i, location.getY() + getSightRange()));
    }
    return vision;
}

void Body::visionLine(CharRaster& ch, vector<Location> line)
{
    for (int i = 0; i < line.size(); i++)
    {
        ch.setCharAttr(line[i].getX(), line[i].getY(), line[i].getTerrain()->getCharAttr(), line[i].getTerrain()->getDisplayChar());
        DisplayManager::getDisplayManager().printTerrain(ch);
        getch();
    }
}
