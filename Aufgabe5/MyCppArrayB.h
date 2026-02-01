#ifndef TESTPROJEKT_MYCPPARRAYB_H
#define TESTPROJEKT_MYCPPARRAYB_H


class MyCppArrayB {
private:
    int size; // Speichert die aktuelle Anzahl der Elementet mehr!
    int *data; // Ein Zeiger auf den Speicherbereich, wo die Zahlen liegen
public:
    MyCppArrayB(int size); //Konstruktor
    ~MyCppArrayB(); //Destruktor

    // Features für Teil b)
    void fillWithRandom(int min, int max); //befüllt das Array
    void resize(int newSize); // ändert die aktuelle Größe zur Laufzeit

    // Features aus Teil a)
    int getSmallestvalue() const; //kleinster Wert
    int getBiggestvalue() const; //größter Wert
    int getindex(int search) const; //findet Position einer Zahl
    int getSize() const; //Gibt die aktuelle Größe zurück

    MyCppArrayB() = delete; //Verhindert, dass ein Array ohne Größe erstellt
};

#endif //TESTPROJEKT_MYCPPARRAYB_H
