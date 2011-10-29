#ifndef LOCATION_H
#define LOCATION_H

#include "LocalArea.h"

class Location
{
    public:
        /** Default constructor */
        Location(LocalArea&, int X = 0, int Y = 0);
        /** Default destructor */
        virtual ~Location();
        /** Access x
         * \return The current value of x
         */
        int getX() { return x; }
        /** Set x
         * \param val New value to set
         */
        void setX(int val) { x = val; }
        /** Access y
         * \return The current value of y
         */
        int getY() { return y; }
        /** Set y
         * \param val New value to set
         */
        void setY(int val) { y = val; }
        void move(int X, int Y) {x += X; y += Y;}
        /** Access localArea
         * \return The current value of localArea
         */
        LocalArea& getLocalArea() {return *localArea;}
        /** Set localArea
         * \param val New value to set
         */
        void setLocalArea(LocalArea val) { localArea = &val; }
        const TerrainType* getTerrain() {return getLocalArea().getTerrain(getX(), getY());}
        bool correct();
    protected:
    private:
        LocalArea* localArea; //!< Member variable "localArea"
        int x; //!< Member variable "x"
        int y; //!< Member variable "y"
};

#endif // LOCATION_H
