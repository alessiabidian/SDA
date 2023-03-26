#include <iostream>
#include "Colectie.h"
#include "IteratorColectie.h"
#include "TestExtins.h"
#include "TestScurt.h"
#include <limits>
using namespace std;

void creeazaColectie(Colectie& c) {
	c.adauga(2);
	c.adauga(5);
	c.adauga(12);
	c.adauga(25);
	c.adauga(2);
	c.adauga(15);
	c.adauga(25);
	c.adauga(79);
	c.adauga(69);
	c.adauga(96);
	c.adauga(14);
	c.adauga(12);
	c.adauga(25);
	c.adauga(2);
	c.adauga(2);
	c.adaugaAparitiiMultiple(3, 100);
}

void tiparesteColectie(const Colectie& c) {
	IteratorColectie it = c.iterator();
	while (it.valid()) {
		TElem e = it.element();
		cout << e << endl;
		it.urmator();
	}
	cout << "Dimensiunea: " << c.dim() << endl;
}
/*
5.TAD Colectie–reprezentare memorand toate elementele,
folosind o TD cu rezolvare coliziuni prin adresare deschisa, dispersia dubla.
*/
int main() {
	testAll();
	testAllExtins();
	Colectie c;
	creeazaColectie(c);
	tiparesteColectie(c);

	cout << "End";
}
