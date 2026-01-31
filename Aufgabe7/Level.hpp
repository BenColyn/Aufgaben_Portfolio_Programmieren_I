#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "Sprite.hpp"
#include <vector>
#include <memory>

namespace game {

    class Level {
    public:
        // Teil a: Gefordertes Attribut
        std::vector<std::shared_ptr<game::Sprite>> sprites_;

        // Teil c: Speichert die Geschwindigkeit für jedes Sprite
        std::vector<Vector2> velocities_;

        // Teil a: Methode zum Zeichnen
        void drawAll() {
            for (auto& s : sprites_) {
                s->Draw();
            }
        }

        // Teil a & c: Zufällige Position und Startgeschwindigkeit
        void positionRandomly() {
            velocities_.clear();
            for (auto& s : sprites_) {
                s->pos_x_ = GetRandomValue(0, GetScreenWidth() - s->texture_.width);
                s->pos_y_ = GetRandomValue(0, GetScreenHeight() - s->texture_.height);

                // Zufällige Geschwindigkeit für Teil c
                float vx = (float)GetRandomValue(-200, 200) / 100.0f;
                float vy = (float)GetRandomValue(-200, 200) / 100.0f;
                velocities_.push_back({vx, vy});
            }
        }

        // Teil c: Update-Logik mit Kollisions-Erweiterung
        void Update() {
            // Wir nutzen ein Flag-System zum Löschen, um die Iteratoren nicht zu beschädigen
            std::vector<bool> toDelete(sprites_.size(), false);

            for (size_t i = 0; i < sprites_.size(); ++i) {
                // 1. Bewegung
                sprites_[i]->pos_x_ += (int)velocities_[i].x;
                sprites_[i]->pos_y_ += (int)velocities_[i].y;

                // 2. Abprallen an den Bildschirmrändern
                if (sprites_[i]->pos_x_ <= 0 ||
                    sprites_[i]->pos_x_ + sprites_[i]->texture_.width >= GetScreenWidth()) {
                    velocities_[i].x *= -1;
                }
                if (sprites_[i]->pos_y_ <= 0 ||
                    sprites_[i]->pos_y_ + sprites_[i]->texture_.height >= GetScreenHeight()) {
                    velocities_[i].y *= -1;
                }

                // 3. Erweiterung: Kollision (Sprites löschen sich gegenseitig)
                for (size_t j = i + 1; j < sprites_.size(); ++j) {
                    if (CheckCollision(i, j)) {
                        toDelete[i] = true;
                        toDelete[j] = true;
                    }
                }
            }

            // Markierte Sprites entfernen
            for (int i = sprites_.size() - 1; i >= 0; --i) {
                if (toDelete[i]) {
                    sprites_.erase(sprites_.begin() + i);
                    velocities_.erase(velocities_.begin() + i);
                }
            }
        }

    private:
        // Hilfsmethode für Rechteck-Kollision
        bool CheckCollision(size_t idx1, size_t idx2) {
            Rectangle r1 = {(float)sprites_[idx1]->pos_x_, (float)sprites_[idx1]->pos_y_,
                            (float)sprites_[idx1]->texture_.width, (float)sprites_[idx1]->texture_.height};
            Rectangle r2 = {(float)sprites_[idx2]->pos_x_, (float)sprites_[idx2]->pos_y_,
                            (float)sprites_[idx2]->texture_.width, (float)sprites_[idx2]->texture_.height};
            return CheckCollisionRecs(r1, r2);
        }
    };

} // namespace game

#endif