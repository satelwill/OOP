#include <iostream>
#include "point.h"

int main() {
    Point p1 (2, 3), p2 (4, -1), p3 (2.0, 3);
    
    std::cout << "p1: " << p1.GetX() << ", " << p1.GetY() << std::endl;
    std::cout << "p2: " << p2.GetX() << ", " << p2.GetY() << std::endl;
    std::cout << "p3: " << p3 << std::endl;
    
    std::cout << (p1 == p2) << std::endl;
    std::cout << (p1 == p3) << std::endl;
    
    return 0;
}
