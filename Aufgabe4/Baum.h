#ifndef BAUM_H
#define BAUM_H

#include "Pflanze.h"

class Baum : public Pflanze {
public:
    // Der Konstruktor (setzt die Standardwerte für Baum)
    Baum();

    // Die überschriebene Methode zur Berechnung
    double berechneWuchshoehe(double t) const override;
};

#endif