#ifndef _sa_tekstom_h
#define _sa_tekstom_h_

#include "poruka.h"
#include "greska.h"

class SaTekstom : public ElPoruka {
private:
	void pisi(ostream& os) const override;

	string text = "";
public:
	SaTekstom(Korisnik* pos, Korisnik* prim, string nasl) : ElPoruka(pos, prim, nasl) {}

	void setText(string text);
	void posaljiPoruku() override;
	SaTekstom* kopija() const override;
};

#endif // !_sa_tekstom_h