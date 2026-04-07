#include <string>
#pragma once

using namespace std;
class Person
{
public:
	Person();
	Person(string nome, string cognome, int anni);
	string getFullName();
	int getAnni();
	string informazioni();
	bool operator > (const Person& p2);
private:
	string nome, cognome;
	int anni;
};

