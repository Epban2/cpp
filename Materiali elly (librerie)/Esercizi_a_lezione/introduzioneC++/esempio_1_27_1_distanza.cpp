#include "esempio_1_27_1_distanza.h"

bool Distanza::operator <(Distanza d) {
	if (metri < d.metri) {
		return true;
	}
	if ((metri == d.metri) && (centimetri < d.centimetri)) {
		return true;
	}

	return false;
}

ostream& operator<<(ostream& os, Distanza op)
{
	os << op.getmetri() << " " << op.getcentimetri();

	return os;
}
