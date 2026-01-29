#ifndef PFLANZE_H
#define PFLANZE_H

#include <string>
#include <iostream>

class Pflanze {
protected:
    double wurzelLaenge;
    std::string blattFarbe;
    double samenDurchmesser;
    std::string name;

public:
    Pflanze(double w, std::string f, double s, std::string n);
    virtual ~Pflanze() {}

    // Die geforderte Methode zur Berechnung (t ist die Zeit)
    virtual double berechneWuchshoehe(double t) const = 0;

    // Methode für die geforderte Benutzerausgabe
    void generiereAusgabe(double t) const;
};

#endif