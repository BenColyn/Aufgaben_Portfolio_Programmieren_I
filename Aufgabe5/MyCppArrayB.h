

#ifndef TESTPROJEKT_MYCPPARRAYB_H
#define TESTPROJEKT_MYCPPARRAYB_H


class MyCppArrayB {
private:
    const int size;
    int *data;
public:
    MyCppArrayB(int size);
    ~MyCppArrayB();
    // Verhindert die Verwendung des Standard-Konstruktors
    MyCppArrayB() = delete;
    int getSize();
    int getindex(int search);

};


#endif //TESTPROJEKT_MYCPPARRAYB_H