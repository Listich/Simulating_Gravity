#include "Render.h"

Render::ScreenPosition Render::worldToScreen(const Vector2D& positionPhysique, double facteurEchelle, int screenWidth, int screenHeight) {
    double pixel_x = positionPhysique.getX() * facteurEchelle + screenWidth / 2;
    double pixel_y = -positionPhysique.getY() * facteurEchelle + screenHeight / 2;
    return ScreenPosition{ pixel_x, pixel_y };
}

