#include "droite.h"
#include <iostream>

using namespace std;

int main() {
    
    try {
        Point p01(1, 2), p02 (2, 2);    
        Droite d0(p01, p02);    
        cout << d0 << endl;  
        cout << d0.CalcY(7) << endl;

        Point p11(1, 1), p12 (2, 2);    
        Droite d1(p11, p12);    
        cout << d1 << endl;  
        cout << d1.CalcY(7) << endl;

        Droite d2(-1, 0);    
        cout << d2 << endl;    
        cout << d2.CalcY(7) << endl;
        cout << d2.CalcY(-7) << endl;

        Droite d4(2, 1);    
        cout << d4 << endl;    

        Droite d5(2, 5);    
        cout << d5 << endl;    

        Droite d6(-0.5, 5);    
        cout << d6 << endl;    

        // test d'appartenance
        Point pt1 (8, 8);
        cout << pt1 << " appartient à la " << d1 << ":" << (d1.TestAppartenance(pt1) ? " vrai" : " faux") << endl;
        Point pt2 (8, 9);
        cout << pt2 << " appartient à la " << d1 << ":" << (d1.TestAppartenance(pt2) ? " vrai" : " faux") << endl;

        Point pt3 (8, 17);
        cout << pt3 << " appartient à la " << d4 << ":" << (d4.TestAppartenance(pt3) ? " vrai" : " faux") << endl;
        Point pt4 (8, 16);
        cout << pt4 << " appartient à la " << d4 << ":" << (d4.TestAppartenance(pt4) ? " vrai" : " faux") << endl;

        // test parallellisme
        cout << "d4 || d5 : " << (d4.TestParallelisme(d5) ? " oui " : " non ") << endl;
        cout << "d4 || d1 : " << (d4.TestParallelisme(d1) ? " oui " : " non ") << endl;

        // test orthogonalité
        cout << "d4 L d6 : " << (d4.TestOrthogonalite(d6) ? " oui " : " non ") << endl;
        cout << "d4 L d5 : " << (d4.TestOrthogonalite(d5) ? " oui " : " non ") << endl;

        // droite || passant par un point donné
        Point pt5 (0, 0);
        Droite d7 = d4.DroiteParallele(pt5);
        cout << " || à la " << d4 << " passant par le " << pt5 << " : " << d7 << endl;

        Point pt6 (1, 1);
        Droite d8 = d4.DroiteParallele(pt6);
        cout << " || à la " << d4 << " passant par le " << pt6 << " : " << d8 << endl;
        
        // droite invalide! -> exception
        Point p31(2, 4), p32(2, 4);
        Droite d3(p31, p32);        
        
        // droite verticale -> exception
        Point pt91(2, 4), pt92(2, 5);
        Droite d9(pt91, pt92);        
    } 
    catch(const char* mess) {
        cout << mess << endl;
    }
    catch(...) {
        cout << "Autre exception" << endl;
    }        

    cout << "Fin testDroite" << endl;
    
    return 0;
}
