// Fi?ier sugerat: Magazin_Produs.cpp

#include <iostream>
#include <cstring>
using namespace std;

class Produs {
private:
    const int id;
    static int nextId;

    string denumire;
    double pret;
    int stoc;
    bool disponibil;
    char* categorie;     // ex: "Alimentar", "Electrocasnic"

public:
    // Constructor default
    Produs() : id(nextId++) {
        denumire = "";
        pret = 0;
        stoc = 0;
        disponibil = false;
        categorie = nullptr;
    }

    // Constructor cu parametri
    Produs(string denumire, double pret, int stoc, bool disponibil, const char* categorie)
        : id(nextId++) {
        this->denumire = denumire;
        this->pret = pret;
        this->stoc = stoc;
        this->disponibil = disponibil;

        if (categorie != nullptr) {
            this->categorie = new char[strlen(categorie) + 1];
            strcpy_s(this->categorie, strlen(categorie) + 1, categorie);
        }
        else {
            this->categorie = nullptr;
        }
    }

    // Constructor de copiere
    Produs(const Produs& p) : id(p.id) {
        denumire = p.denumire;
        pret = p.pret;
        stoc = p.stoc;
        disponibil = p.disponibil;

        if (p.categorie != nullptr) {
            categorie = new char[strlen(p.categorie) + 1];
            strcpy_s(categorie, strlen(p.categorie) + 1, p.categorie);
        }
        else {
            categorie = nullptr;
        }
    }

    // Destructor
    ~Produs() {
        if (categorie != nullptr)
            delete[] categorie;
    }

    // Operator =
    Produs& operator=(const Produs& p) {
        if (this == &p) return *this;

        if (categorie != nullptr) delete[] categorie;

        // id rãmâne neschimbat
        denumire = p.denumire;
        pret = p.pret;
        stoc = p.stoc;
        disponibil = p.disponibil;

        if (p.categorie != nullptr) {
            categorie = new char[strlen(p.categorie) + 1];
            strcpy_s(categorie, strlen(p.categorie) + 1, p.categorie);
        }
        else {
            categorie = nullptr;
        }

        return *this;
    }

    // Getteri
    int getId() const { return id; }
    string getDenumire() const { return denumire; }
    double getPret() const { return pret; }
    int getStoc() const { return stoc; }
    bool getDisponibil() const { return disponibil; }
    const char* getCategorie() const { return categorie; }

    // Setteri
    void setPret(double p) { pret = p; }
    void setStoc(int s) { stoc = s; }
    void setDisponibil(bool d) { disponibil = d; }

    void setCategorie(const char* c) {
        if (categorie != nullptr) delete[] categorie;
        if (c != nullptr) {
            categorie = new char[strlen(c) + 1];
            strcpy_s(categorie, strlen(c) + 1, c);
        }
        else categorie = nullptr;
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Produs& p) {
        out << "ID: " << p.id << endl;
        out << "Denumire: " << p.denumire << endl;
        out << "Pret: " << p.pret << endl;
        out << "Stoc: " << p.stoc << endl;
        out << "Disponibil: " << (p.disponibil ? "DA" : "NU") << endl;
        out << "Categorie: " << (p.categorie ? p.categorie : "-") << endl;
        return out;
    }

    // Operator !
    // Produs problemã dacã pre?ul ? 0 sau stocul e 0
    bool operator!() const {
        return pret <= 0 || stoc == 0;
    }

    // Operator ~ – schimbã disponibilitatea
    void operator~() {
        disponibil = !disponibil;
    }

    // Operator ++ prefix – cre?te stocul cu 1
    Produs& operator++() {
        stoc++;
        return *this;
    }
};

// Ini?ializare membru static
int Produs::nextId = 1;

int main() {
    Produs p1("Laptop", 3500.5, 10, true, "Electrocasnic");
    Produs p2("Paine", 0, 0, false, "Alimentar");

    cout << "=== Produs 1 ===" << endl << p1 << endl;
    cout << "=== Produs 2 ===" << endl << p2 << endl;

    cout << "Produsul 2 este problematic? " << (!p2 ? "DA" : "NU") << endl;

    cout << "Schimbãm disponibilitatea produsului 1..." << endl;
    ~p1;
    cout << p1 << endl;

    cout << "Copiem produsul 1 în produsul 3..." << endl;
    Produs p3 = p1;
    cout << p3 << endl;

    cout << "Incrementãm stocul lui p2..." << endl;
    ++p2;
    cout << p2 << endl;

    return 0;
}
