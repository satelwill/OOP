#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "point.h"
#include "droite.h"

class Triangle {
public:
    Triangle(Point A, Point B, Point C);
    Triangle();
    ~Triangle();
    
    bool TestIsocele();
    bool TestRectangle();
    bool TestRectangle(double a, double b, double c);
    void CalculHauteurs(double &ha, double &hb, double &hc);
    void CalculMediatrices(double &ma, double &mb, double &mc);
    bool CalculCentreDeGravite(Point &cv);
    double CalculAire();
    
private:
    Point A, B, C;
    Segment AB, BC, CA;
};

#endif // _TRIANGLE_H_
