#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // float AB_AP = (b.getX().toFloat() - a.getX().toFloat()) * (point.getY().toFloat() - a.getY().toFloat()) -
    //            (b.getY().toFloat() - a.getY().toFloat()) * (point.getX().toFloat() - a.getX().toFloat());

    // float BC_BP = (c.getX().toFloat() - b.getX().toFloat()) * (point.getY().toFloat() - b.getY().toFloat()) -
    //            (c.getY().toFloat() - b.getY().toFloat()) * (point.getX().toFloat() - b.getX().toFloat());

    // float CA_CP = (a.getX().toFloat() - c.getX().toFloat()) * (point.getY().toFloat() - c.getY().toFloat()) -
    //            (a.getY().toFloat() - c.getY().toFloat()) * (point.getX().toFloat() - c.getX().toFloat());
    Fixed AB_AP = (b.getX() - a.getX()) * (point.getY() - a.getY()) -
                (b.getY() - a.getY()) * (point.getX() - a.getX());

    Fixed BC_BP = (c.getX() - b.getX()) * (point.getY() - b.getY()) -
                (c.getY() - b.getY()) * (point.getX() - b.getX());

    Fixed CA_CP = (a.getX() - c.getX()) * (point.getY() - c.getY()) -
                (a.getY() - c.getY()) * (point.getX() - c.getX());

    bool has_neg = (AB_AP < 0) || (BC_BP < 0) || (CA_CP < 0); 
    bool has_pos = (AB_AP > 0) || (BC_BP > 0) || (CA_CP > 0);
    bool has_zero = (AB_AP == 0) || (BC_BP == 0) || (CA_CP == 0);

    if (has_zero)
        return false;
    return !(has_neg && has_pos);
}


