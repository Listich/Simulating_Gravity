#pragma once

#include "Vector2D.h"

class Body {
public:
    double mass;
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
};