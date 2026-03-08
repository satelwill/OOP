#include "triangle.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Triangle tr1 (Point (0, 0), Point (1, 0), Point (0, 1));        
        cout << "tr1 est triangle isocele :" << (tr1.TestIsocele() ? " vrai" : " faux") << endl;
        cout << "tr1 est triangle rectangle :" << (tr1.TestRectangle() ? " vrai" : " faux") << endl;

        Triangle tr3 (Point (1, 0), Point (2, 0), Point (1, 3));
        cout << "tr3 est triangle isocele :" << (tr3.TestIsocele() ? " vrai" : " faux") << endl;
        cout << "tr3 est triangle rectangle :" << (tr3.TestRectangle() ? " vrai" : " faux") << endl;

        Triangle tr4 (Point (1, 0), Point (2, 0), Point (2, 3));
        cout << "tr4 est triangle rectangle :" << (tr4.TestRectangle() ? " vrai" : " faux") << endl;

        Triangle tr5 (Point (1, 0), Point (2, 0), Point (1.2, 3));
        cout << "tr5 est triangle rectangle :" << (tr5.TestRectangle() ? " vrai" : " faux") << endl;
        
        Triangle tr6 (Point (1, 0), Point (2, 0), Point (1.5, 3));
        cout << "tr6 est triangle isocele :" << (tr6.TestIsocele() ? " vrai" : " faux") << endl;

        Point tr4_cv;
        tr4.CalculCentreDeGravite(tr4_cv);
        cout << "Centre de gravité tr4 : " << tr4_cv << endl;

        cout << "Aire tr1 : " << tr1.CalculAire() << endl;

        double ha, hb, hc;
        tr1.CalculHauteurs(ha, hb, hc);

        cout << "Hauteurs tr1 : " << ha << ", " << hb << ", " << hc << endl;

        Triangle tr2 (Point (0, 0), Point (1, 0), Point (2, 0)); // exemple exception
        cout << "exception tr2... " << endl; // code non-executé
    } 
    catch(const char* mess) {
        cout << mess << endl;
    }
    catch(...) {
        cout << "Exception: Autre exception" << endl;
    }

    cout << "Fin testTriangle." << endl;

    return 0;
}