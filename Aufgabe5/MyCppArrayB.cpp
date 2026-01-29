//
// Created by benco on 27.01.2026.
//

#include "MyCppArrayB.h"

#include <iterator>

#include "MyCppArray.h"

MyCppArrayB::MyCppArrayB(int size) : size(size) {
    data = new int[size];
}

MyCppArrayB::~MyCppArrayB() {
    delete[] data;
}

int MyCppArrayB::getSize() {
    return size;
}

int MyCppArrayB::getindex(int search) {
    for (int i = 0; i < size; i++) {
        if (data[i] == search) {
            return i;
        }
    }
    return -1;
}
