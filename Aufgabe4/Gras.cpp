#include "Gras.h"

// Wurzel: 2.0, Farbe: Gruen, Samen: 0.1
Gras::Gras() : Pflanze(2.0, "Gruen", 0.1, "Gras") {}

double Gras::berechneWuchshoehe(double t) const {
    double hoehe = 0.01 * t;
    if (hoehe > 0.5) return 0.5; // Gras wird hier maximal 0.5 Meter hoch
    return hoehe;
}