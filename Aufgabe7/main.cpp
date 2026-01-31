#include "Sprite.hpp"

int main() {
    InitWindow(800, 600, "Raylib Sprite Test");

    // Nutzung des Pfad-Konstruktors
    game::Sprite myCharacter(100, 100, "resources/character.png");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        myCharacter.Draw();

        EndDrawing();
    }

    // Beim Verlassen des Scopes wird der Destruktor von myCharacter
    // automatisch aufgerufen und die Textur entladen.
    CloseWindow();
    return 0;
}