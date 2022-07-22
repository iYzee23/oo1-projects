#ifndef _lista_h_
#define _lista_h_

#include <iostream>
#include <cmath>
#include <string>
#include "greska.h"
using namespace std;

template<typename T>
class Lista {
private:
	struct Elem {
		T info;
		Elem* next = nullptr;
		Elem(T& info) : info(info) {}
	};

	void brisi();
	void kopiraj(const Lista& l);
	void premesti(Lista& l);

	Elem* prvi = nullptr;
	Elem* posl = nullptr;
	int curr = 0;
public:
	Lista() = default;
	Lista(const Lista& l);
	Lista(Lista&& l);
	Lista& operator=(const Lista& l);
	Lista& operator=(Lista&& l);
	~Lista();

	Lista& operator+=(T& info);
	T& operator[](int i);
	const T& operator[](int i) const;
	int getBrElem() const { return curr; }
};

template<typename T>
inline Lista<T>::Lista(const Lista& l)
{
	kopiraj(l);
}

template<typename T>
inline Lista<T>::Lista(Lista&& l)
{
	premesti(l);
}

template<typename T>
inline Lista<T>& Lista<T>::operator=(const Lista& l)
{
	if (this != &l) {
		brisi();
		kopiraj(l);
	}
	return *this;
}

template<typename T>
inline Lista<T>& Lista<T>::operator=(Lista&& l)
{
	if (this != &l) {
		brisi();
		premesti(l);
	}
	return *this;
}

template<typename T>
inline Lista<T>::~Lista()
{
	brisi();
}

template<typename T>
inline Lista<T>& Lista<T>::operator+=(T& info)
{
	Elem* novi = new Elem(info);
	if (!prvi) prvi = novi;
	else posl->next = novi;
	posl = novi;
	curr++;
	return *this;
}

template<typename T>
inline T& Lista<T>::operator[](int i)
{
	if (i < 0 || i >= curr) throw GrLosIndex();
	Elem* tek = prvi;
	while (i--) tek = tek->next;
	return tek->info;
}

template<typename T>
inline const T& Lista<T>::operator[](int i) const
{
	if (i < 0 || i >= curr) throw GrLosIndex();
	Elem* tek = prvi;
	while (i--) tek = tek->next;
	return tek->info;
}

template<typename T>
inline void Lista<T>::brisi()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->next;
		delete stari;
	}
	prvi = nullptr;
	posl = nullptr;
	curr = 0;
}

template<typename T>
inline void Lista<T>::kopiraj(const Lista& l)
{
	curr = l.curr;
	prvi = nullptr;
	posl = nullptr;
	Elem* tekk = l.prvi;
	while (tekk) {
		Elem* novi = new Elem(tekk->info);
		if (!prvi) prvi = novi;
		else posl->next = novi;
		posl = novi;
		tekk = tekk->next;
	}
}

template<typename T>
inline void Lista<T>::premesti(Lista& l)
{
	curr = l.curr;
	prvi = l.prvi; l.prvi = nullptr;
	posl = l.posl; l.posl = nullptr;
}

#endif // !_lista_h_