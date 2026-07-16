#pragma once

class Vector2D {

public:
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}
    double getX() const;
    double getY() const;
    Vector2D();
private:
    double x;
    double y;
    
};