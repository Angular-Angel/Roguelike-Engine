#include "DisplayManager.h"

DisplayManager* DisplayManager::instance = NULL;

DisplayManager::DisplayManager()
{
    areaDisplay = newwin(30, 30, 0, 0);
}

DisplayManager::~DisplayManager()
{
    delete instance;
}

void DisplayManager::printTerrain(CharRaster& ch, int x, int y)
{
    ch.print(x, y, areaDisplay);
    wrefresh(areaDisplay);
}

DisplayManager& DisplayManager::getDisplayManager()
{
    if (instance == NULL)
    instance = new DisplayManager();
    return *instance;
}
