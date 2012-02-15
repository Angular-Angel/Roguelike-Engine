#include "Controller.h"

Controller::Controller(Body& bod) : body(bod)
{
    body.setControl(*this);
}

Controller::~Controller()
{
    //dtor
}

void Controller::move(int x, int y)
{
    //getBody().move(x, y);
}

void Controller::updatePos() {}

void Controller::updateArea(BorderArea) {}

void Controller::lookAt(Line) {}
