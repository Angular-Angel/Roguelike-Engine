#include "LocalArea.h"
#include "Location.h"

void LocalArea::addBorderArea(BorderArea border)
{
    for (int i = 0; i < borders.size(); i++)
    {
        if (borders[i].getElevation() > border.getElevation())
        {
            borders.insert(borders.begin() + i, border);
            return;
        }
    }
    borders.push_back(border);
    return;
}
