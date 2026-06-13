#ifndef ITEM_H
#define ITEM_H
# include <iostream>
#include <string>
using namespace std;

class Nave {
private:
	string nome;
	string compagnia;
	int passeggeri;
	float velocita;
public:
	Nave(string n = string(), int p = int(), float v = float(), string c = string())
	{
		nome = n;
		compagnia = c;
		passeggeri = p;
		velocita = v;
	}


	string key() const { return compagnia; }
	string getnome() const { return nome; }
	int getpasseggeri() const { return passeggeri; }
	float getvelocita() const { return velocita; }

	void setVelocita(float v) { velocita = v; }
	void setPasseggeri(int p) { passeggeri = p; }
	void setNome(string n) { nome = n; }

	void show(ostream& os = cout)
	{
		os << "(" << nome << "," << passeggeri << "," << velocita << "," << compagnia << ") ";
	}

};


// Let us print out Items easily
inline ostream& operator<<(ostream& s, const Nave& i)
{
	return s << "(" << i.getnome() << "," << i.getpasseggeri() << "," << i.getvelocita() << "," << i.key() << ") ";

}


#endif // !ITEM_H
