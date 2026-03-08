#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>

class Point {
public:
    Point(double abs, double ord);
    Point(Point &p);
    Point();
    double GetX() const;
    double GetY() const;
    bool operator == (Point &p) const;    
    double SetX(double x);
    double SetY(double y);
    
private:
    double x, y;
};

std::ostream& operator << (std::ostream &os, const Point &p);

#endif // _POINT_H_
