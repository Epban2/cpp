#include "esercitazione2-es2.h"

int main()
{
  Persona persone[3];
  Persona p1("Mario", "Rossi", 37);
  Persona p2("Paolino", "Paperino", 25);
  Persona p3("Archimede", "Pitagorico", 40);

  cout << p1.getInformation() << endl;
  cout << p2.getInformation() << endl;
  cout << p3.getInformation() << endl;

  persone[0] = p1;
  persone[1] = p2;
  persone[2] = p3;

  for (int i=0; i<3; i++)
  {
   persone[i].setcognome("Bianchi");
   cout << persone[i].getInformation() << endl;
  }

  cout << endl;
  return 1;
}