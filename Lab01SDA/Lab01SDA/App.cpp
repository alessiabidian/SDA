#include <iostream>
#include "Colectie.h"
#include "IteratorColectie.h"
#include "TestExtins.h"
#include "TestScurt.h"
using namespace std;

/*
5.TAD Colectie–reprezentare secventiala folosind perechi de forma (element, frecventa).
Spre  exemplu, colectia [5, 10, -1, 2, 3, 10, 5, 5, -5] va fi reprezentata
sub forma [(5, 3) (10, 2) (-1, 1) (2, 1) (3, 1) (-5, 1)].
*/

void creare(Colectie& c) {
	for (int i = 1; i <= 6; i++)
		c.adauga(i);
	for (int i = 3; i <= 6; i++)
		c.adauga(i);
	for (int i = 4; i <= 9; i++)
		c.adauga(i);
}

void tiparire(Colectie& c) {
	IteratorColectie i = c.iterator();
	i.prim();
	while (i.valid()) {
		cout << i.element() << ' ';
		i.urmator();
	}
}

int main() {
	testAll();
	testAllExtins();
	Colectie c;
	creare(c);
	tiparire(c);

	cout << "End";
}