#include <iostream> 
#include <map> 
#include <set>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;


bool Find_terno(map<string, set<int> >& lotto, string ruota, int n1, int n2, int n3) {
	map<string, set<int> >::iterator iter = lotto.find(ruota);
	if (iter == lotto.end()) return false;
	if ((*iter).second.find(n1) != (*iter).second.end() && ((*iter).second.find(n2) != (*iter).second.end()) && ((*iter).second.find(n3) != (*iter).second.end()))
		return true;
	else
		return false;
}


int main()
{
	map<string, set<int> > lotto;

	ifstream myfile("lotto.txt");

	string ruota;
	int n1, n2, n3, n4, n5;
	if (myfile.is_open()) {
		while (myfile >> ruota >> n1 >> n2 >> n3 >> n4 >> n5 ) {
			set <int> numeri_estratti;
			numeri_estratti.insert(n1);
			numeri_estratti.insert(n2);
			numeri_estratti.insert(n3);
			numeri_estratti.insert(n4);
			numeri_estratti.insert(n5);
			lotto.insert(std::pair<string, set<int> >(ruota, numeri_estratti));
		}
	}
	else
	{
		cout << "Errore di apertura del file" << endl;
		return -1;
	}
	myfile.close();

	cout << "terno (11,12,13) su ruota Firenze: " << Find_terno(lotto, "Firenze", 11,12,13);
	cout << endl;
	cout << "terno (46,84,3) su ruota Milano: " << Find_terno(lotto, "Milano", 46,84,3);

	return 0;
}