#pragma once 
#include "Vector2D.h"
#include <raylib.h>

namespace Render {
    struct ScreenPosition {
        double x;
        double y;
    };
    ScreenPosition worldToScreen(const Vector2D& positionPhysique, double facteurEchelle, int screenWidth, int screenHeight);
}