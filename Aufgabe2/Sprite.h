#ifndef SPRITE_H
#define SPRITE_H

#include <vector>

// Hilfsstruktur für x, y, z
struct Vector3 {
    float x, y, z;
};

// Frame als leere Struktur laut Vorgabe
struct Frame {};

enum class SpriteType { animate, character, object, character_animation };

struct Sprite {
    Vector3 position;
    bool drawable;
    unsigned int animationFrames;
    unsigned int width;
    unsigned int height;
    unsigned int currentFrame;
    Frame* frames; // Pointer auf Array oder Container
    SpriteType type;
};

#endif