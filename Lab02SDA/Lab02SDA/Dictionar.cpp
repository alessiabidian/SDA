#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"

//adaugate dupa
Nod::Nod(TElem e, PNod urm) {
	this->e = e;
	this->urm = urm;
}
//theta(1)

TElem Nod::element() {
	return e;
}

PNod Nod::urmator() {
	return urm;
}

Dictionar::Dictionar() {
	/* de adaugat */
	prim = nullptr;
	ultim = nullptr;
}
//theta(1)

Dictionar::~Dictionar() {
	/* de adaugat */
	//se elibereaza memoria alocata nodurilor listei
	while (prim != nullptr) {
		PNod p = prim;
		prim = prim->urm;
		delete p;
	}
}
//Caz favorabil:theta(1), Caz Defavorabil:theta(n), Caz Mediu:theta(n)
//n - nr de perechi din dictionar

TValoare Dictionar::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	PNod p = prim;
	while (p != nullptr) {
		if (p->e.first == c) { //daca exista deja cheia
			TValoare vechi = p->e.second;
			p->e.second = v;
			return vechi; //returneaza valoarea veche
		}
		p = p->urm;
	}

	TElem e;
	e.first = c;
	e.second = v;
	PNod q = new Nod(e, nullptr);
	q->urm = prim;
	prim = q;

	if (prim->urm == nullptr)
		ultim = prim;

	return NULL_TVALOARE;
}
//Caz favorabil:theta(1), Caz Defavorabil:theta(n), Caz Mediu:theta(n), total: O(n)
//n - nr de perechi din dictionar

//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare Dictionar::cauta(TCheie c) const {
	/* de adaugat */
	PNod p = prim;
	while (p != nullptr)
	{
		if (p->e.first == c)
			return p->e.second; //returneaza valoarea
		p = p->urm;
	}
	return NULL_TVALOARE;
}
//Caz favorabil:theta(1), Caz Defavorabil:theta(n), Caz Mediu:theta(n)
//n - nr de perechi din dictionar

TValoare Dictionar::sterge(TCheie c) {
	/* de adaugat */
	if(dim()>0)
	{
		if (prim->e.first == c)
		{
			PNod p = prim;
			TValoare v = prim->e.second;
			prim = prim->urm;
			delete p;

			if (prim == nullptr)
				ultim = nullptr;

			return v;
		}
		else {
			PNod q = prim;
			while (q->urm != nullptr)
			{
				if (q->urm->e.first == c) 
				{
					PNod p = q->urm;
					TValoare v = q->urm->e.second;
					if (q->urm == ultim) //daca e ultimul in lsi
						ultim = q;
						
					/*else
					{*/
						q->urm = p->urm;
					//}
					delete p;
					return v;
				}
				q = q->urm;
			}
		}
	}
	return NULL_TVALOARE;
}
//Caz favorabil:theta(1), Caz Defavorabil:theta(n), Caz Mediu:theta(n)
//n - nr de perechi din dictionar


int Dictionar::dim() const {
	/* de adaugat */
	int nr_elemente = 0;
	PNod p = prim;
	while (p != nullptr)
	{
		nr_elemente++;
		p = p->urm;
	}

	return nr_elemente;
}
//theta(n)

bool Dictionar::vid() const {
	/* de adaugat */
	/*if (dim() > 0)
		return false;
	return true;*/
	if (prim == nullptr)
		return true;
	return false;
}
//theta(1)


IteratorDictionar Dictionar::iterator() const {
	return  IteratorDictionar(*this);
}
//theta(1)