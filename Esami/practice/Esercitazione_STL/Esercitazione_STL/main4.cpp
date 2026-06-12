#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

bool Find_terno(map<string, set<int> >& lotto, string ruota, int n1, int n2, int n3)
{
	map<string, set<int>>::iterator it = lotto.find(ruota);
	if (it == lotto.end()) {
		cout << "Citta non presente";
		return false;
	}

	set<int> lookingfor;
	lookingfor.insert(n1); lookingfor.insert(n2); lookingfor.insert(n3);

	set<int> numbers = it->second;
	if (numbers.find(n1) != numbers.end() && numbers.find(n2) != numbers.end() && numbers.find(n3) != numbers.end())
		return true;
	return false;
}


int main() {
	map<string, set<int> > lotto;

	typedef pair<string, set<int>> obj;

	ifstream file("lotto.txt");
	if (file.is_open()) {
		string nomeruota;
		int n1, n2, n3, n4, n5;
		while (file >> nomeruota >> n1 >> n2 >> n3 >> n4 >> n5) {
			set<int> numset;
			numset.insert(n1); numset.insert(n2); numset.insert(n3); numset.insert(n4); numset.insert(n5);
			lotto.insert(obj(nomeruota, numset));
		}
	}
	file.close();

	cout << (Find_terno(lotto, "Firenze", 11, 12, 13) ? "E' terno!" : "Non e' terno") << endl;
	cout << (Find_terno(lotto, "Milano", 46, 84, 3) ? "E' terno!" : "Non e' terno") << endl;

	return 0;
}

