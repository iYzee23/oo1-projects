#include "posiljka.h"
#include "prodavac.h"

int main() {
	{
		Artikal a("Keks", 17, 150);
		Prodavac* r = new Prodavac("Pedja");
		r->dodajUKatalog(a, 0.8, 3);
		try {
			Posiljka pos(a);
			pos += r;
			cout << pos << endl;
			pos.izracunajDetalje();
			cout << pos.getDaniCekanja() << endl;
			cout << pos.getCena() << endl;
		}
		catch (exception& e) {
			cout << e.what();
			cout << endl;
		}
		delete r;
	}
	_CrtDumpMemoryLeaks();
}