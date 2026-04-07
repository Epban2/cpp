
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

template <class T> class Matrix2x2 {
	T matrix[2][2];
public:
	Matrix2x2() : matrix{} {};
	Matrix2x2(T v1, T v2, T v3, T v4) {
		matrix[0][0] = v1; matrix[0][1] = v2;
		matrix[1][0] = v3; matrix[1][1] = v4;
	}

	Matrix2x2<T>& Add(const Matrix2x2& x2) {
		this->matrix[0][0] += x2.matrix[0][0];
		this->matrix[0][1] += x2.matrix[0][1];
		this->matrix[1][0] += x2.matrix[1][0];
		this->matrix[1][1] += x2.matrix[1][1];
		return *this; //Ritorno un riferimento così da non dover copiare l'oggetto in memoria
	}

	friend ostream& operator << (ostream& os, const Matrix2x2& m) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				os << m.matrix[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
};

#endif