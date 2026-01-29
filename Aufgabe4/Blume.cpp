#include "Blume.h"

// Wurzel: 5.0, Farbe: Gelb, Samen: 0.5
Blume::Blume() : Pflanze(5.0, "Gelb", 0.5, "Blume") {}

double Blume::berechneWuchshoehe(double t) const {
    // Blumen wachsen linear, aber wir könnten hier z.B. eine Sättigung einbauen
    return 0.5 * t;
}