#include "Location.h"

Location::Location(LocalArea& area, int X, int Y) :localArea(&area), x(X), y(Y)
{

}

Location::~Location()
{
    //dtor
}
