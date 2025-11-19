#include <iostream>
#include <fstream>

using namespace std;

//Clasa
class Petitie {
private:
	const int id;
	string data;
	string numeComplet;
	int nrZile;
	bool status;
	char* descriere;
public:

	//Constructor default (fără parametrii)
	Petitie() : id(id) {
		this->data = "";
		this->numeComplet = "";
		this->nrZile = 0;
		this->status = true;
		this->descriere = nullptr;
	}

	//Constructor cu parametrii 
	Petitie(string data = "", string numeComplet = "", int nrZile = 0, bool status = true, const char* descriere = nullptr) : id(id) {
		this->data = data;
		this->numeComplet = numeComplet;
		this->nrZile = nrZile;
		this->status = status;
		if (descriere != nullptr) {
			this->descriere = new char[strlen(descriere) + 1];
			strcpy_s(this->descriere, strlen(descriere) + 1, descriere);
		}
		else {
			this->descriere = nullptr;
		}
	}

	//Constructorul de copiere 
	Petitie(const Petitie& p) : id(p.id) {
		this->data = p.data;
		this->numeComplet = p.numeComplet;
		this->nrZile = p.nrZile;
		this->status = p.status;
		if (p.descriere != nullptr) {
			this->descriere = new char[strlen(p.descriere) + 1];
			strcpy_s(this->descriere, strlen(p.descriere) + 1, p.descriere);
		}
		else {
			this->descriere = nullptr;
		}
	}

	//Destructorul
	~Petitie() {
		if (this->descriere != nullptr) {
			delete[] this->descriere;
		}
	}

	//Operatorul=
	Petitie& operator=(const Petitie& p) {
		if (this->descriere != nullptr) {
			delete[] this->descriere;
		}

		this->data = p.data;
		this->numeComplet = p.numeComplet;
		this->nrZile = p.nrZile;
		this->status = p.status;
		if (p.descriere != nullptr) {
			this->descriere = new char[strlen(p.descriere) + 1];
			strcpy_s(this->descriere, strlen(p.descriere) + 1, p.descriere);
		}
		else {
			this->descriere = nullptr;
		}

		return *this;
	}

	//Getteri și setteri
	string getData() {
		return this->data;
	}

	string getNumeComplet() {
		return this->numeComplet;
	}

	int getNrZile() {
		return this->nrZile;
	}

	bool getStatus() {
		return this->status;
	}

	char* getDescriere() {
		return this->descriere;
	}

	//Afișare de la tastatură
	friend ostream& operator<<(ostream& out, Petitie& p) {
		out << p.data << " " << p.numeComplet << " " << p.nrZile << " " << p.status << " " << p.descriere << " ";
		if (p.descriere != nullptr) {
			out << p.descriere;
		}
		return out;
	}

	//Operatori
	bool operator!() {
		if (status == 0 && nrZile > 30) {
			return true;
		}
		else {
			return false;
		}
	}

	void operator~() {
		if (status == 0) {
			status = 1;
		}
		else {
			status = 0;
		}
	}
};

//Afișare în main
int main() {
	Petitie p1("12/08/2021", "Ionescu Ion", 35, true, "abc");
	cout << "Data: " << p1.getData() << endl;
	cout << "Nume: " << p1.getNumeComplet() << endl;
	cout << "Nr Zile: " << p1.getNrZile() << endl;
	cout << "Status: " << p1.getStatus() << endl;
	cout << "Descriere: " << p1.getDescriere() << endl;
	cout << endl;

	Petitie p2("05/10/2018", "Popescu Vasile", 15, false, "def");
	cout << "Data: " << p2.getData() << endl;
	cout << "Nume: " << p2.getNumeComplet() << endl;
	cout << "Nr Zile: " << p2.getNrZile() << endl;
	cout << "Status: " << p2.getStatus() << endl;
	cout << "Descriere: " << p2.getDescriere() << endl;
	cout << endl;

	bool ok = !p1;
	cout << (p1.getNrZile() > 30 ? "Expirata" : "Ok") << endl;

	~p1;
	cout << "Dupa ~" << endl << p1  << endl;
}