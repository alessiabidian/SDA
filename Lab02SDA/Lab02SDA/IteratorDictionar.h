#pragma once
#include "Dictionar.h"

class IteratorDictionar
{
	friend class Dictionar;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorDictionar(const Dictionar& d);

	//contine o referinta catre containerul pe care il itereaza
	const Dictionar& dict;
	PNod curent;
	PNod curent2;
	/* aici e reprezentarea specifica a iteratorului */

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	TElem element() const;

	//in plus
	void anterior();
	bool valid2() const;
	TElem element2() const;
	void anterior2();
	void revinoKpasi(int k);

};
