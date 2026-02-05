#include "Blume.h"

// Wurzel: 5.0, Farbe: Gelb, Samen: 0.5
Blume::Blume() : Pflanze(5.0, "Gelb", 0.5, "Blume") {}

double Blume::berechneWuchshoehe(double t) const {

    double hoehe = 0.05 * t;
    if (hoehe > 2.0) return 2.0; // Eine Blume wird hier maximal 2 Meter hoch
    return hoehe;
}