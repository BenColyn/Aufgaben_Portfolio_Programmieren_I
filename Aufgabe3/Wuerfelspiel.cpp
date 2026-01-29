//
// Created by benco on 23.01.2026.
//

#include "Wuerfelspiel.h"
#include <iostream>
#include <cstdlib> // Für rand() und srand()
#include <ctime>   // Für time()

// Hilfsfunktion: Informiert den Spieler (Aufgabe 3.4)
void gameStartInfo() {
    std::cout << "--- Willkommen beim Wuerfelspiel ---" << std::endl;
    std::cout << "Regeln: Du und der Computer wuerfelt gleichzeitig." << std::endl;
    std::cout << "Wer die hoehere Zahl hat, gewinnt die Runde." << std::endl;
    std::cout << "Viel Erfolg!\n" << std::endl;
}

// Funktion simuliert den Wurf (Aufgabe 3.1)
int wuerfeln(int augen) {
    // rand() % augen gibt 0 bis (augen-1), daher +1
    return (std::rand() % augen) + 1;
}

// Führt eine Runde durch und ermittelt Gewinner (Aufgabe 3.3 & 3.6)
// Wir nutzen Referenzen (&), um die Punkte im Hauptprogramm zu aktualisieren
void spielRunde(int augen, int& spielerPunkte, int& computerPunkte) {
    int wurfSpieler = wuerfeln(augen);
    int wurfComputer = wuerfeln(augen);

    std::cout << "\nDu hast eine " << wurfSpieler << " gewuerfelt." << std::endl;
    std::cout << "Der Computer hat eine " << wurfComputer << " gewuerfelt." << std::endl;

    if (wurfSpieler > wurfComputer) {
        std::cout << "Gewonnen! Punkt fuer dich." << std::endl;
        spielerPunkte++;
    }
    else if (wurfComputer > wurfSpieler) {
        std::cout << "Der Computer gewinnt diese Runde." << std::endl;
        computerPunkte++;
    }
    else {
        std::cout << "Unentschieden! Keine Punkte." << std::endl;
    }
}