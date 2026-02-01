#ifndef TESTPROJEKT_MYCPPARRAY_H
#define TESTPROJEKT_MYCPPARRAY_H

class MyCppArray {
private:
    // Eine Hilfsmethode, um Zufallszahlen zu generieren
    int getrandomnumber(int min, int max);

    // 'static constexpr' bedeutet: Die Größe 100 steht schon beim Kompilieren fest
    static constexpr int size = 100;

public:
    // Das eigentliche Datenfeld mit fester Größe von 100 Elementen
    int data[100];

    // Findet die Position (Index) eines gesuchten Wertes
    int getindex(int search);

    // Sucht den kleinsten Wert im Array
    int getSmallestvalue();

    // Sucht den größten Wert im Array
    int getBiggestvalue();

    // Gibt die fest definierte Größe (100) zurück
    int getSize();

    // Der Konstruktor: Er wird aufgerufen, wenn 'MyCppArray a;' erstellt wird
    MyCppArray();
};

#endif
