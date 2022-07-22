#include "sa_tekstom.h"
#include "oznaka.h"
#include "lista.h"

int main() {
	{
		try {
			Korisnik k1("Pedja", "pp200023d@student.etf.bg.ac.rs");
			Korisnik k2("Milica", "gm210004d@student.ff.bg.ac.rs");

			ElPoruka* p1 = new SaTekstom(&k1, &k2, "Poruka dobrodoslice");
			cout << *p1;
			delete p1;
		}
		catch (exception& e) {
			cout << e.what();
			cout << endl;
		}
	}
	_CrtDumpMemoryLeaks();
}