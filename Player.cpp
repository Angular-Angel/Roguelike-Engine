#include "Player.h"

Player::Player(Body& bod) : Controller(bod), viewPoint(CurrentArea((getBody().getLocation()))), inControl(true)
{
}

Player::~Player()
{
    //dtor
}

void Player::controlLoop()
{
    int ch;
    int moveDir;
    CharRaster vision = getBody().getVision(10, 10);
    DisplayManager::getDisplayManager().printTerrain(vision);
    while((ch = getch()) != 'q')
    {
        switch (ch)
        {
            case  KEY_LEFT:
            {
                moveDir = DIRECTION_WEST - viewPoint.getRotation();
                if (viewPoint.getRotation() == DEGREE_0 || viewPoint.getRotation() == DEGREE_180)
                {
                    if (viewPoint.isMirroredX())
                    moveDir += 2;
                }
                else
                {
                    if (viewPoint.isMirroredY())
                    moveDir += 2;
                }
                while (moveDir >= 4)
                moveDir -= 4;
                while (moveDir < 0)
                moveDir += 4;
                move(static_cast<Direction>(moveDir));
                break;
            }
            case KEY_RIGHT:
            {
                moveDir = DIRECTION_EAST - viewPoint.getRotation();
                if (viewPoint.getRotation() == DEGREE_0 || viewPoint.getRotation() == DEGREE_180)
                {
                    if (viewPoint.isMirroredX())
                    moveDir += 2;
                }
                else
                {
                    if (viewPoint.isMirroredY())
                    moveDir += 2;
                }
                while (moveDir >= 4)
                moveDir -= 4;
                while (moveDir < 0)
                moveDir += 4;
                move(static_cast<Direction>(moveDir));
                break;
            }
            case KEY_UP:
            {
                moveDir = DIRECTION_NORTH - viewPoint.getRotation();
                if (viewPoint.getRotation() == DEGREE_0 || viewPoint.getRotation() == DEGREE_180)
                {
                    if (viewPoint.isMirroredY())
                    moveDir += 2;
                }
                else
                {
                    if (viewPoint.isMirroredX())
                    moveDir += 2;
                }
                while (moveDir >= 4)
                moveDir -= 4;
                while (moveDir < 0)
                moveDir += 4;
                move(static_cast<Direction>(moveDir));
                break;
            }
            case KEY_DOWN:
            {
                moveDir = DIRECTION_SOUTH - viewPoint.getRotation();
                if (viewPoint.getRotation() == DEGREE_0 || viewPoint.getRotation() == DEGREE_180)
                {
                    if (viewPoint.isMirroredY())
                    moveDir += 2;
                }
                else
                {
                    if (viewPoint.isMirroredX())
                    moveDir += 2;
                }
                while (moveDir >= 4)
                moveDir -= 4;
                while (moveDir < 0)
                moveDir += 4;
                move(static_cast<Direction>(moveDir));
                break;
            }

        }
        vision = getBody().getVision(20, 20);
        DisplayManager::getDisplayManager().printTerrain(vision);
        //viewPoint.print(); //Draws the view without line of sight.
    }
}

void Player::move(int x, int y)
{
    getBody().move(x, y);
}

void Player::move(Direction dir)
{
    switch(dir)
    {
        case DIRECTION_NORTH:
        move(0, -1);
        break;
        case DIRECTION_EAST:
        move(1, 0);
        break;
        case DIRECTION_SOUTH:
        move(0, 1);
        break;
        case DIRECTION_WEST:
        move(-1, 0);
        break;
    }
}

void Player::updatePos()
{
    viewPoint.setX(getBody().getLocation().getX());
    viewPoint.setY(getBody().getLocation().getY());
}

void Player::updateArea(BorderArea border)
{
    viewPoint.rotate(border.getRotation());
    if (border.isMirroredX())
    viewPoint.mirrorX();
    if (border.isMirroredY())
    viewPoint.mirrorY();
    viewPoint.setArea(border.getArea());
}
