#include "esercitazione2-es1.h"

int main()
{
 Libro l1;
 Libro l2("manuale", 200);

 cout << "l1:" << l1.gettitolo() << " " << l1.getpagine() << endl;
 l1.settitolo("Programmazione ad Oggetti");
 l1.setpagine(150);
 cout << "l1:" << l1.gettitolo() << " " << l1.getpagine() << endl;
 cout << "l2:" << l2.gettitolo() << " " << l2.getpagine() << endl;

 return 1;
}