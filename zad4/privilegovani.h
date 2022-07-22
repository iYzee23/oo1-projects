#ifndef _privilegovani_h_
#define _privilegovani_h_

#include "tim.h"

class Privilegovani : public Tim {
private:
	void pisi(ostream& os) const override;

	double minVrednost;
public:
	Privilegovani(string naz, int n, double minvr) : Tim(naz, n), minVrednost(minvr) {}

	Privilegovani& dodaj(Igrac* igr, int i) override;
};

#endif // !_privilegovani_h_