#include "Sprite.hpp"

namespace game {

    // Implementierung 1: Textur wird von außen übergeben
    Sprite::Sprite(int pos_x, int pos_y, Texture2D texture)
        : pos_x_(pos_x), pos_y_(pos_y), texture_(texture) {
    }

    // Implementierung 2: Textur wird anhand des Pfads geladen
    Sprite::Sprite(int pos_x, int pos_y, const std::string& fileName)
        : pos_x_(pos_x), pos_y_(pos_y) {
        texture_ = LoadTexture(fileName.c_str());
    }

    // Destruktor: Wichtig für das VRAM-Management
    Sprite::~Sprite() {
        UnloadTexture(texture_);
    }

    void Sprite::Draw() const {
        DrawTexture(texture_, pos_x_, pos_y_, WHITE);
    }

} // namespace game