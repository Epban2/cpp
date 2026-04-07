#include <iostream>
#include <string>
#include <list>
using namespace std;
class alunno{
public:
 string getMatricola(){return matr;};
 string getNome(){return nome;};
 void putNuovo(string mt, string nm)
  {matr=mt;nome=nm;};
private:
 string matr;
 string nome;
};

void main(){
 list<alunno> elenco;
 alunno temp;
 string m,n;
 // inserisce alunni in elenco
 while(true){
  cout << "Matricola alunno ";
  getline(cin,m);
  if(m=="")
   break;
  cout << "Nome alunno ";
  getline(cin,n);
  temp.putNuovo(m,n);
  elenco.push_back(temp);
 }
 for (list<alunno>::iterator it= elenco.begin(); it != elenco.end(); it++) {
	 cout << (*it).getNome() << " ";
 };
 cout << endl;
}