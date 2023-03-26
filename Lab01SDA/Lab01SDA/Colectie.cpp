#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


Colectie::Colectie() {
	//setam capacitatea
	this->cp = 1;

	//alocam spatiu de memorare pt vectorul de elemente
	e = new TElem[cp];

	//alocam spatiu de memorare pt vectorul de frecvente
	f = new TElem[cp];

	//setam numarul de elemente
	this->n = 0;
}
//theta(1)

void Colectie::redim() {
	//alocam un spatiu de capacitate dubla
	TElem* eNou = new int[2 * cp];
	TElem* fNou = new int[2 * cp];

	//copiem vechile valori in zona noua
	for (int i = 0; i < n; i++)
	{
		eNou[i] = e[i];
		fNou[i] = f[i];
	}

	//dublam capacitatea
	cp = 2 * cp;

	//eliberam vechea zona
	delete[] e;
	delete[] f;

	//vectorul indica spre noua zona
	e = eNou;
	f = fNou;
}
//theta(n)


void Colectie::adauga(TElem elem) {
	//daca s-a atins capacitatea maxima, redimensionam
	//if (n == cp)
		//redim();

	//adaugam la sfarsit elementul
	//this->e[n++] = elem;
	int index = 0;
	bool gasit = false;
	while (not gasit && index < this->n) {
		if (this->e[index] == elem)
			gasit = true;
		else
			index++;
	}

	if (not gasit)
	{
		if (n == cp)
			redim();

		this->e[n] = elem;
		this->f[n] = 1;
		this->n++;

	}
	else
		this->f[index]++;

}
//Caz Favorabil:theta(1), Caz Defavorabil:theta(n), Caz Mediu:theta(n)
//n - nr de elemente distincte

bool Colectie::sterge(TElem elem) {
	/*int gasit = 0, i = 0;
	while (i < n && gasit == 0)
	{
		if (e[i] == elem)
		{
			gasit = 1;
			for (int j = i; j < n - 1; j++)
				e[j] = e[j + 1];
			n--;
		}
		i++;
	}
	return gasit;
	*/
	int index = 0;
	bool gasit = false;
	while (not gasit && index < this->n) {
		if (this->e[index] == elem)
			gasit = true;
		else
			index++;
	}

	if (not gasit)
		return false;
	else
	{
		if (this->f[index] == 1)
		{
			this->e[index] = this->e[n - 1];
			this->f[index] = this->f[n - 1];
			this->n--;
		}
		else
			this->f[index]--;

		return true;
	}	
}
//Caz Favorabil:theta(1), Caz Defavorabil:theta(n), Caz Mediu:theta(n)

bool Colectie::cauta(TElem elem) const {
	for (int i = 0; i < n; i++)
		if (e[i] == elem)
			return true;
	return false;
}
//Caz Favorabil:theta(1), Caz Defavorabil:theta(n), Caz Mediu:theta(n)

int Colectie::nrAparitii(TElem elem) const {
	//int nraparitii = 0;
	for (int i = 0; i < n; i++)
		if (e[i] == elem)
			//nraparitii++;
			return this->f[i];
	//return nraparitii;
	return 0;
}
//Caz Favorabil:theta(1), Caz Defavorabil:theta(n), Caz Mediu:theta(n)

int Colectie::dim() const {
	int nr_de_elem = 0;
	for (int i = 0; i < n; i++)
		nr_de_elem += this->f[i];
	return nr_de_elem;
}
//theta(n)


bool Colectie::vida() const {
	
	if(this->n == 0)
		return true;
	return false;
}
//theta(1)

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}
//theta(1)


Colectie::~Colectie() {
	//eliberam zona de memorare alocata vectorului
	delete[] e;
	delete[] f;
}
//theta(1)