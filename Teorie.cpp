#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Obiect {
private:
	static int contor; // Apartine clasei (partajat intre toate obiectele).
	const int id;        // Apartine obiectului
	int atribut2;              // Variabila privata obisnuita
	string atribut3;           // Sir de caractere
	char* atribut4;            // Pointer catre sir de caractere

public:

	// Constructor implicit
	Obiect() : id(contor++) {
		this->atribut2 = 0;
		this->atribut3 = "default";
		this->atribut4 = new char[strlen("no name") + 1];
		strcpy_s(this->atribut4, strlen("no name") + 1, "no name");
	}

	// Constructor cu parametrii
	Obiect(int atribut2, const string atribut3, const char* atribut4) : id(contor++) {
		this->atribut2 = atribut2;
		this->atribut3 = atribut3;
		this->atribut4 = new char[strlen(atribut4) + 1];
		strcpy_s(this->atribut4, strlen(atribut4) + 1, atribut4);
	}

	// Constructor copiere
	Obiect(const Obiect& o) : id(o.id) {
		this->atribut2 = o.atribut2;
		this->atribut3 = o.atribut3;
		this->atribut4 = new char[strlen(o.atribut4) + 1];
		strcpy_s(this->atribut4, strlen(o.atribut4) + 1, o.atribut4);
	}

	// Destructor
	~Obiect() {
		delete[] atribut4;
	}

	// Operator=
	Obiect& operator=(const Obiect& o) {
		if (this != &o) {
			delete[] atribut4;
			this->atribut2 = o.atribut2;
			this->atribut3 = o.atribut3;
			this->atribut4 = new char[strlen(o.atribut4) + 1];
			strcpy_s(this->atribut4, strlen(o.atribut4) + 1, o.atribut4);
		}
		return *this;
	}

	// Getter pentru 'atribut2'
	int getAtribut2() const {
		return atribut2;
	}

	// Setter pentru 'atribut2'
	void setAtribut2(int atribut2) {
		if (atribut2 != 0) {
			this->atribut2 = atribut2;
		}
		else {
			this->atribut2 = 12;
		}
	}

		// Functie afisare pentru 'atribut2'
		void afisareAtribut() const {
			cout << "Atributul 2: " << atribut2 << endl;
		}
		
		friend ostream& operator<<(ostream& out, const Obiect& o) {
			out << "ID obiect: " << o.id << endl;
			out << "Atribut2: " << o.atribut2 << endl;
			out << "Atribut3: " << o.atribut3 << endl;
			out << "Atribut4: " << o.atribut4 << endl;
			return out;
		}
};

int Obiect::contor = 1;

int main() {

	cout << endl << "1. Creare obiecte cu constructor implicit" << endl;
	Obiect o1;
	Obiect o2; 
	cout << o1;
	cout << "----------------------------" << endl;
	cout << o2;


	cout << endl << "2. Getter atribut2 pt o1";
	cout << endl << "Atribut2: " << o1.getAtribut2() << endl;

	o1.setAtribut2(99);
	cout << endl << "3. o1 dupa setter la 99" << endl;
	cout << o1;

	cout << endl << "4. Constructor cu parametrii" << endl;
	Obiect o3(100, "#3", "fara setari");
	Obiect o4(200, "#4", "setari avansate");
	cout << o3;
	cout << "----------------------------" << endl;
	cout << o4;

	cout << endl << "5. Constructor copiere (o5 = o4)" << endl;
	Obiect o5 = o4;
	cout << o5;

	cout << endl << "6. Operator= (o3 = o1)" << endl;
	o3 = o1;
	cout << o3;

	cout << endl << "6. Fct afisare atribut2 pt o2" << endl;
	o2.afisareAtribut();

	return 0;
}