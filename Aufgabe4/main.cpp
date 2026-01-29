#include <iostream>
#include <limits>
#include <string>
#include <ctime>

// Deine Header
#include "Baum.h"
#include "Blume.h"
#include "Strauch.h"
#include "Gras.h"

// Hilfsfunktion zur Validierung
double holeGueltigeZeit() {
    double t;
    while (true) {
        if (std::cin >> t && t >= 0) {
            return t;
        } else {
            std::cout << "Fehler: Bitte eine positive Zahl eingeben: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

void pflanzenMenue() {
    std::cout << "\n--- Pflanzen-Informationssystem ---" << std::endl;
    std::cout << "Hier koennen Informationen zu Pflanzen abgefragt werden." << std::endl;
    std::cout << "Waehlen Sie eine Pflanzenart (1: Baum, 2: Blume, 3: Strauch, 4: Gras): ";

    int wahl;
    // Schleife stellt sicher, dass nur 1-4 eingegeben wird
    while (!(std::cin >> wahl) || wahl < 1 || wahl > 4) {
        std::cout << "Ungueltige Wahl! Bitte 1-4 eingeben: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    // --- ÄNDERUNG: Zeitabfrage NACH der korrekten Wahl ---
    std::cout << "Wie viel Zeit (t) soll fuer das Wachstum berechnet werden?" << std::endl;
    std::cout << "Eingabe: ";
    double t = holeGueltigeZeit();

    Pflanze* p = nullptr;
    if (wahl == 1) p = new Baum();
    else if (wahl == 2) p = new Blume();
    else if (wahl == 3) p = new Strauch();
    else if (wahl == 4) p = new Gras();

    if (p != nullptr) {
        p->generiereAusgabe(t);
        delete p; // Speicher freigeben
    }
}

int main() {
    // Initialisierung
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // --- Aufruf der fertigen Funktion ---
    pflanzenMenue();

    std::cout << "\nProgramm beendet. Vielen Dank!" << std::endl;
    return 0;
}