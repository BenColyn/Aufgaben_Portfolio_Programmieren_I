//
// Created by benco on 27.01.2026.
//

#include "MyCppArrayB.h"

#include <iterator>
#include <random>

#include "MyCppArray.h"


//Konstruktor:
MyCppArrayB::MyCppArrayB(int size) : size(size) {
    data = new int[size]; // 'new' fordert Speicher vom System
}

//Destruktor:
MyCppArrayB::~MyCppArrayB() {
    delete[] data; // Gibt den reservierten Speicher wieder
}

int MyCppArrayB::getSize() const {
    return size;
}
// Dynamische Größenänderung
void MyCppArrayB::resize(int newSize) {
    delete[] data; // Alten Speicher löschen
    size = newSize; // Neue Größe setzen
    data = new int[size]; // Neuen Speicher reservieren
}
// Automatische Zufallswerte
void MyCppArrayB::fillWithRandom(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    for (int i = 0; i < size; i++) {
        data[i] = dis(gen);
    }
}
// Sucht Min
int MyCppArrayB::getSmallestvalue() const {
    int smallest = data[0]; // Erstes Element ist das kleinste
    for (int i = 1; i < size; i++) {
        if (data[i] < smallest) {
            smallest = data[i]; // neuer kleinerer Wert
        }
    }
    return smallest;
}

// Sucht Max
int MyCppArrayB::getBiggestvalue() const {
    int biggest = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > biggest) {
            biggest = data[i];
        }
    }
    return biggest;
}
// Lineare Suche nach einem Wert
int MyCppArrayB::getindex(int search) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == search) {
            return i; //Position zurückgeben, wenn gefunden
        }
    }
    return -1;
}
