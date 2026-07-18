#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D() : x(0.0), y(0.0) {}

double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}

Vector2D Vector2D::operator-(const Vector2D& autre) const {
    return Vector2D(x - autre.x, y - autre.y);
}

double Vector2D::length() const {
    return sqrt(x*x + y*y);
}