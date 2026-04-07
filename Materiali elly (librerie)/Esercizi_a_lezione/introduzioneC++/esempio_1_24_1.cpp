// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

int main () {
  string str;
  string nome;
  string cognome;
  string matricola;

  ifstream myfile ("elenco_sep.txt");
  if (myfile.is_open())
  {
	while (getline(myfile, nome, '|'))
    {
      getline(myfile, cognome, '|');
      getline(myfile, str);
	  istringstream token(str);
	  token >> matricola;
      cout << nome << " " << cognome << " "<< matricola << endl;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}