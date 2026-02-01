#include "Sprite.hpp"

#include "raylib.h"
#include "Level.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Portfolio 2025 - Aufgabe 8");
    SetTargetFPS(60);

    game::Level myLevel;

    // Teil b: 20 Sprites in einer for-Schleife erstellen
    for (int i = 0; i < 20; ++i) {
        // Nutzt deinen Pfad-Konstruktor
        auto newSprite = std::make_shared<game::Sprite>(0, 0, "resources/character.png");
        myLevel.sprites_.push_back(newSprite);
    }

    // Zufällig positionieren
    myLevel.positionRandomly();

    while (!WindowShouldClose()) {
        // Teil c: Update Methode
        myLevel.Update();

        BeginDrawing();
        ClearBackground(DARKGRAY);

        // Teil b: Zeichnen über die Levelklasse
        myLevel.drawAll();

        DrawText("Kollision = Löschen", 10, 10, 20, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}