#include <iostream>
#include <cstring>

using namespace std;

class ComandaOnline {
private:
    const int id;
    static int nextId;

    string dataPlasare;
    string numeClient;
    double valoare;
    bool livrata;
    char* adresaLivrare;

public:
    // Constructor default
    ComandaOnline()
        : id(nextId++) {
        this->dataPlasare = "";
        this->numeClient = "";
        this->valoare = 0;
        this->livrata = false;
        this->adresaLivrare = nullptr;
    }

    // Constructor cu parametri
    ComandaOnline(string dataPlasare,
        string numeClient,
        double valoare,
        bool livrata,
        const char* adresaLivrare)
        : id(nextId++) {
        this->dataPlasare = dataPlasare;
        this->numeClient = numeClient;
        this->valoare = valoare;
        this->livrata = livrata;

        if (adresaLivrare != nullptr) {
            this->adresaLivrare = new char[strlen(adresaLivrare) + 1];
            strcpy_s(this->adresaLivrare,
                strlen(adresaLivrare) + 1,
                adresaLivrare);
        }
        else {
            this->adresaLivrare = nullptr;
        }
    }

    // Constructor de copiere
    ComandaOnline(const ComandaOnline& c)
        : id(c.id) {
        this->dataPlasare = c.dataPlasare;
        this->numeClient = c.numeClient;
        this->valoare = c.valoare;
        this->livrata = c.livrata;

        if (c.adresaLivrare != nullptr) {
            this->adresaLivrare = new char[strlen(c.adresaLivrare) + 1];
            strcpy_s(this->adresaLivrare,
                strlen(c.adresaLivrare) + 1,
                c.adresaLivrare);
        }
        else {
            this->adresaLivrare = nullptr;
        }
    }

    // Destructor
    ~ComandaOnline() {
        if (this->adresaLivrare != nullptr) {
            delete[] this->adresaLivrare;
        }
    }

    // Operator=
    ComandaOnline& operator=(const ComandaOnline& c) {
        if (this == &c) {
            return *this;
        }

        if (this->adresaLivrare != nullptr) {
            delete[] this->adresaLivrare;
        }

        // id este const, NU se poate copia / modifica aici

        this->dataPlasare = c.dataPlasare;
        this->numeClient = c.numeClient;
        this->valoare = c.valoare;
        this->livrata = c.livrata;

        if (c.adresaLivrare != nullptr) {
            this->adresaLivrare = new char[strlen(c.adresaLivrare) + 1];
            strcpy_s(this->adresaLivrare,
                strlen(c.adresaLivrare) + 1,
                c.adresaLivrare);
        }
        else {
            this->adresaLivrare = nullptr;
        }

        return *this;
    }

    // Getteri
    int getId() const {
        return this->id;
    }

    string getDataPlasare() const {
        return this->dataPlasare;
    }

    string getNumeClient() const {
        return this->numeClient;
    }

    double getValoare() const {
        return this->valoare;
    }

    bool getLivrata() const {
        return this->livrata;
    }

    char* getAdresaLivrare() const {
        return this->adresaLivrare;
    }

    // Operator << pentru afisare
    friend ostream& operator<<(ostream& out, const ComandaOnline& c) {
        out << "Id: " << c.id << endl;
        out << "Data plasare: " << c.dataPlasare << endl;
        out << "Client: " << c.numeClient << endl;
        out << "Valoare: " << c.valoare << endl;
        out << "Livrata: " << (c.livrata ? "DA" : "NU") << endl;
        out << "Adresa livrare: ";
        if (c.adresaLivrare != nullptr) {
            out << c.adresaLivrare;
        }
        else {
            out << "-";
        }
        out << endl;
        return out;
    }

    // Operator !
    // Consideram "problematica" o comanda cu valoare 0 sau nelivrata
    bool operator!() const {
        if (this->valoare <= 0 || this->livrata == false) {
            return true;
        }
        else {
            return false;
        }
    }

    // Operator ~ (toggle pe livrata)
    void operator~() {
        this->livrata = !this->livrata;
    }
};

// Initializare membru static
int ComandaOnline::nextId = 1;

int main() {
    ComandaOnline c1("10/11/2025", "Popescu Ana", 350.75, false, "Str. Libertatii nr. 10");
    ComandaOnline c2("12/11/2025", "Ionescu Mihai", 0, false, "Bd. Unirii nr. 25");

    cout << "Comanda 1:" << endl;
    cout << c1 << endl;

    cout << "Comanda 2:" << endl;
    cout << c2 << endl;

    // Testare operator !
    bool prob = !c2;
    cout << "Comanda 2 este problematica? "
        << (prob ? "DA" : "NU") << endl << endl;

    // Testare operator ~
    ~c1;
    cout << "Dupa ~c1:" << endl;
    cout << c1 << endl;

    // Testare constructor de copiere
    ComandaOnline c3 = c1;
    cout << "Comanda 3 (copie dupa c1):" << endl;
    cout << c3 << endl;

    // Testare operator=
    c3 = c2;
    cout << "Comanda 3 dupa c3 = c2:" << endl;
    cout << c3 << endl;

    return 0;
}
