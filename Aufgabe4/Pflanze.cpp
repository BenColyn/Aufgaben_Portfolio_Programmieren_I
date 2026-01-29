#include "Pflanze.h"

Pflanze::Pflanze(double w, std::string f, double s, std::string n)
    : wurzelLaenge(w), blattFarbe(f), samenDurchmesser(s), name(n) {}

void Pflanze::generiereAusgabe(double t) const {
    double hoehe = berechneWuchshoehe(t);
    std::cout << "Die durchschnittliche Wuchshoehe des " << name
              << "s betraegt " << hoehe << " Meter." << std::endl;
}