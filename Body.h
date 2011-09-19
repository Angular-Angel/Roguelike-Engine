#ifndef BODY_H
#define BODY_H

#include "Location.h"

class Controller;

/** Represents most creatures

*/

class Body
{
    public:
        /** Default constructor */
        Body(Location, int sight = 1, char rep = '@');
        /** Default destructor */
        virtual ~Body();
        /** Access sightRange
        * \return The current value of sightRange
        */
        int getSightRange() {return sightRange;}
        /** Set sightRange
        *\param sight New value to set
        */
        void setSightRange(int sight) {sightRange = sight;}
        Location& getLocation() {return location;}
        void setLocation(Location place) {location = place;}
        char getSymbol() {return symbol;}
        void setControl(Controller& cont) {control = &cont;}
        void print();
        void moveTo(int x, int y);
        void move(int x, int y);
    protected:
    private:
    Controller* control;
    Location location;
    int sightRange;
    char symbol;
};

#endif // BODY_H
