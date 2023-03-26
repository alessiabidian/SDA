#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;
//constanta simbolica NIL indica o locatie libera in tabela
//consideram ca TElement este intreg
#include <climits>
#define NIL INT_MIN
#define STERS INT_MIN + 10

//functia care da <hashCode>-ul unui element
int hashCode(TElem e) {
	//ptr moment numarul e intreg
	return abs(e);
}
//theta(1)

//functia de dispersie dubla
int Colectie::d(TElem e, int i) {
	//return (hashCode(e) % m + i * (1 + hashCode(e) % (m - 2))) % m;
	unsigned long c1, c2;
	c1 = hashCode(e) % m;
	c2 = (1 + hashCode(e) % (m - 2)) % m;

	// (a+b)%m = (a%m + b%m)%m
	return int((c1 + (i * c2) % m) % m);
}
//theta(1)

Colectie::Colectie() {
	/* de adaugat */
	m = MAX; //initializam m cu o valoare predefinita

	//alocam spatiu de memorare pt vectorul de elemente
	e = new TElem[m];

	//daca va fi cazul, se poate redimensiona tabela si sa se redisperseze elementele
	//se marcheaza pozitiile din tabela ca fiind libere
	for (int i = 0; i < m; i++) {
		e[i] = NIL;
	}
}
//theta(m)

int prim(int nr)
{
	if (nr <= 1 || nr % 2 == 0)
		return 0;
	for (int d = 3; d * d <= nr; d=d+2)
		if (nr % d == 0)
			return 0;
	return 1;
}
//caz fav: theta(1); caz defav: theta([(sqrt(nr)-1)/2]); total: O(sqrt(nr))

void Colectie::redim() {
	int mvechi = m;
	m = m + 2;
	while (!prim(m))
		m = m + 2;

	//alocam un spatiu de capacitate dubla
	TElem* eNou = new int[m];
	TElem* copie = new int[mvechi];
	//copiem vechile valori in zona noua auxiliara
	for (int i = 0; i < mvechi; i++)
	{
		copie[i] = e[i];
	}

	//initializam vectorul nou
	for (int i = 0; i < m; i++) {
		eNou[i] = NIL;
	}

	//eliberam vechea zona
	delete[] e;
	//vectorul indica spre noua zona
	e = eNou;

	//dublam capacitatea/nr de locatii din tabela
	//m = 2 * m;
	
	//for (int i = 0; i < m/2; i++)
	for (int i = 0; i < mvechi; i++)
	{
		adauga(copie[i]);
	}

	delete[] copie;
}
//caz fav: theta(m), caz defav: theta(m^2), total: O(m^2)

void Colectie::adauga(TElem elem) {
	/* de adaugat */
	//locatia de dispersie a cheii
	int i = 0; //numarul de verificare
	bool gasit = false;
	do {
		int j = d(elem, i);
		if (e[j] == NIL || e[j] == STERS) {
			e[j] = elem;
			gasit = true;
		}
		else i++;
	} while (i < m && !gasit);
	if (i == m) {
		//depasire tabela
		//ar fi necesara redimensionare
		//cout << "Element: " << elem << "; Redimensionare pt: " << m << endl;
		redim();
		adauga(elem);
	}
}
//caz fav: theta(1), caz defav: theta(m^2) - din cauza redim, total: O(m^2)

bool Colectie::sterge(TElem elem) { 
	
	/*for (int i = 0; i < m; i++)
		if (e[i] == elem)
		{
			e[i] = STERS;
			return true;
		}
	return false;*/

	int i = 0; //numarul de verificare
	bool gasit = false;
	do {
		int j = d(elem, i);
		if (e[j] == NIL)
			break;
		if (e[j] == elem) {
			e[j] = STERS;
			gasit = true;
		}
		else i++;
	} while (i < m && !gasit);

	return gasit;
}
//caz fav: theta(1), caz defav: theta(m), total: O(m)

bool Colectie::cauta(TElem elem){ //const
	/* de adaugat */
	/*for (int i = 0; i < m; i++)
		if (e[i] == elem)
			return true;
	return false;*/
	int i = 0; //numarul de verificare
	bool gasit = false;
	do {
		int j = d(elem, i);
		if (e[j] == NIL)
			return false;
		if (e[j] == elem) {
			gasit = true;
		}
		else i++;
	} while (i < m && !gasit);
	return gasit;
}
//caz fav: theta(1), caz defav: theta(m), total: O(m)


int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
	int nrAparitii = 0;
	for (int i = 0; i < m; i++)
		if (e[i] == elem)
			nrAparitii++;
	return nrAparitii;
}
//theta(m)


int Colectie::dim() const {
	/* de adaugat */
	int nrElemente = 0;
	for (int i = 0; i < m; i++)
		if (e[i] != NIL && e[i] != STERS)
			nrElemente++;
	return nrElemente;
}
//theta(m)


bool Colectie::vida() const {
	/* de adaugat */
	if(dim()==0)
		return true;
	return false;
}
//theta(m)

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}
//theta(1)

Colectie::~Colectie() {
	/* de adaugat */
	delete[] e;
}
//theta(1)

// adauga nr aparitii ale elementului elem in colectie.
// arunca exceptie in cazul in care este nr este negativ.
void Colectie::adaugaAparitiiMultiple(int nr, TElem elem)
{
	if (nr < 0)
		throw exception();
	int i = 0; //numarul de verificare
	do {
		int j = d(elem, i);
		if (e[j] == NIL || e[j] == STERS) {
			e[j] = elem;
			nr--;
		}
		else i++;
	} while (i < m && nr!=0);
	if (i == m) {
		redim();
		adaugaAparitiiMultiple(nr, elem);
	}
	/*for (int i = 1; i <= nr; i++)
		adauga(elem);*/
}
// caz fav: theta(1) pt nr=1 si fara redim, caz defav: theta(nr+m^2), total: O(m^2)
// PSEUDOCOD
// daca nr < 0
//		arunca exceptie
// executa
//		j <- d(elem, i) valoarea de dispersie
//		daca e[j] == NIL sau e[j] == STERS atunci
//			e[j] <- elem
//			nr <- nr-1
//		altfel i <- i+1
// cat timp i<m si nr != 0
// 
// daca i==m atunci
//		redimensionam()
//		adaugaAparitiiMultiple(nr, elem) unde nr e nr de aparitii modificat
// sf alg
// 
// 
// 
// 
// Varianta 2
//pentru i=1, nr, pas=1 executa
//	adauga(elem)
