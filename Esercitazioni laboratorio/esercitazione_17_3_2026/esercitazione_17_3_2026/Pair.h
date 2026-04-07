#ifndef PAIR_H
#define PAIR_H

template<class T> class Pair {
private:
	T obj[2];
public:
	Pair() : obj() {}//Valore predefinito

	Pair(T first, T second) {
		obj[0] = first; obj[1] = second;
	}
	void set_element(int position, T value) {
		obj[position] = value;
	}
	T get_element(int position) const {
		return obj[position];
	}
	void add_up(const Pair<T>& the_pair) { /* somma gli elementi corrispondenti di un oggetto Pair con quelli contenuti nell’argomento the_pair*/
		obj[0] += the_pair.get_element(0);
		obj[1] += the_pair.get_element(1);
	}
};

#endif