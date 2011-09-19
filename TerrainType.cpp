#include "TerrainType.h"

TerrainType::TerrainType(char display, bool pass, bool see) : displayChar(display), passable(pass), transparent(see)
{
}

TerrainType::~TerrainType()
{
    //dtor
}
