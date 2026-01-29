
#ifndef BLUME_H
#define BLUME_H

#include "Pflanze.h"

class Blume : public Pflanze {
public:
    Blume();

    double berechneWuchshoehe(double t) const override;
};

#endif
