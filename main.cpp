#include "Jeu.hpp"
#include <iostream>
#include <chrono>

void test_ex1() {
    Jeu g1(20, 20,5000);

    while(true) {


        std::cout << "Initial state:\n";
        g1.afficheC();
        std::cout << "\n";


        g1.AjouteCellule(5, 5);
        g1.AjouteCellule(5, 6);
        g1.AjouteCellule(5, 7);
        std::cout << "After adding cells:\n";
        g1.afficheC();
        std::cout << "\n";

        g1.avance();
        std::cout << "After 1st advance:\n";
        g1.afficheC();
        std::cout << "\n";

        g1.avance();
        std::cout << "After 2nd advance:\n";
        g1.afficheC();
        std::cout << "\n";

        g1.avance();
        std::cout << "After 3rd advance:\n";
        g1.afficheC();
        std::cout << "\n";

        g1.avance();
        std::cout << "After 4th advance:\n";
        g1.afficheC();
        std::cout << "\n";
        
        g1.attendre();

        
    }
    
}

int main() {
    test_ex1();
    return 0;
}
