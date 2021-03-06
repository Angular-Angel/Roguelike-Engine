#include "Line.h"
#include <stdlib.h>

#define SGN(a) (((a)<0) ? -1 : 1)

Line::Line(Location loc, int X2, int Y2) : x1(loc.getX()), y1(loc.getY()), x2(X2), y2(Y2)
{
    //cerr << x1 << ',' << y1 << ',' << x2 << ',' << x2 << '#';
    line = vector<Location>(); //this is a list of the spots that are in the line.
    dx = x2 - x1; //change in x and y.
    dy = y2 - y1;
    ax = abs(dx) << 1; //absolute values of dx and dy multiplied by 2.
    ay = abs(dy) << 1;
    sx = SGN(dx); //signs of x and y.
    sy = SGN(dy);
    int t;
    if (dy == 0) sy = 0;
    if (dx == 0) sx = 0;
    Location cur(loc); //current location.
    int xmin = (x1 < x2 ? x1 : x2), ymin = (y1 < y2 ? y1 : y2),
                                           xmax = (x1 > x2 ? x1 : x2), ymax = (y1 > y2 ? y1 : y2);
    xmin -= abs(dx);
    ymin -= abs(dy);
    xmax += abs(dx);
    ymax += abs(dy); //minimums and maximums for x and y.
    if (ax == ay)
    {

        do
        {
            cur.move(sx, sy);
            if (!cur.correct())
            return;
            addLocation(cur);
        }
        while ((cur.getX() != x2 || cur.getY() != y2) &&
                (cur.getY() >= xmin && cur.getY() <= xmax && cur.getY() >= ymin && cur.getY() <= ymax));
    }
    else if (ax > ay)
    {
        t = ay - (ax >> 1);
        do
        {
            if (t >= 0)
            {
                cur.move(0, sy);
                t -= ax;
            }
            cur.move(sx, 0);
            t += ay;
            if (!cur.correct())
            return;
            addLocation(cur);
        }
        while ((cur.getX() != x2 || cur.getY() != y2) &&
                (cur.getX() >= xmin && cur.getX() <= xmax && cur.getY() >= ymin && cur.getY() <= ymax));
    }
    else
    {
        t = ax - (ay >> 1);
        do
        {
            if (t >= 0)
            {
                cur.move(sx, 0);
                t -= ay;
            }
            cur.move(0, sy);
            t += ax;
            if (!cur.correct())
            return;
            addLocation(cur);
        }
        while ((cur.getX() != x2 || cur.getY() != y2) &&
                (cur.getX() >= xmin && cur.getX() <= xmax && cur.getY() >= ymin && cur.getY() <= ymax));
    }
}

int Line::getX(int index)
{
    int x = x1;
    int cur = 0;
    if (ax >= ay)
    {
        return x + (index + 1) * sx;
    }
    else
    {
        //cerr << "!";
        //getch();
        int t;
        t = ax - (ay >> 1);
        do
        {
            if (t >= 0)
            {
                x += sx;
                t -= ay;
            }
            t += ax;
            cur++;
        }
        while (cur <= index);
    }
    return x;

}

int Line::getY(int index)
{
    int y = y1;
    int cur = 0;
    if (ax <= ay)
    {
        return y + (index + 1) * sy;
    }
    else
    {
        //cerr << "!";
        //getch();
        int t;
        t = ay - (ax >> 1);
        do
        {
            if (t >= 0)
            {
                y += sy;
                t -= ax;
            }
            t += ay;
            cur++;
        }
        while (cur <= index);
    }
    return y;
}

void Line::cutOff(int index)
{
    x2 = getX(index);
    y2 = getY(index);
    while (line.size() >= index)
    line.pop_back();
}

Line::~Line()
{
    //dtor
}
