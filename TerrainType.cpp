#include "TerrainType.h"

TerrainType::TerrainType(char display, charAttr chAt, bool pass, bool see) : displayChar(display), attr(chAt), passable(pass), transparent(see)
{
}

TerrainType::~TerrainType()
{
    //dtor
}
