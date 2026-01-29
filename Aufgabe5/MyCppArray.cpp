#include <iostream>
#include "MyCppArray.h"
#include <algorithm> // Für std::fill (optional)
#include <limits>    // Für Min/Max Initialisierung
#include "random"

int MyCppArray::getrandomnumber(int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> distrib(min, max);
    return distrib(mt);
}

int MyCppArray::getSize() {
    return (size);
}

MyCppArray::MyCppArray() {
    for (int i = 0; i < size; i++)
        data[i] = getrandomnumber(0, 99); //To do: min und max auslagern
}
