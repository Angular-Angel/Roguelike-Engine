#ifndef PLAYER_H
#define PLAYER_H

#include "Body.h"
#include "CurrentArea.h"
#include "Controller.h"

class Player : public Controller
{
    public:
        /** Default constructor */
        Player(Body&);
        /** Default destructor */
        virtual ~Player();
        /** Access character
        * \return Current value of character.
        */
        void controlLoop();
        void updateVision();
        virtual void updatePos();
        virtual void updateArea(BorderArea);
    protected:
    private:
        void move(int, int);
        void move(Direction);
        CurrentArea viewPoint;
        bool inControl;
};

#endif // PLAYER_H
