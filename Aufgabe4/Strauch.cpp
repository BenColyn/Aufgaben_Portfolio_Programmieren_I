#include "Strauch.h"

// Wurzel: 20.0, Farbe: Hellgruen, Samen: 2.0
Strauch::Strauch() : Pflanze(20.0, "Hellgruen", 2.0, "Strauch") {}

double Strauch::berechneWuchshoehe(double t) const {
    return 0.8 * t;
}