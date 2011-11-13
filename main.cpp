#include <iostream>
#include "LocalArea.h"
#include "Player.h"
#include <ncurses.h>
#include "CharRaster.h"
#include "Color.h"

/*TODO
debug by having lineTo print to cerr the coordinates of each location it finds.
*/

using namespace std;

int main()
{
    initscr();
    raw();
    noecho();
    keypad(stdscr, true);
    define_color();
    const TerrainType floor('.');
    const TerrainType wall('#', WHITEBLACK, false, false);
    const TerrainType six('6', REDBLACK);
    const TerrainType four('4');
    const TerrainType five('5');
    const TerrainType stair('=');
    LocalArea bigPlace(floor, 9, 9);
    for (int i = 0; i < bigPlace.getHeight(); i++)
    {
        if (i != bigPlace.getHeight()/2)
        {
            bigPlace.setTerrain(wall, 0, i);
            bigPlace.setTerrain(wall, bigPlace.getWidth()-1, i);
        }
    }
    for (int j = 0; j < bigPlace.getWidth(); j++)
    {
        if (j != bigPlace.getWidth()/2)
        {
            bigPlace.setTerrain(wall, j, 0);
            bigPlace.setTerrain(wall, j, bigPlace.getHeight()-1);
        }
    }
    bigPlace.setTerrain(six, 7, 7);
    LocalArea bottomStair(stair, 1, 1);
    bigPlace.nullTerrain(3, 3);
    bigPlace.addBorderArea(BorderArea(bottomStair, 3, 3, 5));
    bottomStair.addBorderArea(BorderArea(bigPlace, -3, -3, -5));
    LocalArea stairs(stair, 1, 3);
    bottomStair.addBorderArea(BorderArea(stairs, 0, -3));
    stairs.addBorderArea(BorderArea(bottomStair, 0, 3));
    LocalArea topStair(stair, 1, 1);
    stairs.addBorderArea(BorderArea(topStair, 0, -1));
    bigPlace.nullTerrain(5, 5);
    bigPlace.nullTerrain(5, 6);
    bigPlace.addBorderArea(BorderArea(topStair, 5, 5));
    topStair.addBorderArea(BorderArea(bigPlace, -5, -5, 5));
    topStair.addBorderArea(BorderArea(stairs, 0, 1, -5));
    bigPlace.addBorderArea(BorderArea(bigPlace, 0, -9, 0, DEGREE_0));
    bigPlace.addBorderArea(BorderArea(bigPlace, -9, 0, 0, DEGREE_90));
    bigPlace.addBorderArea(BorderArea(bigPlace, 0, 9, 0, DEGREE_180));
    bigPlace.addBorderArea(BorderArea(bigPlace, 9, 0, 0, DEGREE_270));
    LocalArea testPlace(floor, 6, 6);
    Body character(Location(testPlace, 2, 2), 2, '@', GREENBLACK);
    Player player(character);
    refresh();
    player.controlLoop();
    endwin();
    return 0;
}
