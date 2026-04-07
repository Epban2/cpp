#include <iostream> 
#include <map> 
#include <set>
using namespace std;


bool Find_nome(map<int, set<string> >& pren_map, int spettacolo, string nome) {
	map<int, set<string> >::iterator iter = pren_map.find(spettacolo);
	if (iter == pren_map.end()) return false;
	set<string>::iterator iter1 = (*iter).second.find(nome);
	return (iter1 != (*iter).second.end());
}


int main()
{
	map<int, set<string> > prenotazioni;

	set <string> spettacolo1;
	spettacolo1.insert("nome1");
	spettacolo1.insert("nome2");
	spettacolo1.insert("nome3");
	int numero_spettacolo1 = 123;

	set <string> spettacolo2;
	spettacolo2.insert("nome4");
	spettacolo2.insert("nome8");
	spettacolo2.insert("nome5");
	int numero_spettacolo2 = 5;

	set <string> spettacolo3;
	spettacolo3.insert("nome41");
	spettacolo3.insert("nome80");
	spettacolo3.insert("nome500");
	int numero_spettacolo3 = 18;

	prenotazioni.insert(std::pair<int, set<string> >(numero_spettacolo1,spettacolo1)); //map.insert(std::pair<key_type, value_type>(key, value));
	prenotazioni.insert(std::pair<int, set<string> >(numero_spettacolo2, spettacolo2));
	prenotazioni.insert(std::pair<int, set<string> >(numero_spettacolo3, spettacolo3));

	cout << "nome8 in spettacolo2= " << Find_nome(prenotazioni, numero_spettacolo2, "nome8");
	cout << endl;
	cout << "nome50 in spettacolo3= " << Find_nome(prenotazioni, numero_spettacolo3, "nome50");

	return 0;
}