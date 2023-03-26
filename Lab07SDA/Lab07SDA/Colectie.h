#pragma once
#include <climits>
#include <utility>
using namespace std;

#define VID INT_MIN;

typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {

	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	int cp;

	/*TElem* e;*/

	/*int* stanga;
	int* dreapta;*/

	//int radacina;
	int primLiber;

	//pentru redimensionare
	void redim();

	//functii pentru alocarea/dealocarea unui spatiu liber
	//se returneaza pozitia unui spatiu liber in lista
	int aloca();

	//dealoca spatiul de indice i
	void dealoca(int i);

	int adauga_rec(int p, TElem e);

	//int sterge_rec(int p, TElem elem);
	pair<int, int> sterge_rec(pair<int, int> pp, TElem elem);

	//functie privata care creeaza un nod in lista inlantuita
	int creeazaNod(TElem elem);
public:
	TElem* e;
	int* stanga;
	int* dreapta;
	int radacina;
	
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;


	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();
};