//
// Created by benco on 23.01.2026.
//
#include <iostream>
#include "Wuerfelspiel.h"
#include <cstdlib> // Notwendig für srand() und rand()
#include <limits>
#include <ctime>

// Kurze Hilfsfunktionen (Platzhalter / Minimalimplementierung)


// --- Start Aufgabe 3 ---
int main() {
    // 1. Zufallsgenerator einmalig starten
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 2. Initialisierung (Aufgabe 3.4 & 3.6)
    gameStartInfo();
    int punkteSpieler = 0;
    int punkteComputer = 0;
    int aktuelleAugen =0;
    char status = 'y'; // Datentyp für Spielerstatus (Aufgabe 3.5)

    // Erster Würfel-Check (Aufgabe 3.2)
    std::cout << "Mit wie vielen Augen moechten Sie starten? ";
    while (!(std::cin >> aktuelleAugen) || aktuelleAugen <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bitte eine positive ganze Zahl eingeben: ";
    }

    // 3. Die Spielschleife (Aufgabe 3.5)
    while (status == 'y' || status == 'Y') {

        // --- Würfel wechseln (Aufgabe 3.7) ---
        char wechselWunsch;
        std::cout << "\nMoechten Sie die Wuerfel vor dem Wurf wechseln? (y/n): ";
        std::cin >> wechselWunsch;

        if (wechselWunsch == 'y' || wechselWunsch == 'Y') {
            std::cout << "Neue Anzahl der Augen eingeben: ";
            while (!(std::cin >> aktuelleAugen) || aktuelleAugen <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Bitte eine positive ganze Zahl eingeben: ";
            }
        }

        // 4. Runde spielen (Aufgabe 3.3)
        spielRunde(aktuelleAugen, punkteSpieler, punkteComputer);

        // Punktestand anzeigen
        std::cout << "Punktestand -> Spieler: " << punkteSpieler
                  << " | Computer: " << punkteComputer << std::endl;

        // 5. Weiterspielen oder Aufhören? (Aufgabe 3.5)
        std::cout << "\nNoch eine Runde spielen? (y/n): ";
        std::cin >> status;
    }


    // Ende des Spiels
    std::cout << "\nDas Spiel ist beendet. Endstand: " << punkteSpieler << ":" << punkteComputer << std::endl;
    if (punkteSpieler > punkteComputer) std::cout << "Glueckwunsch, du hast das Match gewonnen!" << std::endl;
    else if (punkteComputer > punkteSpieler) std::cout << "Der Computer hat gewonnen. Viel Erfolg beim naechsten Mal!" << std::endl;
    else std::cout << "Unentschieden!" << std::endl;

    return 0;
}