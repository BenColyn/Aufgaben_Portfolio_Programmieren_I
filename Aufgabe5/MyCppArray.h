#include <iostream>
#include <algorithm> // Für std::fill (optional)
#include <limits>    // Für Min/Max Initialisierung


class MyCppArray {
private:
    int getrandomnumber(int min, int max);

    static constexpr int size = 100;

public:
    int data[100]; // Feste Größe von 100
    int getindex(int search);

    int getSmallestvalue();

    int getBiggestvalue();

    int getSize();

    MyCppArray();


};
