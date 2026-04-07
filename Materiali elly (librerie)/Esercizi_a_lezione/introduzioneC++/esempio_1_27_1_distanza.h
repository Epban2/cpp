#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
using namespace std;

class Distanza {
private:
    int metri;
    int centimetri;

public:

    Distanza(int m = 0, int c = 0) {
        metri = m;
        centimetri = c;
    }

    bool operator <(Distanza d);

    int getmetri() { return metri; }
    int getcentimetri() { return centimetri; }
};

ostream& operator<<(ostream& os, Distanza op);

#endif