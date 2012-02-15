#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Body.h"

class Controller
{
    public:
        /** Default constructor */
        Controller(Body&);
        /** Default destructor */
        virtual ~Controller();
        Body& getBody() {return body;}
        virtual void updatePos();
        virtual void updateArea(BorderArea);
        virtual void lookAt(Line);
    protected:
    private:
        void move(int, int);
        Body& body;
};

#endif // CONTROLLER_H
