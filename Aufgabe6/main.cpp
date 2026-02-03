#include "BaseCar.h"
#include <iostream>
#include <limits>

void printMenu() {
    std::cout << "\n--- Fahrzeugsteuerung ---\n";
    std::cout << "1. Motor starten\n";
    std::cout << "2. Beschleunigen (Vorwärts)\n";
    std::cout << "3. Bremsen\n";
    std::cout << "4. Links abbiegen\n";
    std::cout << "5. Rechts abbiegen\n";
    std::cout << "6. Rückwärts fahren\n";
    std::cout << "7. Motor stoppen\n";
    std::cout << "0. Programm beenden\n";
    std::cout << "Aktion wählen: ";
}

int main() {
    std::shared_ptr<car::BaseCar> spCar = nullptr;
    int choice = 0;

    std::cout << "Verfügbare konkrete Autos:\n";
    std::cout << "(1) Sportwagen (Karbon, V8, Keramikbremsen)\n";
    std::cout << "(2) Schwerlaster (Stahl, Diesel, Trommelbremsen)\n";
    std::cout << "Welches Auto soll auf dem Heap erstellt werden? ";
    std::cin >> choice;

    if (choice == 1) {
        spCar = std::make_shared<car::SportsCar>();
    } else {
        spCar = std::make_shared<car::HeavyTruck>();
    }

    std::cout << "\n[Info] Benutzer hat einen " << spCar->getModelName() << " auf dem Heap erstellt.\n";

    int action = -1;
    while (action != 0) {
        printMenu();
        if (!(std::cin >> action)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (action) {
            case 1: spCar->startEngine(); break;
            case 2: spCar->accelerateForward(3.0f); break; // Simuliert 3 Sek. Gas
            case 3: spCar->brake(); break;
            case 4: spCar->turnLeft(); break;
            case 5: spCar->turnRight(); break;
            case 6: spCar->accelerateBackward(2.0f); break;
            case 7: spCar->stopEngine(); break;
            case 0: std::cout << "Programm beendet.\n"; break;
            default: std::cout << "Ungültige Aktion.\n";
        }
    }

    return 0;
}