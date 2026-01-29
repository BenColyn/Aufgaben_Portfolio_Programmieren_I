#include "Gras.h"

// Wurzel: 2.0, Farbe: Gruen, Samen: 0.1
Gras::Gras() : Pflanze(2.0, "Gruen", 0.1, "Gras") {}

double Gras::berechneWuchshoehe(double t) const {
    return 0.05 * t;
}