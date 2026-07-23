#include "Vector2D.h"
#include "Body.h"
#include "Physics.h"
#include <iostream>
#include <raylib.h>
#include "Render.h"


int main() {
    InitWindow(800, 600, "Simulation Gravitationnelle");
    SetTargetFPS(60);

    Body terre;
    terre.mass = 5.972e24; // Masse de la Terre en kg
    terre.position = Vector2D(0.0, 0.0); // Position initiale de la Terre
    terre.velocity = Vector2D(0.0, 0.0); // Vitesse initiale de la Terre

    double distanceTerreLune = 3.844e8; // Distance moyenne entre la Terre et la Lune en mètres

    Body lune;
    lune.mass = 7.348e22; // Masse de la Lune en kg
    lune.position = Vector2D(distanceTerreLune, 0.0); // Position initiale de la Lune
    lune.velocity = Vector2D(0.0, 1018.0); // Vitesse initiale de la Lune (environ 1 km/s)

    while (!WindowShouldClose()) {
        double facteurEchelle = 7.8125e-7;
        double dt = 1296.0;
        int nombre_sous_etapes = 100;
        double dt_petit = dt / nombre_sous_etapes;

        for (int i = 0; i < nombre_sous_etapes ; ++i)  {
            Vector2D force = Physics::computeGravitationalForce(lune, terre);
            Physics::integrate(lune, force , dt_petit);
        }
        Render::ScreenPosition posTerre = Render::worldToScreen(terre.position, facteurEchelle, 800, 600);
        Render::ScreenPosition posLune = Render::worldToScreen(lune.position, facteurEchelle, 800, 600);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(static_cast<int>(posTerre.x), static_cast<int>(posTerre.y), 15, BLUE);
        DrawCircle(static_cast<int>(posLune.x), static_cast<int>(posLune.y), 5, GRAY);
        EndDrawing();
    }

}