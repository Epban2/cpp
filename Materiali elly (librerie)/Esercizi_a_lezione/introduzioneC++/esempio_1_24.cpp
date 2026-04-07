// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string nome;
  string cognome;
  int matricola;

  ifstream myfile ("elenco.txt");
  if (myfile.is_open())
  {
	while (myfile >> nome >> cognome >> matricola )
    {
      cout << nome << " " << cognome << " "<< matricola << endl;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
  system("pause");
  return 0;
}