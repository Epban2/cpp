#include "esempio_1_27_1_distanza.h"


int main() {
    Distanza D1(11, 10), D2(5, 11);

    cout << "D1=" << D1 << endl;
    cout << "D2=" << D2 << endl;

    if (D1 < D2) {
        cout << "D1 is less than D2 " << endl;
    }
    else {
        cout << "D2 is less than D1 " << endl;
    }

    return 0;
}