#ifndef STRAUCH_H
#define STRAUCH_H

#include "Pflanze.h"

class Strauch : public Pflanze {
public:
    Strauch();

    double berechneWuchshoehe(double t) const override;
};

#endif