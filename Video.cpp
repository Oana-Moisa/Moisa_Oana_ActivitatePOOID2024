#define _CRT_SECURE_NO_WARNINGS
#include <iostream>;
#include <fstream>;
using namespace std;

class Abonament {
private:
	static int contor;
	const int idAbonament;
	float pret;
	int durata;
	int optiune;
	int* vizualizari;

public: 
	Abonament() : idAbonament(contor++) {
		this->pret = 10.5f;
		this->durata = 0;
		this->optiune = 3;
		this->vizualizari = new int[3];
		for (int i = 0; i < 3; i++) {
			this->vizualizari[i] = 100;
		}

	}

	Abonament(float pret, int durata, int optiune, const int* vizualizari) : idAbonament(contor++) {
		this->pret = pret;
		this->durata = durata;
		this->optiune = optiune;
		this->vizualizari = new int[optiune];
		if (this->vizualizari != nullptr && optiune > 0) {
		for (int i = 0; i < optiune; i++) {
			this->vizualizari[i] = vizualizari[i];
		}
		}
	}

	Abonament(const Abonament& ab) : idAbonament(idAbonament) {
			this->pret = ab.pret;
			this->durata = ab.durata;
			this->optiune = ab.optiune;
			this->vizualizari = new int[ab.optiune];
			if (this->vizualizari != nullptr && optiune > 0) {
				for (int i = 0; i < ab.optiune; i++) {
					this->vizualizari[i] = ab.vizualizari[i];
				}
			}	
	}

	~Abonament() {
		if (this->vizualizari != nullptr) {
			delete[] this->vizualizari;
			this->vizualizari = nullptr;
		}
	}

	Abonament& operator=(const Abonament& ab) {
		if (this != &ab) {
			if (this->vizualizari != nullptr) {
				delete[] this->vizualizari;
				this->vizualizari = nullptr;
			}
		this->pret = ab.pret;
		this->durata = ab.durata;
		this->optiune = ab.optiune;
		this->vizualizari = new int[ab.optiune];
		if (this->vizualizari != nullptr && optiune > 0) {
			for (int i = 0; i < ab.optiune; i++) {
				this->vizualizari[i] = ab.vizualizari[i];
			}
		}
	}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Abonament& ab) {
		out << "Pret: " << ab.pret << endl;
		out << "Durata: " << ab.durata << endl;
		out << "Optiune: " << ab.optiune << endl;
		out << "Vizualizari: ";
		for (int i = 0; i < ab.optiune; i++) {
			out << ab.vizualizari[i] << " ; ";
		}
		cout << endl;
		return out;
	}

	int getDurata() const {
		if (durata > 0) {
			return durata;
		}
	}

	void setDurata(int) {
		if (durata > 0) {
			this->durata = durata;
		}
		else {
			this->durata = 6;
		}
		} 

	Abonament& operator+=(const Abonament& ab) {
		this->pret += ab.pret;
		return *this;
	}

	Abonament& operator-=(const Abonament& ab) {
		this->pret -= ab.pret;
		return *this;
	}

	operator double() const {
		if (this->vizualizari != nullptr && this->optiune > 0) {
			int max = this->vizualizari[0];
			for (int i = 1; i < this->optiune; i++) {
				if (this->vizualizari[i] > max) {
					max = this->vizualizari[i];
				}
			}
			return static_cast<double>(max);
		}
		return 0.0;
	}
};

int Abonament::contor = 1;

int main() {
	
	Abonament ab1;

	cout << "Constructor implicit: " << endl;
	cout << ab1;

	cout << "=========================================" << endl;
	cout << "Constructor parametrii: " << endl;
	Abonament ab2(15.6f, 12, 4, new int[4]{50,60,70,80});
	cout << ab2;

	cout << "=========================================" << endl;
	cout << "Get durata abonament #2: " << endl;
	cout << ab2.getDurata() << endl;

	cout << "=========================================" << endl;
	cout << "Set durata abonament #2: " << endl;
	ab1.setDurata(6);
	cout << ab1;

	cout << "=========================================" << endl;
	cout << "Constructor copiere a3 = a2: " << endl;
	Abonament ab3 = ab2;
	cout << ab3;

	cout << "=========================================" << endl;
	cout << "'Operator=' a3 = a1: " << endl;
	ab3 = ab1;
	cout << ab3;

	cout << "=========================================" << endl;
	cout << "'Operator +=' ab5(default) += ab6: " << endl;
	Abonament ab5;
	cout << ab5 << endl;
	Abonament ab6(20.0f, 6, 3, new int[4]{50, 60, 70, 100});
	cout << ab6 << endl;
	ab5 += ab6;
	cout << ab5;

	cout << "=========================================" << endl;
	cout << "'Operator -=' ab7(default) += ab8: " << endl;
	Abonament ab7;
	cout << ab5 << endl;
	Abonament ab8(20.0f, 6, 3, new int[4] {50, 60, 70, 100});
	cout << ab6 << endl;
	ab8 -= ab7;
	cout << ab8;

	cout << "=========================================" << endl;
	cout << "Operator cast: " << endl;
	float pretAbonament = (int)ab2;
	cout << "Pretul abonamentului este: " << pretAbonament << endl;

	cout << "=========================================" << endl;

	return 0;
};
