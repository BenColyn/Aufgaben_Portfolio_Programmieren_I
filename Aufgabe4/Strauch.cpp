#include "Strauch.h"

// Wurzel: 20.0, Farbe: Hellgruen, Samen: 2.0
Strauch::Strauch() : Pflanze(20.0, "Hellgruen", 2.0, "Strauch") {}

double Strauch::berechneWuchshoehe(double t) const {
    double hoehe = 0.25 * t;
    if (hoehe > 6.0) return 6.0; // Strauch wird hier maximal 4 Meter hoch
    return hoehe;
}