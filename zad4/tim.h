#ifndef _tim_h_
#define _tim_h_

#include "igrac.h"
#include "greska.h"

class Tim {
protected:
	void brisi();
	void kopiraj(const Tim& t);
	void premesti(Tim& t);

	virtual void pisi(ostream& os) const;

	string naziv;
	int n;
	Igrac** igraci = nullptr;
public:
	Tim(string naz, int n) : naziv(naz), n(n), igraci(new Igrac*[n]()) {}
	Tim(const Tim& t);
	Tim(Tim&& t);
	Tim& operator=(const Tim& t);
	Tim& operator=(Tim&& t);
	virtual ~Tim();

	Igrac* operator[](int i);
	const Igrac* operator[](int i) const;
	friend bool operator==(const Tim& t1, const Tim& t2);
	friend bool operator!=(const Tim& t1, const Tim& t2);
	friend ostream& operator<<(ostream& os, const Tim& t);

	virtual Tim& dodaj(Igrac* igr, int i);
	int getBrIgraca() const;
	double getVrednostTima() const;
};

#endif // !_tim_h_