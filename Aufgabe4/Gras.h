#ifndef GRAS_H
#define GRAS_H

#include "Pflanze.h"

class Gras : public Pflanze {
public:
    Gras();

    double berechneWuchshoehe(double t) const override;
};

#endif