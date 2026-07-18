#pragma once
#include "Vector2D.h"
#include "Body.h"

namespace Physics {
    const double G = 6.67430e-11;
    Vector2D computeGravitationalForce(const Body& a, const Body& b);
    void integrate(Body& body, const Vector2D& totalForce, double deltaTime);
}
