#include "Baum.h"

// Wurzel: 5.0, Farbe: Gelb, Samen: 0.5
Baum::Baum() : Pflanze(5.0, "Gelb", 0.5, "Baum") {}

double Baum::berechneWuchshoehe(double t) const {

        double hoehe = 0.2 * t;
        if (hoehe > 30.0) return 30.0; // Ein Baum wird hier maximal 30 Meter hoch
        return hoehe;
    }
