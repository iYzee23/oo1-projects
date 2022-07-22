#ifndef _mec_h_
#define _mec_h_

#include "par.h"
#include "tim.h"

enum Ishod {POBEDA_DOMACIN, NERESENO, POBEDA_GOST};

class Mec {
private:
	void brisi();
	void kopiraj(const Mec& m);
	void premesti(Mec& m);

	Par<Tim> timovi;
	Ishod ishod;
	bool odigran = false;
	Par<int> poeni;
public:
	Mec(Tim* t1, Tim* t2) : timovi(t1, t2), poeni(nullptr, nullptr) {}
	Mec(const Mec& m);
	Mec(Mec&& m);
	Mec& operator=(const Mec& m);
	Mec& operator=(Mec&& m);
	~Mec();

	Par<Tim>& getParTimova() { return timovi; }
	const Par<Tim>& getParTimova() const { return timovi; }
	Par<int>& getParPoena();
	friend ostream& operator<<(ostream& os, const Mec& m);

	void odigrajMec();
	bool odigranMec() const { return odigran; }
};

#endif // !_mec_h_