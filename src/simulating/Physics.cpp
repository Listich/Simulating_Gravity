#include "Physics.h"
#include <cmath>

Vector2D Physics::computeGravitationalForce(const Body& a, const Body& b) {
    Vector2D direction = b.position - a.position;
    double distance = direction.length();
    Vector2D normalizedDirection = direction / distance;
    double intensity = G * (a.mass * b.mass) / (distance *distance);
    return normalizedDirection * intensity;
}

