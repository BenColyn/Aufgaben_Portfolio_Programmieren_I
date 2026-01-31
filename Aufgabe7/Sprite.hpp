#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "raylib.h"
#include <string>

namespace game {

    class Sprite {
    public:
        int pos_x_;
        int pos_y_;
        Texture2D texture_;

        // Standardkonstruktor deaktivieren
        Sprite() = delete;

        // Konstruktor mit bereits geladener Textur
        Sprite(int pos_x, int pos_y, Texture2D texture);

        // Konstruktor, der den Dateipfad entgegennimmt
        Sprite(int pos_x, int pos_y, const std::string& fileName);

        // Destruktor zum Entladen der Textur
        ~Sprite();

        // Hilfsmethode zum Zeichnen (optional, aber nützlich)
        void Draw() const;
    };

} // namespace game

#endif