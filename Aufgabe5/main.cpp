#include <iostream>
#include "MyCppArray.h"   // Die statische Klasse (Teil a)
#include "MyCppArrayB.h"  // Die dynamische Klasse (Teil b)

int main() {
    // --- DEMONSTRATION TEIL A (Statisch) ---
    std::cout << "=== TEIL A: Statisches Array ===" << std::endl;
    MyCppArray statischesArray; // Erstellt ein Objekt mit festen 100 Elementen

    std::cout << "Groesse von Teil A: " << statischesArray.getSize() << std::endl;
    std::cout << "Max-Wert in Teil A: " << statischesArray.getBiggestvalue() << std::endl;
    // Da der Konstruktor von MyCppArray das Array automatisch füllt,
    // können wir direkt Werte abfragen.

    std::cout << "\n----------------------------------\n" << std::endl;

    // --- DEMONSTRATION TEIL B (Dynamisch) ---
    std::cout << "=== TEIL B: Dynamisches Array ===" << std::endl;

    // 1. Erster Durchlauf: Wir bestimmen die Größe selbst (z.B. 10)
    MyCppArrayB dynamischesArray(10); //
    dynamischesArray.fillWithRandom(1, 50); // Automatisch befüllen

    std::cout << "Durchlauf 1 - Groesse: " << dynamischesArray.getSize() << std::endl;
    std::cout << "Durchlauf 1 - Min-Wert: " << dynamischesArray.getSmallestvalue() << std::endl;

    // 2. Zweiter Durchlauf: Das GLEICHE Objekt wird in der Größe angepasst (Aufgabe 5b.2)
    std::cout << "\nAnpassung: Resize auf 5 Elemente..." << std::endl;
    dynamischesArray.resize(2); // Alter Speicher wird gelöscht, neuer reserviert
    dynamischesArray.fillWithRandom(100, 120); // Neu befüllen mit anderen Werten

    std::cout << "Durchlauf 2 - Neue Groesse: " << dynamischesArray.getSize() << std::endl;
    std::cout << "Durchlauf 2 - Neuer Max-Wert: " << dynamischesArray.getBiggestvalue() << std::endl;

    // Suche nach einem Wert (Feature aus Teil a, erhalten in Teil b)
    int gesucht = 111;
    int pos = dynamischesArray.getindex(gesucht); //
    if (pos != -1) {
        std::cout << "Wert " << gesucht << " gefunden an Index: " << pos << std::endl;
    } else {
        std::cout << "Wert " << gesucht << " nicht im neuen Array vorhanden." << std::endl;
    }

    return 0;
    // Hier werden die Destruktoren aufgerufen.
    // Bei MyCppArrayB wird 'delete[] data' ausgeführt.
}