#ifndef _DROITE_H_
#define _DROITE_H_

#include <iostream>
#include "point.h"

class Droite {
public:
    Droite(Point &point1, Point &point2);
    Droite(double m, double b);
    Droite();

    bool TestAppartenance(Point &p) const;
    bool TestParallelisme(Droite &d) const;
    bool TestOrthogonalite(Droite &d) const;
    Droite DroiteParallele(Point &p) const;

    double CalcY(double x) const;  // retourne le y pour un x donné
    double GetM() const;    // get pente
    double GetB() const;    // get ordonnée à l'origine

private:
    // equation de la droite, forme fonctionnelle : y = m * x + b
    double m;   // pente
    double b;   // ordonnée à l'origine

    void CalculMB();
};

std::ostream &operator << (std::ostream &os, const Droite &d);

class Segment {
public:
    Segment(Point &point1, Point &point2);
    Segment();

    double Longueur() const;

    friend std::ostream & operator << (std::ostream &os, const Segment &d);

private:
    Point p1, p2;
    Droite d;
};

#endif // _DROITE_H_
