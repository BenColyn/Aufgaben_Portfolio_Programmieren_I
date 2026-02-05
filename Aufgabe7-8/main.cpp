#include "Sprite.hpp"


#include "Level.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Portfolio 2025 - Aufgabe 8");
    SetTargetFPS(60);

    game::Level myLevel;
    // Vor der Schleife die Textur EINMAL laden
    Texture2D rockTex = LoadTexture("resources/stein.png");

    // Teil b: 20 Sprites in einer for-Schleife erstellen
    for (int i = 0; i < 20; ++i) {
        // Wir übergeben die fertige Textur 'rockTex' statt des Pfades:
        auto newSprite = std::make_shared<game::Sprite>(0, 0, rockTex);
        myLevel.sprites_.push_back(newSprite);
    }

    // Zufällig positionieren
    myLevel.positionRandomly();

    while (!WindowShouldClose()) {
        // Teil c: Update Methode
        myLevel.Update();

        BeginDrawing();
        ClearBackground(WHITE);

        // Teil b: Zeichnen über die Levelklasse
        myLevel.drawAll();

        DrawText("Kollision = Löschen", 10, 10, 20, BLUE);
        EndDrawing();
    }

    UnloadTexture(rockTex); // Erst hier ganz am Ende löschen!
    CloseWindow();
    return 0;
}