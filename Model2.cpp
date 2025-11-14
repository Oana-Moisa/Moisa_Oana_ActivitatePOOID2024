#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ziCurenta;

class Produs {
public:
	string denumire;
	int cantitate;

	Produs(string denumire, int cantitate) : denumire(denumire), cantitate(cantitate) {}

	friend ostream& operator<<(ostream& out, const Produs& p) {
		out << "Produs: " << p.denumire << ", Cantitate: " << p.cantitate;
		return out;
	}
};

class Stoc {
private:
	vector<Produs> produse;

public:	Stoc& operator+=(const Produs& p) {
		for (auto& produs : produse) {
			if (produs.denumire == p.denumire) {
				produs.cantitate += p.cantitate;
				return *this;
			}
		}
		produse.push_back(p);
		return *this;
	}

	void operator()() {
		produse.erase(
			remove_if(produse.begin(), produse.end(), [](const Produs& p) {
				return p.cantitate <= 0;
				}),
			produse.end());
	}

	void afiseazaStoc() const {
		if (produse.empty()) {
			cout << "Stocul este gol!" << endl;
		}
		else {
			for (const auto& produs : produse) {
				cout << produs << endl;
			}
		}
	}
};


class Comanda {
private:
	static int contor; 
	const int idComanda;
	char* tipProdus;
	int ziExpirare;
	float pret;

public:
	Comanda() : idComanda(++contor) {
		this->tipProdus = new char[strlen("produse din carne") + 1];
		strcpy(this->tipProdus, "produse din carne");
		this->ziExpirare = 1;
		this->pret = 1.0;
	}

	Comanda(const char* tipProdus, int ziExpirare, float pret) : idComanda(++contor) {
		if (strlen(tipProdus) > 3) {
			this->tipProdus = new char[strlen(tipProdus) + 1];
			strcpy(this->tipProdus, tipProdus);
		}
		else {
			this->tipProdus = new char[strlen("produse din carne") + 1];
			strcpy(this->tipProdus, "produse din carne");
		}

		if (ziExpirare > 0 && ziExpirare < 31)
		{
			this->ziExpirare = ziExpirare;
		}
		else {
			this->ziExpirare = 1;
		}

		if (pret > 0)
		{
			this->pret = pret;
		}
		else
			this->pret = 1.0;
		cout << "Apelare constructor cu parametri" << endl;
		cout << "Tipul produsului: " << this->tipProdus << endl;
		cout << "Ziua expirarii: " << this->ziExpirare << endl;
		cout << "Pretul produsului: " << this->pret << endl;
	};

	~Comanda() {
		if (this->tipProdus != nullptr)
			delete[] this->tipProdus;
	};

	// Nu mai sunt necesare validari 
	// Cele fara param sunt atribuite de programator 
	// Cele din constructor cu param sunt validate
	Comanda(const Comanda& c) : idComanda(c.idComanda) {
		this->tipProdus = new char[strlen(c.tipProdus) + 1];
		strcpy(this->tipProdus, c.tipProdus);
		this->ziExpirare = c.ziExpirare;
		this->pret = c.pret;
	}

	int getidComanda()
	{
		return this->idComanda;
	};

	char* gettipProdus()
	{
		return this->tipProdus;
	};

	int getziExpirare()
	{
		return this->ziExpirare;
	};

	float getpret()
	{
		return this->pret;
	};

	// seter -- inver retsrictiilor din constr cu param
	void settipProdus(const char* tipProdus) {
		if (strlen(tipProdus) < 3)
			return;
		delete[] this->tipProdus;
		strcpy(this->tipProdus, tipProdus);
	};

	void setziExpirare(int ziExpirare) {
		if (ziExpirare <= 0 || ziExpirare > 31)
			return; // nu face nimic - zi invalida
		this->ziExpirare = ziExpirare;
	};

	void setpret(float pret) {
		if (pret <= 0)
			return; // nu face nimic - pret negativ
		this->pret = pret;
	};

	friend ostream& operator<<(ostream& o, Comanda& c) {
		o << "ID comanda: " << c.idComanda << endl;
		o << "Tipul produsului: " << c.tipProdus << endl;
		o << "Ziua expirarii: " << c.ziExpirare << endl;
		o << "Pretul produslui: " << c.pret << endl;
		return o;
	}

	// Nu vrem sa moficiam obiectul initial
	// Rferinta ca sa nu faca o copie in plus
	// Se foloseste & daca se modifica obiectul curent

	Comanda& operator=(const Comanda& c) {
		if (this != &c)
		{
			delete[] this->tipProdus;
			this->tipProdus = new char[strlen(c.tipProdus) + 1];
			strcpy(this->tipProdus, c.tipProdus);
			this->ziExpirare = c.ziExpirare;
			this->pret = c.pret;
		};
		return *this;
	};

	Comanda& operator*=(const float reducere) {
		if (reducere > 0 && reducere < 1)
			if (ziCurenta + 1 == this->ziExpirare) {
				this->pret *= reducere;
			};
		return *this;
	};

	bool operator== (const Comanda& c) {
		if (strcmp(this->tipProdus, c.tipProdus) == 0 && this->ziExpirare == c.ziExpirare && this->pret == c.pret)
			return true;
		else 
			return false;
	};
};

int Comanda :: contor = 0;

int main() {

	cout << "Introdu ziua curenta: ";
	cin >> ziCurenta;

	Comanda c1 ("carne congelata", 21, 2.0);
	Comanda c2 = c1;
	Comanda c3;
	c3 = c1;

	cout << "Tip " << c2.gettipProdus();
	cout << endl << "Pret initial " << c2.getpret() << endl;
	c2.setpret(20.0);
	cout << "Pret dupa modificare " << c2.getpret() << endl;

	cout << c2;
	cout << c3;

	//Comanda* c2 = new Comanda();
	////c2->~Comanda();
	//delete c2;

	c2 *= 0.5;
	cout << endl << endl << c2;

	if (c3 == c1)
	{
		cout << endl << "Sunt egale" << endl;
	}
	else 		
		cout << endl << "Nu sunt egale" << endl;

	Stoc stoc;

	stoc += Produs("Lapte", 10);
	stoc += Produs("Paine", 5);
	stoc += Produs("Oua", 12);

	cout << endl << "Stocul initial:" << endl;
	stoc.afiseazaStoc();

	stoc += Produs("Lapte", 5);
 
	cout << "\nStoc dupa actualizare:" << endl;
	stoc.afiseazaStoc();


	return 0;
}

