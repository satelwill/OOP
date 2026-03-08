#include <iostream>
#include "point.h"


Point::Point(double abs, double ord): x(abs), y(ord) {
}

Point::Point(): x(0), y(0) {
}

Point::Point(Point &p): x(p.GetX()), y(p.GetY()) {
}

double Point::GetX() const {
    return x;
}

double Point::GetY() const {
    return y;
}
    
bool Point::operator == (Point &p) const {
    return (x == p.GetX() && y == p.GetY());
}

double Point::SetX(double x) {
    this->x = x;
    return this->x;
}

double Point::SetY(double y) {
    return this->y = y;
}

std::ostream& operator << (std::ostream &os, const Point &p)
{    
    os << "[Point (" << p.GetX() << ", " << p.GetY() << ")]";
    return os;
}