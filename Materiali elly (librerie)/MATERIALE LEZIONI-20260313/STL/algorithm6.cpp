#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class clibro{
public:
 clibro(string t, string a, float p);
 string getTitolo() const {return titolo;};
 string getAutore(){return autore;};
 float getPrezzo(){return prezzo;};
 friend ostream& operator<<(ostream& output, const clibro& l);
 bool operator==(const clibro &t) const;

private:
 string titolo;
 string autore;
 float prezzo;
};

clibro::clibro(string t, string a, float p){
	titolo = t;
	autore = a;
	prezzo = p;
}

ostream& operator<<(ostream& output, const clibro& l){
 output << l.titolo << ' ' << l.autore << ' '<< l.prezzo << endl;
 return output;
};

bool clibro::operator==(const clibro &t) const{
 return (titolo== t.getTitolo());
};

bool ordT(clibro l1,clibro l2){return l1.getTitolo()<l2.getTitolo();};
bool ordP(clibro l1,clibro l2){return l1.getPrezzo()<l2.getPrezzo();};

void ordina(vector<clibro>& vl){
 int scelta;
 cout << "Ordina per titolo(1) o prezzo (2)" << endl;
 cin >> scelta;
 if(scelta==1)
  sort(vl.begin(),vl.end(),ordT);
 if(scelta==2)
  sort(vl.begin(),vl.end(),ordP);
};

void stampa(const vector<clibro>& vl) {
	vector<clibro>::const_iterator i;
	for (i = vl.begin(); i != vl.end(); i++)
		cout << *i;
};

int main()
{
 vector<clibro> vLibri;
 clibro libro1("autore1","titolo1",15.10);
 clibro libro2("autore2", "titolo2", 10.0);
 clibro libro3("autore3", "titolo3", 11.0);
 clibro libro4("autore4", "titolo4", 21.0);
 vLibri.push_back(libro1);
 vLibri.push_back(libro2);
 vLibri.push_back(libro3);
 vLibri.push_back(libro4);
 
 ordina(vLibri);
 stampa(vLibri);
 replace(vLibri.begin(), vLibri.end(), libro1, libro4);
 cout << "vLibri after replace:" << endl;
 stampa(vLibri);
 return 0;
}