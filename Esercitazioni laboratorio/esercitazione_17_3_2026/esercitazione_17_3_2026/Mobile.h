#ifndef MOBILE_H
#define MOBILE_H

class Mobile
{
private:
	int altezza, larghezza;
public:
	Mobile() {
		altezza = larghezza= 0;
	}
	int getAltezza() {
		return altezza;
	}
	int getLarghezza() {
		return larghezza;
	}
	void setAltezza(int altezza) {
		this->altezza = altezza;
	}
	void setLarghezza(int larghezza) {
		this->larghezza = larghezza;
	}
};

class Armadio : public Mobile {
private: 
	int num_ante;
public:
	Armadio(){
		num_ante = 0;
	}
	int getNumeroAnte() {
		return num_ante;
	}
	void setNumeroAnte(int num_ante) {
		this->num_ante= num_ante;
	}

};

#endif