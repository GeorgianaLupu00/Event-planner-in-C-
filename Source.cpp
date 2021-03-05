#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <set>
#include <map>

using namespace std;


class Decoratiuni {

protected:
	int id_decoratiune;
	char* nume;
	float pret;
	bool stoc;

public:
	Decoratiuni() :id_decoratiune(0) {

		this->nume = new char[strlen("indisponibil") + 1];
		strcpy_s(this->nume, 13, "indisponibil");

		this->pret = 0;

		this->stoc = false;

	}

	void Reducere(int x) {
		float t = x * this->pret / 100;
		this->pret = this->pret - t;
		std::cout << "Decoratiunii " << nume << " i-a fost aplicata o reducere de " << x << "%. Noul pret este:" << pret;

	}
	Decoratiuni(char* nume, int id, bool stoc, float pret) :id_decoratiune(id) {

		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

		this->stoc = stoc;
		this->pret = pret;
	}

	Decoratiuni(int id) :id_decoratiune(id) {

		this->nume = new char[strlen("nume nou") + 1];
		strcpy_s(this->nume, 9, "nume nou");

		this->pret = 0;

		this->stoc = 0;
	}

	Decoratiuni(const Decoratiuni& dec) :id_decoratiune(dec.id_decoratiune) {

		this->nume = new char[strlen(dec.nume) + 1];
		strcpy_s(this->nume, strlen(dec.nume) + 1, dec.nume);

		this->pret = dec.pret;

		this->stoc = dec.stoc;

	}

	void setnume(char* nume) {
		if (this->nume != nullptr)
			delete[] this->nume;
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			for (int i = 0; i < strlen(nume); i++)
			{
				this->nume[i] = nume[i];
			}
			this->nume[strlen(nume)] = '\0';
		}
	}
	void setnume(const char* nume) {
		if (this->nume != nullptr)
			delete[] this->nume;
		if (nume != nullptr)
		{
			this->nume = new char[strlen(nume) + 1];
			for (int i = 0; i < strlen(nume); i++)
			{
				this->nume[i] = nume[i];
			}
			this->nume[strlen(nume)] = '\0';
		}
	}
	char* getnume() {
		return this->nume;
	}

	void setstoc(bool stoc) {
		this->stoc = stoc;
	}
	bool getstoc() {
		return this->stoc;
	}

	void setpret(float pret) {
		this->pret = pret;
	}
	float getpret() {
		return this->pret;
	}

	friend istream& operator>>(istream& in, Decoratiuni& d);
	friend ostream& operator<< (ostream& out, const Decoratiuni& d);

	Decoratiuni operator++()
	{
		pret++;
		return *this;
	}
	Decoratiuni operator--()
	{
		pret--;
		return *this;
	}
	// compara pretul dintre doua decoratiuni
	bool operator<= (const Decoratiuni& other)
	{
		if (this->pret <= other.pret)
			return true;
		else
			return false;
	}
	operator char* ()
	{
		return nume;
	}

	Decoratiuni operator+ (Decoratiuni& other)
	{
		return Decoratiuni(this->nume, this->id_decoratiune, this->stoc, this->pret + other.pret);
	}

	bool operator==(const Decoratiuni& other)
	{
		if (strcmp(nume, other.nume) != 0)
			return false;

		if (pret != other.pret)
			return false;

		if (stoc != other.stoc)
			return false;

	}

	~Decoratiuni() {

		if (this->nume != nullptr)
			delete[] this->nume;

	}

	Decoratiuni& operator= (const Decoratiuni& other)
	{
		nume = new char[strlen(other.nume) + 1];
		strcpy_s(nume, strlen(other.nume) + 1, other.nume);

		pret = other.pret;
		stoc = other.stoc;

		return *this;
	}

	Decoratiuni& operator+(float a) {

		this->pret = this->pret + a;
		return *this;
	}

	Decoratiuni& operator-(float a) {

		this->pret = this->pret - a;
		return *this;
	}

	bool operator< (const Decoratiuni& other)
	{
		if (this->pret < other.pret)
			return true;
		else
			return false;
	}

	bool operator> (const Decoratiuni& other)
	{
		if (this->pret > other.pret)
			return true;
		else
			return false;
	}

	bool operator>= (const Decoratiuni& other)
	{
		if (this->pret >= other.pret)
			return true;
		else
			return false;
	}

	int operator[](int i) {
		if (i >= 0 and this->pret > i)
			return this->nume[i];
		else
		{
			std::cout << "index out of range";
			return -1;
		}
	}
};

istream& operator>>(istream& in, Decoratiuni& d) {

	char aux[100];

	std::cout << "\n Introdu numele decoratiunii:";
	in.get(aux, 100);
	in.get();
	if (d.nume != nullptr)
		delete[]d.nume;
	d.nume = new char[strlen(aux) + 1];
	strcpy(d.nume, aux);

	std::cout << "\n Introdu pretul decoratiunii:";
	in >> d.pret;

	std::cout << "\n Decoratiune pe stoc (da/nu):";
	in >> d.stoc;

	return in;
}

ostream& operator<< (ostream& out, const Decoratiuni& d)
{
	out << d.nume << d.pret << d.stoc;
	for (int i = 0; i < d.pret; i++)
		out << d.nume[i];
	return out;
};

class DecoratiuneFlorala : public Decoratiuni
{
	string tip_flori;
	float diametru;

public:
	DecoratiuneFlorala()
		: Decoratiuni()
	{
		tip_flori = "";
		diametru = 0;
	}
	DecoratiuneFlorala(char* nume, int id, bool stoc, float pret, string tip_flori, float diametru)
		: Decoratiuni(nume, id, stoc, pret)
	{
		this->tip_flori = tip_flori;
		this->diametru = diametru;
	}
	DecoratiuneFlorala(const DecoratiuneFlorala& other)
		: Decoratiuni(other)
	{
		this->tip_flori = tip_flori;
		this->diametru = diametru;
	}
	DecoratiuneFlorala operator=(const DecoratiuneFlorala& other)
	{
		this->tip_flori = tip_flori;
		this->diametru = diametru;
		return *this;
	}
	~DecoratiuneFlorala()
	{
		tip_flori = "";
		diametru = 0;
	}
};
class Locatie {

private:
	int id_locatie;
	char* adresa;
	char* tip;
	double capacitate;
	int telefon;
	vector<Decoratiuni> decoratiuni;
public:

	Locatie() :id_locatie(0) {

		this->adresa = new char[strlen("anonima") + 1];
		strcpy_s(this->adresa, 8, "anonima");

		this->tip = new char[strlen("neidentificat") + 1];
		strcpy_s(this->tip, 14, "neidentificat");

		this->capacitate = 0;

		this->telefon = 0;

	}

	void Modificare(int id, char* a, double cap, int tel) {
		*this->adresa = *a;
		this->id_locatie = id;
		this->capacitate = cap;
		this->telefon = tel;
		std::cout << "Din cauza unui inconvenient, locatia evenimentului a fost schimbata. Noua adresa este: " << adresa;

	}

	Locatie(int id, char* adresa, char* tip, double capacitate, int telefon) :id_locatie(id)
	{

		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);

		this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);

		this->capacitate = capacitate;
		this->telefon = telefon;

	}

	Locatie(int id) :id_locatie(id) {

		this->adresa = new char[strlen("adresa noua") + 1];
		strcpy_s(this->adresa, 12, "adresa noua");

		this->tip = new char[strlen("tip nou") + 1];
		strcpy_s(this->tip, 8, "tip nou");

		this->capacitate = 0;

		this->telefon = 0;

	}

	Locatie(const Locatie& loc) :id_locatie(loc.id_locatie) {

		this->adresa = new char[strlen(loc.adresa) + 1];
		strcpy_s(this->adresa, strlen(loc.adresa) + 1, loc.adresa);

		this->tip = new char[strlen(loc.tip) + 1];
		strcpy_s(this->tip, strlen(loc.adresa) + 1, loc.tip);

		this->capacitate = loc.capacitate;

		this->telefon = loc.telefon;
	}

	~Locatie() {

		if (this->adresa != nullptr)
			delete[] this->adresa;
		if (this->tip != nullptr) {
			delete[]this->tip;
		}
		decoratiuni.clear();
	}

	Locatie& operator= (const Locatie& other) {

		adresa = new char[strlen(other.adresa) + 1];
		strcpy_s(adresa, strlen(other.adresa) + 1, other.adresa);

		tip = new char[strlen(other.tip) + 1];
		strcpy_s(tip, strlen(other.tip) + 1, other.tip);

		capacitate = other.capacitate;
		telefon = other.telefon;
		decoratiuni.clear();
		for (int i = 0; i < other.decoratiuni.size(); i++)
		{
			this->decoratiuni.push_back(other.decoratiuni[i]);
		}
		return *this;
	}

	friend istream& operator>>(istream& in, Locatie& l);
	friend ostream& operator<< (ostream& out, const Locatie& l);

	Locatie& operator++()
	{
		this->capacitate++;
		return *this;
	}

	Locatie& operator--()
	{
		this->capacitate--;
		return *this;
	}

	Locatie operator+ (Locatie& other)
	{
		return Locatie(this->id_locatie, this->adresa, this->tip, this->capacitate + other.capacitate, this->telefon);
	}

	bool operator<= (const Locatie& other)
	{
		if (this->capacitate <= other.capacitate)
			return true;
		else
			return false;
	}

	operator char* ()
	{
		return tip;
	}

	bool operator==(const Locatie& other)
	{
		if (strcmp(this->adresa, other.adresa) != 0)
			return false;

		if (strcmp(this->tip, other.tip) != 0)
			return false;

		if (this->capacitate != other.capacitate)
			return false;

		if (this->telefon != other.telefon)
			return false;
	}

	int operator[](int i) {
		if (i >= 0 and this->capacitate > i)
			return this->adresa[i];
		else
		{
			std::cout << "index out of range";
			return -1;
		}
	}
};

istream& operator>>(istream& in, Locatie& l) {

	char aux[100];

	std::cout << "\n Introdu adresa locatiei:";
	in.get(aux, 100);
	in.get();
	if (l.adresa != nullptr)
		delete[] l.adresa;
	l.adresa = new char[strlen(aux) + 1];
	strcpy_s(l.adresa, strlen(aux) + 1, aux);

	if (l.tip != nullptr)
		delete[] l.tip;
	l.tip = new char[strlen(aux) + 1];
	strcpy_s(l.tip, strlen(aux) + 1, aux);

	std::cout << "\n Introdu capacitatea locatiei:";
	in >> l.capacitate;

	std::cout << "\n Introdu numarul de telefon al locatiei:";
	in >> l.telefon;

	int nr_decoratiuni;
	std::cout << "\n Introdu numarul de decoratiuni";
	in >> nr_decoratiuni;
	for (int i = 0; i < nr_decoratiuni; i++)
	{
		Decoratiuni d;
		in >> d;
		l.decoratiuni.push_back(d);
	}
	return in;
};

ostream& operator<< (ostream& out, const Locatie& l)
{
	out << l.tip << ' ' << ' ' << l.adresa << ' ' << ' ' << l.capacitate << ' ' << l.telefon;
	out << l.adresa << ' ';
	for (int i = 0; i < l.decoratiuni.size(); i++)
	{
		out << l.decoratiuni[i] << ' ';
	}
	return out;
}

class Evenimente {

	//declarare variabile
protected:
	/*char* tip;*/
	int durata;
	bool finalizat;
	const char id_eveniment;
	char descriere[100];
	float suprafata_locatie;
	int* costuri;
	double capacitate;
	Locatie* locatie;

public:
	static int nr_evenimente;

	void input(string);
	void output(string);

	//constructor simplu
	Evenimente() : id_eveniment(0) {
		locatie = new Locatie();

		/*this->tip = new char[strlen("neidentificat") + 1];
		strcpy_s(this->tip, 14, "neidentificat");*/

		this->durata = 0;

		this->suprafata_locatie = 0;

		this->costuri = new int[this->durata];

		this->finalizat = false;

		this->capacitate = 0;

		//this->descriere = new char[strlen(descriere) + 1];

		strcpy_s(this->descriere, 6, "empty");

	}

	virtual string getTip() = 0;

	void Finalizare() {
		this->finalizat = 1;
		std::cout << "Evenimentul cu id-ul " << id_eveniment << " de tipul " << getTip() << " a fost finalizat cu succes!" << endl;
	}

	Evenimente(int durata, bool finalizat, const char id, char* descriere, float suprafata_locatie, int* costuri, double capacitate, Locatie locatie) :id_eveniment(id) {

		this->locatie = new Locatie(locatie);
		//this->tip = new char[strlen(tip) + 1];
		//strcpy_s(this->tip, strlen(tip) + 1, tip);

		this->durata = durata;
		this->costuri = new int[this->durata];
		for (int i = 0; i < this->durata; i++)
			this->costuri[i] = costuri[i];

		this->suprafata_locatie = suprafata_locatie;
		this->finalizat = finalizat;
		this->capacitate = capacitate;
		strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
		this->descriere[strlen(descriere)] = '\0';
	}

	Evenimente(int durata, bool finalizat, const char id, const char* descriere, float suprafata_locatie, int* costuri, double capacitate, Locatie locatie) :id_eveniment(id) {

		this->locatie = new Locatie(locatie);
		/*this->tip = new char[strlen(tip) + 1];
		strcpy_s(this->tip, strlen(tip) + 1, tip);*/

		this->durata = durata;
		this->costuri = new int[this->durata];
		for (int i = 0; i < this->durata; i++)
			this->costuri[i] = costuri[i];

		this->suprafata_locatie = suprafata_locatie;
		this->finalizat = finalizat;
		this->capacitate = capacitate;
		strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
		this->descriere[strlen(descriere)] = '\0';
	}

	Evenimente(char id) :id_eveniment(id) {
		locatie = new Locatie();
		/*this->tip = new char[strlen("tip nou") + 1];
		strcpy_s(this->tip, 8, "tip nou");*/

		this->durata = 0;

		this->costuri = new int[this->durata];

		this->suprafata_locatie = 0.0;

		this->capacitate = 0;

		this->finalizat = 0;

		strcpy_s(this->descriere, 6, "empty");
		this->descriere[5] = '\0';

	}

	Evenimente(const Evenimente& event) :id_eveniment(event.id_eveniment) {

		this->locatie = new Locatie(*(event.locatie));
		//this->tip = new char[strlen(event.tip) + 1];
		//strcpy_s(this->tip, strlen(event.tip) + 1, event.tip);

		this->durata = event.durata;

		this->costuri = new int[this->durata];
		for (int i = 0; i < this->durata; i++)
			this->costuri[i] = event.costuri[i];


		this->suprafata_locatie = event.suprafata_locatie;

		this->capacitate = event.capacitate;

		this->finalizat = event.finalizat;

		for (int i = 0; i < strlen(event.descriere); i++)
		{
			this->descriere[i] = event.descriere[i];
		}
		this->descriere[strlen(event.descriere)] = '\0';
	}

	~Evenimente() {
		if (this->locatie != NULL)
		{
			delete locatie;
		}
		//if (this->tip != NULL)
		//	delete[] this->tip;
		if (this->costuri != NULL) {

			delete[]this->costuri;
		}
		this->descriere[0] = '\0';
	}

	/*void settip(char* tip) {
		if (this->tip != nullptr)
			delete[] this->tip;
		if (tip != nullptr)
		{
			this->tip = new char[strlen(tip) + 1];
			for (int i = 0; i < strlen(tip); i++)
			{
				this->tip[i] = tip[i];
			}
			this->tip[strlen(tip)] = '\0';
		}
	}
	void settip(const char* tip) {
		if (this->tip != nullptr)
			delete[] this->tip;
		if (tip != nullptr)
		{
			this->tip = new char[strlen(tip) + 1];
			for (int i = 0; i < strlen(tip); i++)
			{
				this->tip[i] = tip[i];
			}
			this->tip[strlen(tip)] = '\0';
		}
	}
	char* gettip() {
		return this->tip;
	}*/

	void setdurata(int durata) {
		this->durata = durata;
	}
	int getdurata() {
		return this->durata;
	}

	void setfinalizat(bool finalizat) {
		this->finalizat = finalizat;
	}
	bool getfinalizat() {
		return this->finalizat;
	}

	void setdescriere(char* d) {

		strcpy_s(this->descriere, strlen(d) + 1, d);
	}

	string getdescriere() {

		return this->descriere;
	}

	void setsuprafata_locatie(float suprafata_locatie) {
		this->suprafata_locatie = suprafata_locatie;
	}
	float getsuprafata_locatie() {
		return this->suprafata_locatie;
	}

	void setcosturi(int* costuri) {
		if (this->costuri != nullptr)
			delete[] this->costuri;
		this->costuri = new int[this->durata];
		for (int i = 0; i < this->durata; i++)
		{
			this->costuri[i] = costuri[i];
		}
	}
	int* getcosturi() {
		return this->costuri;
	}

	void setcapacitate(double capacitate) {
		this->capacitate = capacitate;
	}
	double getcapacitate() {
		return this->capacitate;
	}


	Evenimente& operator= (const Evenimente& other) {
		if (this->locatie != NULL)
		{
			delete this->locatie;
		}
		this->locatie = new Locatie(*(other.locatie));
		//tip = new char[strlen(other.tip) + 1];
		//strcpy_s(tip, strlen(other.tip) + 1, other.tip);

		durata = other.durata;
		finalizat = other.finalizat;

		for (int i = 0; i < strlen(other.descriere); i++)
			descriere[i] = other.descriere[i];
		descriere[strlen(other.descriere)] = '\0';

		suprafata_locatie = other.suprafata_locatie;

		costuri = new int[durata];
		for (int i = 0; i < durata; i++)
		{
			costuri[i] = other.costuri[i];
		}

		capacitate = other.capacitate;
		return *this;
	}

	friend istream& operator>>(istream& in, Evenimente& e);
	friend ostream& operator<< (ostream& out, const Evenimente& e);

	Evenimente& operator++()
	{
		this->durata++;
		return *this;
	}

	Evenimente& operator--()
	{
		this->durata--;
		return *this;
	}

	// compara durata intre doua evenimente
	bool operator<= (const Evenimente& other)
	{
		if (durata <= other.durata)
			return true;
		else
			return false;
	}
	operator char* ()
	{
		return descriere;
	}

	//adauga costurile si duratele si returneaza un obiect nou cu duratele insumate si costurile concatenate	


	bool operator==(const Evenimente& other)
	{
		/*if (strcmp(tip, other.tip) != 0)
			return false;*/

		if (durata != other.durata)
			return false;

		if (finalizat != other.finalizat)
			return false;

		if (id_eveniment != other.id_eveniment)
			return false;

		if (strcmp(descriere, other.descriere) != 0)
			return false;

		if (suprafata_locatie != other.suprafata_locatie)
			return false;

		if (*locatie != *(other.locatie))
			return false;
		return true;
	}

	int operator[](int i) {
		if (i >= 0 and this->durata > i)
			return this->costuri[i];
		else
		{
			std::cout << "index out of range";
			return -1;
		}
	}


};

void Evenimente::input(string numeFisier)
{
	ifstream fin(numeFisier);

	fin >> *this;

	fin.close();
}

void Evenimente::output(string numeFisier) {

	ofstream fout(numeFisier);

	fout << *this;

	fout.close();
}

istream& operator>>(istream& in, Evenimente& e) {

	char aux[100];

	std::cout << "\n Introdu tipul evenimentului:";
	in.get(aux, 100);
	in.get();
	/*if (e.tip != nullptr)
		delete[] e.tip;
	e.tip = new char[strlen(aux) + 1];*/
	/*strcpy_s(e.tip, strlen(aux) + 1, aux);*/

	std::cout << "\n Introdu durata evenimentului:";
	in >> e.durata;

	std::cout << "\n Eveniment finalizat sau nefinalizat:";
	in >> e.finalizat;

	std::cout << "\n Introdu suprafata locatiei:";
	in >> e.suprafata_locatie;

	std::cout << "\n Introdu capacitatea:";
	in >> e.capacitate;

	std::cout << "\n Introdu descrierea evenimentului:";
	in >> e.descriere;

	std::cout << "\n Se citeste locatia:";
	in >> (*e.locatie);

	if (e.costuri != nullptr)
		delete[] e.costuri;
	e.costuri = new int[e.durata];

	std::cout << "\n Costurile:";
	for (int i = 0; i < e.durata; i++) {
		in >> e.costuri[i];
	}
	return in;
}

ostream& operator<< (ostream& out, const Evenimente& e)
{
	out << /*e.tip << ' ' << */ e.durata << ' ' << e.finalizat << ' ' << e.descriere << ' ' << e.suprafata_locatie << ' ';
	for (int i = 0; i < e.durata; i++)
		out << e.costuri[i] << ' ';
	out << e.capacitate << ' ';
	out << *(e.locatie) << '\n';
	return out;
}

class Nunta : public Evenimente
{
	string mire;
	string mireasa;
	string data_nuntii;
	string nas;
	string nasa;
public:
	Nunta()
		: Evenimente()
	{
		mire = mireasa = data_nuntii = nas = nasa = "";
	}
	Nunta(int durata, bool finalizat, const char id, char* descriere, float suprafata_locatie, int* costuri, Locatie locatie, double capacitate, string mire, string mireasa, string data_nuntii, string nas, string nasa)
		: Evenimente(durata, finalizat, id, descriere, suprafata_locatie, costuri, capacitate, locatie)
	{
		this->mire = mire;
		this->mireasa = mireasa;
		this->data_nuntii = data_nuntii;
		this->nas = nas;
		this->nasa = nasa;
	}

	Nunta(const Nunta& other)
		: Evenimente(other)
	{
		this->mire = mire;
		this->mireasa = mireasa;
		this->data_nuntii = data_nuntii;
		this->nas = nas;
		this->nasa = nasa;
	}

	Nunta operator=(const Nunta& other)
	{
		this->mire = mire;
		this->mireasa = mireasa;
		this->data_nuntii = data_nuntii;
		this->nas = nas;
		this->nasa = nasa;

		return *this;
	}

	~Nunta()
	{
		mire = mireasa = data_nuntii = nas = nasa = "";
	}

	string getTip()
	{
		return "Nunta";
	}
	Nunta operator+ (Nunta& other)
	{
		int* c = new int[durata + other.durata];
		int i = 0;
		for (; i < durata; i++)
		{
			c[i] = costuri[i];
		}
		for (i = 0; i < other.durata; i++)
		{
			c[durata + i] = other.costuri[i];
		}

		return Nunta(durata + other.durata, finalizat, id_eveniment, descriere, suprafata_locatie, c, *locatie, capacitate, mire, mireasa, data_nuntii, nas, nasa);
	}
};

class Organizator {

private:
	char* nume;
	int id_organizator;
	bool organizator;
	char sex;
	char specializare[100];
	float salariu;
	const double CNP;
	int* telefon;
public:
	static int nr_organizatori;

	Organizator() :CNP(0) {

		this->nume = new char[strlen("neidentificat") + 1];
		strcpy(this->nume, "neidentificat");

		this->sex = 0;

		this->telefon = new int[*this->nume];

		this->organizator = false;

		this->salariu = 0;

		//this->specializare = new char[strlen(specializare) + 1];

		strcpy(this->specializare, "empty");

	}

	Organizator(char* nume, int id, bool organizator, char sex, char* specializare, float salariu, double x, int* telefon) :CNP(x) {

		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

		this->telefon = new int[*this->nume];
		for (int i = 0; i <= 9; i++)
			this->telefon[i] = telefon[i];
	}

	Organizator(double cnp) :CNP(cnp) {

		this->nume = new char[strlen("nume nou") + 1];
		strcpy(this->nume, "nume nou");

		this->telefon = new int[*this->nume];

		this->salariu = 0.0;

		this->sex = 0;

		this->organizator = 0;


		//this->specializare = new char[strlen(specializare) + 1];
		strcpy(this->specializare, "empty");

	}

	Organizator(const Organizator& org) :CNP(org.CNP) {

		this->nume = new char[strlen(org.nume) + 1];
		strcpy(this->nume, org.nume);

		this->telefon = new int[*this->nume];
		for (int i = 0; i <= 9; i++)
			this->telefon[i] = org.telefon[i];

		this->organizator = org.organizator;

		*this->specializare = *org.specializare;

		this->sex = org.sex;

		this->salariu = org.salariu;
	}

	friend istream& operator>>(istream& in, Organizator& o) {

		char aux[100];

		std::cout << "\n Introdu numele persoanei:";
		in.get(aux, 100);
		in.get();
		if (o.nume != NULL)
			delete[]o.nume;
		o.nume = new char[strlen(aux) + 1];
		strcpy(o.nume, aux);

		std::cout << "\n Persoana este organizator al evenimentului curent?";
		in >> o.organizator;

		std::cout << "\n Introdu sexul persoanei:";
		in >> o.sex;

		std::cout << "\n Introdu salariul:";
		in >> o.salariu;

		std::cout << "\n Introdu specializarea:";
		in >> o.specializare;

		if (o.telefon != NULL)
			delete[] o.telefon;
		o.telefon = new int[*o.telefon];

		std::cout << "/n Telefon:";
		for (int i = 0; i <= 9; i++) {
			in >> o.telefon[i];
		}
		return in;

		//tratarea exceptiilor
		std::cout << "introduceti sexul:";
		try
		{
			in >> o.sex;
			if (o.sex != 'M' && o.sex != 'F')
				throw 1;
		}
		catch (...)
		{
			std::cout << "sexul nu a fost introdus corect. Se completeaza automat cu sexul masculin.\n";
			o.sex = 'M';
		}
		//

	}

	Organizator& operator= (const Organizator& other)
	{
		nume = new char[strlen(other.nume) + 1];
		strcpy_s(nume, strlen(other.nume), other.nume);

		organizator = other.organizator;

		for (int i = 0; i < strlen(other.specializare); i++)
			specializare[i] = other.specializare[i];
		specializare[strlen(other.specializare)] = '\0';

		sex = other.sex;
		salariu = other.salariu;

		telefon = new int[9];
		for (int i = 0; i <= 9; i++)
		{
			telefon[i] = other.telefon[i];
		}

		return *this;
	}

	friend ostream& operator<< (ostream& out, const Organizator& o);

	Organizator& operator++()
	{
		salariu++;
		return *this;
	}
	Organizator& operator--()
	{
		salariu--;
		return *this;
	}

	bool operator<= (const Organizator& other)
	{
		if (salariu <= other.salariu)
			return true;
		else
			return false;
	}
	operator char* ()
	{
		return specializare;
	}

	Organizator operator+ (Organizator& other)
	{
		return Organizator(this->nume, this->id_organizator, this->organizator, this->sex, this->specializare, this->salariu + other.salariu, this->CNP, this->telefon);
	}


	bool operator==(const Organizator& other)
	{
		if (strcmp(nume, other.nume) != 0)
			return false;
		if (organizator != other.organizator)
			return false;
		if (id_organizator != other.id_organizator)
			return false;
		if (strcmp(specializare, other.specializare) != 0)
			return false;
		if (salariu != other.salariu)
			return false;
		if (sex != other.sex)
			return false;
		if (CNP != other.CNP)
			return false;

	}

	~Organizator() {

		if (this->nume != NULL)
			delete[] this->nume;
		if (this->telefon != NULL) {
			delete[]this->telefon;
		}
	}

	int operator[](int i) {

		if (i >= 0)
			return this->telefon[i];
		else
			std::cout << "incorect";
		return -1;
	}

	friend ostream& operator<< (ostream& out, Organizator& p)
	{
		out << p.nume << p.id_organizator << p.specializare << p.sex << p.salariu << p.CNP;
		for (int i = 0; i < 9; i++)
			out << p.telefon[i];
		return out;
	}
	void Demisie() {

		this->organizator = 0;
		this->salariu = 0;
		this->id_organizator = -1;
		std::cout << "Organizatorul " << nume << " si-a dat demisia" << endl;
	}
};

//verificam daca o locatie este potrivita pentru un eveniment 
//raportand capacitatea umana la suprafata locatiei folosind CLASA TEMPLATE (verificare in main)

template <class T> class Calculator
{
private:
	T nr1, nr2;
public:
	Calculator(T numar1, T numar2)
	{
		nr1 = numar1;
		nr2 = numar2;
	}
	void Rezultat()
	{
		std::cout << "numerele sunt:" << nr1 << "si" << nr2 << "." << endl;
		std::cout << "impartirea este:" << impartire() << endl;
	}

	T impartire() { return nr1 / nr2; }
};



int main()
{
	// vector
	vector <Evenimente*> listaEvenimente;

	Nunta ne;
	cin >> ne;
	listaEvenimente.push_back(&ne);

	for (auto ir = listaEvenimente.rbegin(); ir != listaEvenimente.rend(); ++ir)
		std::cout << *ir << " ";
	//

	//lista 

	list <Evenimente*> listaEvenimente2;

	listaEvenimente2.push_back(&ne);
	listaEvenimente2.push_front(&ne);

	list<Evenimente*>::iterator it;
	for (it = listaEvenimente2.begin(); it != listaEvenimente2.end(); ++it)
		std::cout << '\t' << (*it);

	//

	//set

	set<int, greater<int>> e1;

	e1.insert(50);

	set<int, greater<int>>::iterator itr;

	std::cout << "\n Setul e1 este:";
	for (itr = e1.begin(); itr != e1.end(); ++itr) {
		std::cout << *itr << ",";
	}
	std::cout << endl;
	set<int> e2(e1.begin(), e1.end());

	// afisarea elementelor lui e2 dupa atribuirea din e1
	std::cout << "\nElementele din e2 sunt: ";
	for (itr = e2.begin(); itr != e2.end(); ++itr) {
		std::cout << *itr << ",";
	}
	//

	//map

	map<int, int> evenim;

	evenim.insert(pair<int, int>(1, 50));
	evenim.insert(pair<int, int>(2, 40));
	evenim.insert(pair<int, int>(3, 30));

	map<int, int>::iterator iter;
	cout << "\n Map-ul evenim este";

	for (iter = evenim.begin(); iter != evenim.end(); ++iter) {
		cout << '\t' << iter->first << '\t' << iter->second << '\n';
	}
	cout << endl;

	map<int, int> evenim2(evenim.begin(), evenim.end());

	//stergerea elementelor cu key=2 din evenim
	evenim2.erase(evenim2.begin(), evenim2.find(2));
	for (iter = evenim2.begin(); iter != evenim2.end(); ++iter) {
		cout << '\t' << iter->first << '\t' << iter->second << '\n';
	}

	//fisier
	Nunta object;
	//object.input();
	//object.output();


	//tratarea exceptiilor + fisiere

	bool desc = true;
	while (desc)
	{
		try
		{
			string nameF;
			cout << "Numele fisierului:";
			cin >> nameF;
			ifstream fis(nameF);
			if (!fis.is_open()) throw 1;
			desc = false;
			Nunta ne;
			fis >> ne;
			listaEvenimente.push_back(&ne);

			fis.close();

		}
		catch (...)
		{
			cout << "Fisierul nu se deschide, reincearca! \n\n";
			desc = true;
		}
	}
	//

	//calculul folosind clasa template

	Calculator<int> floatCalc(object.getcapacitate(), (double)(object.getsuprafata_locatie()));
	cout << "rezultatul de tip float:" << endl;
	floatCalc.Rezultat();
	//

	cout << "\n\n-----------------------------------------------\n\n";

	char nume[] = "Oana";
	char specializare[] = "chelner";

	//Organizator org(nume, 7, 1, "F", specializare, 2000, 1234567890123, 763455598);

	//org.Demisie();

	cout << "\n\n-------------- GATA ----------------\n\n";

	return 0;

};