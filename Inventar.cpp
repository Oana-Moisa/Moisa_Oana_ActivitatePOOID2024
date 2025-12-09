#include <iostream>
#include <cstring>
using namespace std;

class InventarProdus {
private:
    const int id;
    static int nextId;

    string denumire;
    int stoc;
    double pret;
    bool disponibil;
    char* categorie;

public:
    // Constructor default
    InventarProdus() : id(nextId++) {
        denumire = "";
        stoc = 0;
        pret = 0;
        disponibil = false;
        categorie = nullptr;
    }

    // Constructor cu parametri
    InventarProdus(string denumire, int stoc, double pret, bool disponibil, const char* categorie)
        : id(nextId++) {
        this->denumire = denumire;
        this->stoc = stoc;
        this->pret = pret;
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
    InventarProdus(const InventarProdus& p) : id(p.id) {
        denumire = p.denumire;
        stoc = p.stoc;
        pret = p.pret;
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
    ~InventarProdus() {
        if (categorie != nullptr)
            delete[] categorie;
    }

    // Operator =
    InventarProdus& operator=(const InventarProdus& p) {
        if (this == &p) return *this;

        if (categorie != nullptr) delete[] categorie;

        denumire = p.denumire;
        stoc = p.stoc;
        pret = p.pret;
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
    int getStoc() const { return stoc; }
    double getPret() const { return pret; }
    bool getDisponibil() const { return disponibil; }
    const char* getCategorie() const { return categorie; }

    // Setteri
    void setStoc(int s) { stoc = s; }
    void setPret(double p) { pret = p; }
    void setDisponibil(bool d) { disponibil = d; }

    void setCategorie(const char* c) {
        if (categorie != nullptr) delete[] categorie;
        if (c != nullptr) {
            categorie = new char[strlen(c) + 1];
            strcpy_s(categorie, strlen(categorie) + 1, c);
        }
        else {
            categorie = nullptr;
        }
    }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const InventarProdus& p) {
        out << "ID: " << p.id << endl;
        out << "Denumire: " << p.denumire << endl;
        out << "Stoc: " << p.stoc << endl;
        out << "Pret: " << p.pret << endl;
        out << "Disponibil: " << (p.disponibil ? "DA" : "NU") << endl;
        out << "Categorie: " << (p.categorie ? p.categorie : "-") << endl;
        return out;
    }

    // Operator ! — produs invalid dacã stocul e zero
    bool operator!() const {
        return stoc == 0;
    }

    // Operator ~ — inverseazã disponibilitatea
    void operator~() {
        disponibil = !disponibil;
    }

    // Operator ++ — cre?terea stocului
    InventarProdus& operator++() {
        stoc++;
        return *this;
    }
};

int InventarProdus::nextId = 1;

int main() {
    InventarProdus p1("Caiet A4", 50, 4.5, true, "Papetarie");
    InventarProdus p2("Capsator", 0, 12.0, false, "Birou");

    cout << p1 << endl;
    cout << p2 << endl;

    ~p1;   // modificã starea de disponibilitate
    cout << p1 << endl;

    InventarProdus p3 = p1; // constructor de copiere
    cout << p3 << endl;

    ++p2;  // cre?terea stocului
    cout << p2 << endl;

    return 0;
}
