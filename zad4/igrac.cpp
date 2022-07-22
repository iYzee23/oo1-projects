#include "igrac.h"

void Igrac::promeniVrednost(double procenat)
{
	double promena = 1 + procenat / 100;
	vrednost *= promena;
}

bool operator==(const Igrac& i1, const Igrac& i2)
{
	return (i1.ime == i2.ime) && (i1.vrednost == i2.vrednost);
}

bool operator!=(const Igrac& i1, const Igrac& i2)
{
	return !(i1 == i2);
}

ostream& operator<<(ostream& os, const Igrac& i)
{
	return os << i.ime << "#" << i.vrednost;
}
