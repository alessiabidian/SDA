#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>
//#define NIL -1
#define NIL INT_MIN

void IteratorColectie::deplasare() {
	while ((curent < col.m) && col.e[curent] == NIL)
		curent++;
}
//caz fav: theta(1); caz defav: theta(m); caz total: O(m)

IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	/* de adaugat */
	curent = 0;
	deplasare();
}
//caz fav: theta(1); caz defav: theta(m); caz total: O(m)

void IteratorColectie::prim() {
	/* de adaugat */
	//se determina prima locatie ocupata
	curent = 0;
	deplasare();
}
//caz fav: theta(1); caz defav: theta(m); caz total: O(m)

void IteratorColectie::urmator() {
	/* de adaugat */
	if (!valid())
		throw std::exception();
	curent++;
	deplasare();
}
//caz fav: theta(1); caz defav: theta(m); caz total: O(m)

bool IteratorColectie::valid() const {
	/* de adaugat */
	return (curent < col.m);
}
//theta(1)

TElem IteratorColectie::element() const {
	/* de adaugat */
	if (!valid())
		throw std::exception();
	return col.e[curent];
}
//theta(1)