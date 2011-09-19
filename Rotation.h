#ifndef ROTATION_H
#define ROTATION_H

//Rotates Clockwise

enum Rotation
{
    DEGREE_0 = 0,
    DEGREE_90,
    DEGREE_180,
    DEGREE_270
};

Rotation spin(Rotation r1, Rotation r2);


#endif
