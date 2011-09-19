#ifndef BORDERAREA_H
#define BORDERAREA_H

#include "Rotation.h"

class Location;

class LocalArea;

class BorderArea
{
public:
    /** Default constructor */
    BorderArea(LocalArea&, int X, int Y, int elev = 0, Rotation rot = DEGREE_0, bool mirrorx = false, bool mirrory = false);
    /** Default destructor */
    virtual ~BorderArea();
    /** Access offset
    * \return The current value of offset
    */
    Rotation getRotation()
    {
        return rotation;
    }
    /** Set rotation
    * \param val New value to set
    */
    void setRotation(Rotation rot)
    {
        rotation = rot;
    }
    /** Access xmirroring
    * \return The current value of xmirroring
    */
    bool isMirroredX()
    {
        return xmirroring;
    }
    /** Set xmirroring
    * \param val New value to set
    */
    void setMirroredX(bool val)
    {
        xmirroring = val;
    }
    /** Access ymirroring
    * \return The current value of ymirroring
    */
    bool isMirroredY()
    {
        return ymirroring;
    }
    /** Set ymirroring
    * \param val New value to set
    */
    void setMirroredY(bool val)
    {
        xmirroring = val;
    }
    /** Access area
    * \return The current value of area
    */
    LocalArea& getArea()
    {
        return *area;
    }
    /** Set area
    * \param val New value to set
    */
    void setArea(LocalArea& val)
    {
        area = &val;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void setX(int X)
    {
        x = X;
    }
    void setY(int Y)
    {
        y = Y;
    }
    int getElevation()
    {
        return depth;
    }
    void setElevation(int elev)
    {
        depth = elev;
    }
    bool contains(int x, int y);
    Location getLocation(int x, int y);
protected:
private:
    LocalArea* area; //!< Member variable "area"
    Rotation rotation; //!< Member variable "rotation"
    int x; //!< Member variable "x"
    int y; //!< Member variable "y". These represent the point where the BorderArea is relative to the LocalArea
    bool xmirroring; //!< Member variable "xmirroring". This represents whether the LocalArea is flipped along the x-axis.
    bool ymirroring; //!< Member variable "ymirroring". This represents whether the LocalArea is flipped along the y-axis.
    int depth;
};

#endif // BORDERAREA_H
