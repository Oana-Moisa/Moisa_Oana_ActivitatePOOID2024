#include <iostream>
#include <cstring>

using namespace std;

class Carte {
private:
    const int id;
    static int nextId;

    string titlu;
    string autor;
    int nrPagini;
    bool imprumutata;
    char* categorie;     // ex: "Roman", "SF", "Istorie"

public:
    // Constructor default
    Carte() : id(nextId++) {
        this->titlu = "";
        this->autor = "";
        this->nrPagini = 0;
        this->imprumutata = false;
        this->categorie = nullptr;
    }

    // Constructor cu parametri (cu valori default)
    Carte(string titlu,
        string autor,
        int nrPagini,
        bool imprumutata,
        const char* categorie)
        : id(nextId++) {
        this->titlu = titlu;
        this->autor = autor;
        this->nrPagini = nrPagini;
        this->imprumutata = imprumutata;

        if (categorie != nullptr) {
            this->categorie = new char[strlen(categorie) + 1];
            strcpy_s(this->categorie, strlen(categorie) + 1, categorie);
        }
        else {
            this->categorie = nullptr;
        }
    }

    // Constructor de copiere
    Carte(const Carte& c) : id(c.id) {
        this->titlu = c.titlu;
        this->autor = c.autor;
        this->nrPagini = c.nrPagini;
        this->imprumutata = c.imprumutata;

        if (c.categorie != nullptr) {
            this->categorie = new char[strlen(c.categorie) + 1];
            strcpy_s(this->categorie, strlen(c.categorie) + 1, c.categorie);
        }
        else {
            this->categorie = nullptr;
        }
    }

    // Destructor
    ~Carte() {
        if (this->categorie != nullptr) {
            delete[] this->categorie;
        }
    }

    // Operator =
    Carte& operator=(const Carte& c) {
        if (this == &c) {
            return *this;
        }

        if (this->categorie != nullptr) {
            delete[] this->categorie;
        }

        // id este const -> nu se reasigneazã

        this->titlu = c.titlu;
        this->autor = c.autor;
        this->nrPagini = c.nrPagini;
        this->imprumutata = c.imprumutata;

        if (c.categorie != nullptr) {
            this->categorie = new char[strlen(c.categorie) + 1];
            strcpy_s(this->categorie, strlen(c.categorie) + 1, c.categorie);
        }
        else {
            this->categorie = nullptr;
        }

        return *this;
    }

    // Getteri
    int getId() const {
        return this->id;
    }

    string getTitlu() const {
        return this->titlu;
    }

    string getAutor() const {
        return this->autor;
    }

    int getNrPagini() const {
        return this->nrPagini;
    }

    bool getImprumutata() const {
        return this->imprumutata;
    }

    char* getCategorie() const {
        return this->categorie;
    }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Carte& c) {
        out << "ID: " << c.id << endl;
        out << "Titlu: " << c.titlu << endl;
        out << "Autor: " << c.autor << endl;
        out << "Numar pagini: " << c.nrPagini << endl;
        out << "Imprumutata: " << (c.imprumutata ? "DA" : "NU") << endl;
        out << "Categorie: ";
        if (c.categorie != nullptr) {
            out << c.categorie;
        }
        else {
            out << "-";
        }
        out << endl;
        return out;
    }

    // Operator ! 
    // Consideram "carti scurte" cele cu sub 100 pagini
    bool operator!() const {
        return this->nrPagini < 100;
    }

    // Operator ~  (toggle pe imprumutata)
    void operator~() {
        this->imprumutata = !this->imprumutata;
    }
};

// initializare membru static
int Carte::nextId = 1;

int main() {
    // Carte cu constructor cu parametri
    Carte c1("Micul Print", "Antoine de Saint-Exupery", 96, false, "Literatura");
    Carte c2("Crima si pedeapsa", "F. M. Dostoievski", 650, true, "Roman");

    cout << "=== Carte 1 ===" << endl;
    cout << c1 << endl;

    cout << "=== Carte 2 ===" << endl;
    cout << c2 << endl;

    // Testare operator !
    cout << "Carte 1 este scurta (<100 pagini)? "
        << (!c1 ? "DA" : "NU") << endl;
    cout << "Carte 2 este scurta (<100 pagini)? "
        << (!c2 ? "DA" : "NU") << endl << endl;

    // Testare operator ~
    cout << "Schimbam statusul de imprumut pentru cartea 1 cu ~c1..." << endl;
    ~c1;
    cout << c1 << endl;

    // Testare constructor de copiere
    cout << "=== Carte 3 (copie dupa c2) ===" << endl;
    Carte c3 = c2;
    cout << c3 << endl;

    // Testare operator =
    cout << "Dupa c3 = c1:" << endl;
    c3 = c1;
    cout << c3 << endl;

    return 0;
}
