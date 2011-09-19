#include "Rotation.h"

Rotation spin(Rotation r1, Rotation r2)
{
    int ret = static_cast<int>(r1) + static_cast<int>(r2);
    while(ret > 3)
    ret -= 4;
    return static_cast<Rotation>(ret);
}
