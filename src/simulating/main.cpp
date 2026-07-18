#include "Vector2D.h"
#include "Body.h"
#include "Physics.h"
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


    Body body1 = { 5.0, Vector2D(0.0, 0.0), Vector2D(0,0), Vector2D(0,0) };
    Body body2 = { 5.0, Vector2D(3.0, 4.0), Vector2D(0,0), Vector2D(0,0) };

    double dt = 0.01;
    int nombre_iterations = 1000;

    for(int i = 0; i < nombre_iterations; ++i) {
        if (i % 100 == 0) {
            std::cout << "Iteration: " << i 
            << " | Position: (" << body1.position.getX() 
            << ", " << body1.position.getY() << ")" << std::endl;
        }
        Vector2D force = Physics::computeGravitationalForce(body1, body2);
        Physics::integrate(body1, force, dt);
    }
    return 0;
}