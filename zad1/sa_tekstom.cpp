#include "sa_tekstom.h"

void SaTekstom::pisi(ostream& os) const
{
	ElPoruka::pisi(os);
	os << text << endl;
}

void SaTekstom::setText(string text)
{
	if (stanje == POSLATA) throw GrVecPoslata();
	this->text = text;
}

void SaTekstom::posaljiPoruku()
{
	setStanje(POSLATA);
}

SaTekstom* SaTekstom::kopija() const
{
	return new SaTekstom(*this);
}
