#include "Vector2D.h"
#include "Body.h"
#include <iostream>


int main() {
    Body b = { 5.0, Vector2D(1.0, 2.0), Vector2D(0.5, 0.5), Vector2D(0.1, 0.1) };
    std::cout << "Body mass: " << b.mass << std::endl;

    Vector2D v(3.0, 4.0);
    std::cout << "Vector2D: (" << v.getX() << ", " << v.getY() << ")" << std::endl;

    std::cout << "Test de Pythagore" << std::endl;

    Vector2D pointA(0.0, 0.0);
    Vector2D pointB(3.0, 4.0);

    Vector2D entre_A_et_B = pointB - pointA; 

    double distance = entre_A_et_B.length();

    std::cout << "Vecteur entre A et B : (" << entre_A_et_B.getX() << ", " << entre_A_et_B.getY() << ")" << std::endl;
    std::cout << "Distance calculée (Pythagore) : " << distance << std::endl;

    std::cout << "Test de normalisation" << std::endl;
    Vector2D pointC(3.0, 4.0);
    double lengthC = pointC.length();

    Vector2D normalise = pointC / lengthC;
    std::cout << "Vecteur normalise : (" << normalise.getX() << ", " << normalise.getY() << ")" << std::endl;


    return 0;
}