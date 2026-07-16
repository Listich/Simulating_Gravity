#include "Vector2D.h"
#include "Body.h"
#include <iostream>


int main() {
    Body b = { 5.0, Vector2D(1.0, 2.0), Vector2D(0.5, 0.5), Vector2D(0.1, 0.1) };
    std::cout << "Body mass: " << b.mass << std::endl;
    Vector2D v(3.0, 4.0);
    std::cout << "Vector2D: (" << v.getX() << ", " << v.getY() << ")" << std::endl;
}