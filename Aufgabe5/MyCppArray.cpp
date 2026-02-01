#include <iostream>
#include "MyCppArray.h"
#include <random>

// Diese Methode erzeugt eine echte Zufallszahl für uns
int MyCppArray::getrandomnumber(int min, int max) {
    std::random_device rd;  // Liefert einen Seed (Startwert) von der Hardware
    std::mt19937 mt(rd());  // Der Zufallsgenerator (Mersenne-Twister)
    std::uniform_int_distribution<int> distrib(min, max); // Bereich festlegen

    return distrib(mt);     // Zufallszahl würfeln und zurückgeben
}

// Gibt einfach den Wert der Variable 'size' zurück
int MyCppArray::getSize() {
    return size;
}

// Der Konstruktor: Hier befüllen wir das Array direkt beim Start
MyCppArray::MyCppArray() {
    for (int i = 0; i < size; i++) {
        // Jede der 100 Stellen bekommt eine Zufallszahl zwischen 0 und 99
        data[i] = getrandomnumber(0, 99);
    }
}

// Geht das Array von vorne bis hinten durch (Lineare Suche)
int MyCppArray::getindex(int search) {
    for (int i = 0; i < size; i++) {
        if (data[i] == search) {
            return i; // Gefunden! Gib die Position zurück
        }
    }
    return -1; // Wenn die Schleife fertig ist und nichts gefunden wurde
}

// Sucht das Minimum
int MyCppArray::getSmallestvalue() {
    int smallest = data[0]; // Wir starten beim ersten Element
    for (int i = 1; i < size; i++) {
        if (data[i] < smallest) {
            smallest = data[i]; // Wir haben etwas Kleineres gefunden!
        }
    }
    return smallest;
}

// Sucht das Maximum
int MyCppArray::getBiggestvalue() {
    int biggest = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > biggest) {
            biggest = data[i];
        }
    }
    return biggest;
}