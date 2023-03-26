#include <iostream>
#include "Colectie.h"
#include "IteratorColectie.h"
#include "TestExtins.h"
#include "TestScurt.h"
using namespace std;

void creeazaColectie(Colectie& c) {
	c.adauga(2);
	c.adauga(4);
	c.adauga(2);
	c.adauga(5);
	c.adauga(4);
	c.adauga(4);
	c.adauga(4);
	c.adauga(1);
	c.adaugaAparitiiMultiple(7, 3);
	c.adaugaAparitiiMultiple(8, 4);
	c.sterge(2);
	c.sterge(2);
	c.sterge(1);
	cout << c.dim() << endl;
}

void tiparesteColectie(const Colectie& c) {
	int anterior = 0;
	IteratorColectie it = c.iterator();
	it.ultimul();
	while (it.valid()) {
		if (anterior != it.element())
			cout << it.element() << ' ' << it.frecventa() << '\n';
		anterior = it.element();
		//it.urmator();
		it.anterior();
	}
}

/*
Sa  se  implementeze  în  C++  un anumit container  de  date(TAD)
folosind  o  anumita reprezentare (indicata) si o lista inlantuita
(LSI –lista simplu inlantuita, LDI –lista dublu inlantuita) ca structura
de date, cu reprezentarea inlantuirilor pe tablou dinamic.
*/

/*
4.TAD Colectie–reprezentare folosind o LDI cu perechi de forma (element, frecventa).
*/

int main() {
	//int vector[5] = {0, 2, 4, 7, 3};
	Colectie c;
	creeazaColectie(c);
	tiparesteColectie(c);
	testAll();
	testAllExtins();
	cout << "End";
}
