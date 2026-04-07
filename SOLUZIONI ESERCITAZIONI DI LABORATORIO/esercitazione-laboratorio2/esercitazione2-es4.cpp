#include <fstream>
#include "esercitazione2-es4.h"

int main()
{
  Persona p1("Mario", "Rossi", 37);
  //Persona p2("Paolino", "Paperino", 25);
  Persona p2("Mario", "Rossi", 37);
  
  ofstream output("output.txt");

  if (p1 != p2)
	  output << "DIVERSI";
  else
	  output << "UGUALI";
  
  return 1;
}