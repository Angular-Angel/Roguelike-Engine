#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#include "ncurses.h"
#include "CharRaster.h"

/*

----------------------


*/


class DisplayManager
{
    public:
        static DisplayManager& getDisplayManager();
        /** Default destructor */
        ~DisplayManager();
        void printTerrain(CharRaster&, int x = 0, int y = 0);
    protected:
    private:
        WINDOW* areaDisplay;
        WINDOW* messageLog;

        /** Default constructor */
        DisplayManager();
        static DisplayManager* instance;
};

#endif // DISPLAYMANAGER_H
