#include "Line.h"
#include <stdlib.h>

#define SGN(a) (((a)<0) ? -1 : 1)

vector<Location> lineTo(Location loc, int x2, int y2)
{
    vector<Location> ret;
    int x1 = loc.getX();
    int y1 = loc.getY();
    int dx = x2 - x1;
    int dy = y2 - y1;
    int ax = abs(dx) << 1;
    int ay = abs(dy) << 1;
    int sx = SGN(dx);
    int sy = SGN(dy);
    int t = ay - (ax >> 1);
    if (dy == 0) sy = 0;
    if (dx == 0) sx = 0;
    Location cur(loc);
    int xmin = (x1 < x2 ? x1 : x2), ymin = (y1 < y2 ? y1 : y2),
                                           xmax = (x1 > x2 ? x1 : x2), ymax = (y1 > y2 ? y1 : y2);
    xmin -= abs(dx);
    ymin -= abs(dy);
    xmax += abs(dx);
    ymax += abs(dy);
    if (ax == ay)
    {
        do
        {
            cur.move(sx, sy);
            cur.correct();
            ret.push_back(cur);
        }
        while ((cur.getX() != x2 || cur.getY() != y2) &&
                (cur.getX() >= xmin && cur.getX() <= xmax && cur.getY() >= ymin && cur.getY() <= ymax));
    }
    else if (ax > ay)
    {
        do
        {
            if (t > 0)
            {
                cur.move(0, sy);
                t -= ax;
            }
            cur.move(sx, 0);
            t += ay;
            cur.correct();
            ret.push_back(cur);
        }
        while ((cur.getX() != x2 || cur.getY() != y2) &&
                (cur.getX() >= xmin && cur.getX() <= xmax && cur.getY() >= ymin && cur.getY() <= ymax));
    }
    else
    {
        do
        {
            if (t > 0)
            {
                cur.move(sx, 0);
                t -= ay;
            }
            cur.move(0, sy);
            t += ax;
            cur.correct();
            ret.push_back(cur);
        }
        while ((cur.getX() != x2 || cur.getY() != y2) &&
                (cur.getX() >= xmin && cur.getX() <= xmax && cur.getY() >= ymin && cur.getY() <= ymax));
    }
    return ret;
}
