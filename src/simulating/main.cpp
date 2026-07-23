#include "Vector2D.h"
#include "Body.h"
#include "Physics.h"
#include <iostream>
#include <raylib.h>
#include "Render.h"


int main() {
    InitWindow(800, 600, "Simulation Gravitationnelle");
    SetTargetFPS(60);
    Texture2D textureTerre = LoadTexture("terre.png");
    Texture2D textureLune  = LoadTexture("lune.png");

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
        ClearBackground(BLACK);

        
        Rectangle srcTerre  = { 0.0f, 0.0f, (float)textureTerre.width, (float)textureTerre.height };
        Rectangle destTerre = { (float)posTerre.x, (float)posTerre.y, 40.0f, 40.0f };
        Vector2 originTerre = { 20.0f, 20.0f };
        DrawTexturePro(textureTerre, srcTerre, destTerre, originTerre, 0.0f, WHITE);

    
        Rectangle srcLune  = { 0.0f, 0.0f, (float)textureLune.width, (float)textureLune.height };
        Rectangle destLune = { (float)posLune.x, (float)posLune.y, 16.0f, 16.0f };
        Vector2 originLune = { 8.0f, 8.0f };
        DrawTexturePro(textureLune, srcLune, destLune, originLune, 0.0f, WHITE);

        EndDrawing();
    }
    UnloadTexture(textureTerre);
    UnloadTexture(textureLune);
    CloseWindow();
    return 0;

}