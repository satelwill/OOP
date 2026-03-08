#include <math.h>
#include "triangle.h"

using namespace std;

Triangle::Triangle(): Triangle (Point(0, 0), Point(1, 0), Point(0,1)) {
}

Triangle::Triangle(Point A, Point B, Point C) {
    
    if ((A.GetX() == B.GetX() && A.GetX() == C.GetX()) || 
            (A.GetY() == B.GetY() && A.GetY() == C.GetY())) {
        throw "Exception dans Triangle::Triangle : triangle invalide !";
    }

    this->A = A;
    this->B = B;
    this->C = C;   

    AB = Segment(this->A, this->B);
    BC = Segment(this->B, this->C);
    CA = Segment(this->C, this->A); 
}

Triangle::~Triangle() {
}

bool Triangle::TestIsocele() {
    double l1, l2, l3;
    
    l1 = AB.Longueur();
    l2 = BC.Longueur();
    l3 = CA.Longueur();
    
    if (l1 == l2 || l2 == l3 || l3 == l1) {
        return true;
    }
    
    return false;
}

bool Triangle::TestRectangle() {
    double l1, l2, l3;
    l1 = AB.Longueur();
    l2 = BC.Longueur();
    l3 = CA.Longueur();
    
    if (l1 >= l2 && l1 >= l3) {
        return TestRectangle(l1, l2, l3);
    }
    
    if (l2 >= l3) {
        return TestRectangle(l2, l1, l3);
    }
    
    return TestRectangle(l3, l1, l2);
}

bool Triangle::TestRectangle(double a, double b, double c) {
    // on suppose que a >= b et que a >= c
    if (b > a || c > a) {
        throw("Exception dans Triangle::TestRectangle : b > a || c > a");
    }
    
    return a == sqrt(b * b + c * c);
    // Note : Attention aux nombres irrationnels (avec une représentation finie, ici double) ! 
    // Car les résultats risquent d'être inattendus quand on manipule des irrationnels ! Par exemple : sqrt(2) * sqrt(2) == 2 ?  ... Non.
}
 
void Triangle::CalculMediatrices(double &ma, double &mb, double &mc) {
    // a completer
}

void Triangle::CalculHauteurs(double &ha, double &hb, double &hc) {
    double aireX2 = CalculAire() * 2;

    double a, b, c;
    c = AB.Longueur();
    a = BC.Longueur();
    b = CA.Longueur();

    if (!a || !b || !c) {
        throw "Exception dans Triangle::CalculHauteurs : coté null !";
    }

    ha = aireX2 / a;
    hb = aireX2 / b;
    hc = aireX2 / c;
}

bool Triangle::CalculCentreDeGravite(Point &cv) {
    
    double x = (A.GetX() + B.GetX() + C.GetX())/3;
    double y = (A.GetY() + B.GetY() + C.GetY())/3;
    
    cv.SetX(x);
    cv.SetY(y);
    
    return true;
}

double Triangle::CalculAire() {
    double a, b, c, d;
    c = AB.Longueur();
    a = BC.Longueur();
    b = CA.Longueur();
    
    d = (a + b + c) / 2;
    
    return sqrt (d * (d - a) * (d - b) * (d - c));
}