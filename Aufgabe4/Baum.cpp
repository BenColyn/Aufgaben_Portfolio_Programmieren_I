#include "Baum.h"

// Wurzel: 5.0, Farbe: Gelb, Samen: 0.5
Baum::Baum() : Pflanze(5.0, "Gelb", 0.5, "Baum") {}

double Baum::berechneWuchshoehe(double t) const {
    // Blumen wachsen linear, aber wir könnten hier z.B. eine Sättigung einbauen
    return 0.2 * t;
}