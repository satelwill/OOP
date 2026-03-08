#include <math.h>
#include "droite.h"

// classe Droite

Droite::Droite() {
    m = 0;
    b = 0;
}

Droite::Droite(double m, double b) {
    this->m = m;
    this->b = b;
}

// y = m * x + b
Droite::Droite(Point &p1, Point &p2) {
    if (p1 == p2) {
        throw "Exception dans Droite::Droite : p1 == p2";
    }

    if (p1.GetX() == p2.GetX()) {
        throw "Exception dans Droite::Droite: droite verticale. Cas non traité.";
    } 
    
    m = (p1.GetY() - p2.GetY()) / (p1.GetX() - p2.GetX());
    b = p1.GetY() - m * p1.GetX();
}

bool Droite::TestAppartenance(Point &p) const {
    return p.GetY() == CalcY(p.GetX());
}

bool Droite::TestParallelisme(Droite &d) const {
    return m == d.GetM();
}

bool Droite::TestOrthogonalite(Droite &d) const {
    return m * d.GetM() == -1;
}

Droite Droite::DroiteParallele(Point &p) const {
    // droite parallelle: y = m * x + b2. p appartient à d2 => b2 = p.y - m * p.x
    double b2 = p.GetY() - m * p.GetX();
    
    Droite d2(m, b2);
    
    return d2;
}

double Droite::CalcY(double x) const {
     return m * x + b;
 } 

double Droite::GetM() const {
     return m;
}
 
double Droite::GetB() const {
     return b;
}

std::ostream &operator << (std::ostream &os, const Droite &d)
{
    os << "[Droite eq. (y = " << d.GetM() << "x + " << d.GetB() << ")]";
    return os;  
}

// classe Segment
Segment::Segment(Point &point1, Point &point2) {
    if (point1 == point2) {
        throw "Exception dans Segment::Segment : p1 == p2";
    }    
    p1 = point1;
    p2 = point2;
}

Segment::Segment() : p1(0, 0), p2(1, 1) {    
}

double Segment::Longueur() const {
    double dx = p2.GetX() - p1.GetX();
    double dy = p2.GetY() - p1.GetY();
    return sqrt (dx * dx + dy * dy);
}

std::ostream& operator << (std::ostream &os, const Segment &s) {
    os << "[Segment " << s.p1 << ", " << s.p2 << "]";
    return os;
}
