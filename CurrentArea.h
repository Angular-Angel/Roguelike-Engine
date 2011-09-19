#ifndef CURRENTAREA_H
#define CURRENTAREA_H

#include "Location.h"
#include "DisplayManager.h"

class CurrentArea
{
    public:
        /** Default constructor */
        CurrentArea(LocalArea&, int x = 0, int y = 0, Rotation rot = DEGREE_0, bool mirrorx = false, bool mirrory = false);
        CurrentArea(Location&, Rotation r = DEGREE_0, bool mirrorx = false, bool mirrory = false);
        /** Default destructor */
        virtual ~CurrentArea();
        LocalArea getArea() {return *area;}
        void setArea(LocalArea& local) {area = &local;}
        int getX() {return x;}
        void setX(int X) {x = X;}
        int getY() {return y;}
        void setY(int Y) {y = Y;}
        int getDrawX();
        int getDrawY();
        Rotation getRotation() {return rot;}
        void setRotation(Rotation rotation) {rot = rotation;}
        void rotate(Rotation);
        bool isMirroredX() {return mirroredX;}
        void setMirroredX(bool mirror) {mirroredX = mirror;}
        bool isMirroredY() {return mirroredY;}
        void setMirroredY(bool mirror) {mirroredY = mirror;}
        void mirrorX() {mirroredX += 1;}
        void mirrorY() {mirroredY += 1;}
        void print();
    protected:
    private:
    LocalArea* area;
    int x, y;
    Rotation rot;
    bool mirroredX;
    bool mirroredY;
};

#endif // CURRENTAREA_H
