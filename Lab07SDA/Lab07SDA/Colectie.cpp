#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>
#include <utility>

using namespace std;

bool rel(TElem e1, TElem e2) {
	/* de adaugat */
	//return false;
	return e1 <= e2;
}

int Colectie::aloca() {
	//se sterge primul element din lista spatiului liber
	int i = primLiber;
	primLiber = stanga[primLiber];
	return i;
}
//theta(1)

void Colectie::dealoca(int i) {
	//se trece pozitia i in lista spatiului liber
	stanga[i] = primLiber;
	primLiber = i;
}
//theta(1)

void Colectie::redim() {
	//alocam un spatiu de capacitate dubla
	TElem* eNou = new TElem[2 * cp];
	int* stNou = new int[2 * cp];
	int* drNou = new int[2 * cp];

	//copiem vechile valori in zona noua
	for (int i = 0; i < cp; i++)
	{
		eNou[i] = e[i];
		stNou[i] = stanga[i];
		drNou[i] = dreapta[i];
	}

	int cp_anterior = cp;

	//dublam capacitatea
	cp = 2 * cp;

	//eliberam vechea zona
	delete[] e;
	delete[] stanga;
	delete[] dreapta;

	//vectorul indica spre noua zona
	e = eNou;
	stanga = stNou;
	dreapta = drNou;

	for (int i = cp_anterior; i < cp - 1; i++)
	{
		e[i] = VID; 
		stanga[i] = i + 1;
		dreapta[i] = -1;
	}
	stanga[cp - 1] = -1; e[cp - 1] = VID; dreapta[cp - 1] = -1;//!!!!!!!!!!!!!

	primLiber = cp_anterior;
}
//theta(cp), cp - capacitatea veche a tabloului dinamic

//creeaza un nod in lista inlantuita unde se memoreaza informatia utila e
int Colectie::creeazaNod(TElem elem) {
	//daca s-ar folosi vector dinamic, s-ar redimensiona in cazul in care colectia ar fi plina (primLiber=0)
	if (primLiber == -1)
		redim();
	int i = aloca();
	if (i != -1) {//exista spatiu liber in lista
		this->e[i] = elem;
		stanga[i] = -1;
		dreapta[i] = -1;
	}
	return i;
}
//caz favorabil: theta(1); caz defavorabil: theta(cp); caz total: O(cp)

Colectie::Colectie() {
	/* de adaugat */
	//setam capacitatea
	this->cp = 2;

	//alocam spatiu de memorare pt vectorul de elemente
	e = new TElem[cp];

	stanga = new int[cp];
	dreapta = new int[cp];

	//lista e vida
	radacina = -1;

	//se initializeaza lista spatiului liber - toate pozitiile din vector sunt marcate ca fiind libere
	for (int i = 0; i < cp - 1; i++)
	{
		e[i] = VID;
		stanga[i] = i + 1;
		dreapta[i] = -1;
	}
	stanga[cp - 1] = -1;
	dreapta[cp - 1] = -1; //!!!!!!!!!!!!!!!!!
	e[cp - 1] = VID;

	//referinta spre prima pozitie libera din lista
	primLiber = 0;
}
//theta(cp), cp - capacitatea tabloului dinamic, chiar theta(1) (intra in for o sg data)

//adaugare recursiva a unui element
int Colectie::adauga_rec(int p, TElem elem) {
	if (p == -1)
	{
		p = creeazaNod(elem);
	}
	else {
		//if (elem <= e[p]) //se adauga in stanga
		if(rel(elem, e[p]))
			stanga[p] = adauga_rec(stanga[p], elem);
		else //se adauga in dreapta
			dreapta[p] = adauga_rec(dreapta[p], elem);
	}
	return p;
}

void Colectie::adauga(TElem e) {
	/* de adaugat */
	radacina = adauga_rec(radacina, e);
}


pair<int, int> Colectie::sterge_rec(pair<int, int> pp, TElem elem) {

	int prep = pp.first, p = pp.second;

	if(prep == -1 || p == -1)
		return std::make_pair(-1, -1);

	TElem curent_elem = this->e[p];
	if (this->e[p] == elem)
		return std::make_pair(prep, p);
	else
		if (rel(elem, curent_elem))
			return sterge_rec(std::make_pair(p, this->stanga[p]), elem);
		else
			return sterge_rec(std::make_pair(p, this->dreapta[p]), elem);

}


bool Colectie::sterge(TElem elem) {
	/* de adaugat */
	if (radacina == -1)
		return false;//nu avem nmc 

	pair<int, int> indexes = sterge_rec(make_pair(radacina, radacina), elem);
	int index_anterior = indexes.first, index = indexes.second;

	if (index == -1) //nu l am gasit
		return false;
	else
	{
		if (stanga[index] == -1 && dreapta[index] == -1) //e frunza
		{
			if (index == radacina) //modificam radacina
				radacina = -1;
			e[index] = VID;
			dealoca(index);
		}
		else if (stanga[index] == -1 && dreapta[index] != -1) //are un copil drept
		{
			
			if (stanga[index_anterior] == index)
				stanga[index_anterior] = dreapta[index];
			else if (dreapta[index_anterior] == index)
				dreapta[index_anterior] = dreapta[index];

			if (index_anterior == index && index == radacina) //modificam radacina
				radacina = dreapta[index];

			stanga[index] = -1;
			dreapta[index] = -1;
			e[index] = VID;

			dealoca(index);
		}
		else if (stanga[index] != -1 && dreapta[index] == -1) //are un copil stang
		{

			if (stanga[index_anterior] == index)
				stanga[index_anterior] = stanga[index];
			else if (dreapta[index_anterior] == index)
				dreapta[index_anterior] = stanga[index];

			if (index_anterior == index && index == radacina) //modificam radacina
				radacina = stanga[index];

			stanga[index] = -1;
			dreapta[index] = -1;
			e[index] = VID;
			dealoca(index);
		}
		else { //are si fiu stang, si fiu drept
				int current_index = dreapta[index];
				int current_index_anterior = index;
				while (current_index != -1 && stanga[current_index] != -1 && e[stanga[current_index]] != INT_MIN)
				{
					current_index_anterior = current_index;
					current_index = stanga[current_index];
				}

				e[index] = e[current_index];

				if (dreapta[current_index] != -1) //nodul mutat cel mai apropiat de cel sters avea fiu drept
				{
					if (stanga[current_index_anterior] == current_index)
						stanga[current_index_anterior] = dreapta[current_index];
					else if (dreapta[current_index_anterior] == current_index)
						dreapta[current_index_anterior] = dreapta[current_index];

					stanga[current_index] = -1;
					dreapta[current_index] = -1;
					e[current_index] = VID;
					dealoca(current_index);
				}
				else { //ii frunza
					e[current_index] = VID;
					dealoca(current_index);
				}
		}
		//dealoca(index); //marim spatiul liber

		return true;
	}
}

//bool Colectie::cauta(TElem elem) const {
//	/* de adaugat */
//	for (int i = 0; i < cp; i++)
//		if (e[i] == elem)
//			return true;
//	return false;
//};

bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
	int p = radacina;
	while (p != -1 && e[p] != elem)
	{
		if (elem < e[p])
			p = stanga[p];
		else //if (elem > e[p])
			p = dreapta[p];
	}
	
	if(p != -1 && e[p] == elem)
			return true;
	return false;
};

int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
	int nr = 0;
	for (int i = 0; i < cp; i++)
		if (e[i] == elem)
			nr++;
	return nr;
}


int Colectie::dim() const {
	/* de adaugat */
	int nr_de_elem = 0;

	for (int i = 0; i < cp; i++)
		if (e[i] != INT_MIN)
		{
			//cout << e[i] << " ";
			nr_de_elem++;
		}

	return nr_de_elem;
}


bool Colectie::vida() const {
	/* de adaugat */
	if(radacina == -1)
		return true;
	return false;
}


IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	delete[] e;
	delete[] stanga;
	delete[] dreapta;
}
