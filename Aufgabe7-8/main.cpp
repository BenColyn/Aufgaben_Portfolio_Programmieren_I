#include "Sprite.hpp"

#include <random>
#include "Level.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Portfolio 2025 - Aufgabe 8");
    SetTargetFPS(60);

    game::Level myLevel;
    Texture2D rockTex = LoadTexture("resources/Rock.png");

    // Start-Sprites (optional)
    for (int i = 0; i < 20; ++i) {
        auto newSprite = std::make_shared<game::Sprite>(0, 0, rockTex);
        myLevel.sprites_.push_back(newSprite);
    }
    myLevel.positionRandomly();

    while (!WindowShouldClose()) {
        // Input-Abfrage gehört in den Game-Loop der main.cpp
        if (IsKeyPressed(KEY_SPACE)) {
            int x = GetRandomValue(0, screenWidth - 64);
            int y = GetRandomValue(0, screenHeight - 64);

            // Erstellen und direkt in den Vektor des Levels schieben
            auto newRock = std::make_shared<game::Sprite>(x, y, rockTex);
            myLevel.sprites_.push_back(newRock);
        }

        // Update bewegt alle Sprites in myLevel.sprites_
        myLevel.Update();

        BeginDrawing();
        ClearBackground(WHITE);
        myLevel.drawAll();
        EndDrawing();
    }
}