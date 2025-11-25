#include <iostream>
#include <cstring>
using namespace std;

class BiletConcert {
private:
    const int id;
    static int nextId;

    string numeCumparator;
    int loc;
    double pret;
    bool valid;
    char* zona;

public:
    BiletConcert() : id(nextId++) {
        numeCumparator = "";
        loc = 0;
        pret = 0;
        valid = false;
        zona = nullptr;
    }

    BiletConcert(string numeCumparator, int loc, double pret, bool valid, const char* zona)
        : id(nextId++) {
        this->numeCumparator = numeCumparator;
        this->loc = loc;
        this->pret = pret;
        this->valid = valid;

        if (zona != nullptr) {
            this->zona = new char[strlen(zona) + 1];
            strcpy_s(this->zona, strlen(zona) + 1, zona);
        }
        else {
            this->zona = nullptr;
        }
    }

    BiletConcert(const BiletConcert& b) : id(b.id) {
        numeCumparator = b.numeCumparator;
        loc = b.loc;
        pret = b.pret;
        valid = b.valid;

        if (b.zona != nullptr) {
            zona = new char[strlen(b.zona) + 1];
            strcpy_s(zona, strlen(b.zona) + 1, b.zona);
        }
        else {
            zona = nullptr;
        }
    }

    ~BiletConcert() {
        if (zona != nullptr)
            delete[] zona;
    }

    BiletConcert& operator=(const BiletConcert& b) {
        if (this == &b) return *this;

        if (zona != nullptr) delete[] zona;

        numeCumparator = b.numeCumparator;
        loc = b.loc;
        pret = b.pret;
        valid = b.valid;

        if (b.zona != nullptr) {
            zona = new char[strlen(b.zona) + 1];
            strcpy_s(zona, strlen(b.zona) + 1, b.zona);
        }
        else {
            zona = nullptr;
        }

        return *this;
    }

    int getId() const { return id; }
    string getNumeCumparator() const { return numeCumparator; }
    int getLoc() const { return loc; }
    double getPret() const { return pret; }
    bool getValid() const { return valid; }
    const char* getZona() const { return zona; }

    void setLoc(int l) { loc = l; }
    void setPret(double p) { pret = p; }
    void setValid(bool v) { valid = v; }

    void setZona(const char* z) {
        if (zona != nullptr) delete[] zona;
        if (z != nullptr) {
            zona = new char[strlen(z) + 1];
            strcpy_s(zona, strlen(z) + 1, z);
        }
        else {
            zona = nullptr;
        }
    }

    friend ostream& operator<<(ostream& out, const BiletConcert& b) {
        out << "ID: " << b.id << endl;
        out << "Nume cumparator: " << b.numeCumparator << endl;
        out << "Loc: " << b.loc << endl;
        out << "Pret: " << b.pret << endl;
        out << "Valid: " << (b.valid ? "DA" : "NU") << endl;
        out << "Zona: " << (b.zona ? b.zona : "-") << endl;
        return out;
    }

    bool operator!() const {
        return !valid || pret <= 0;
    }

    void operator~() {
        valid = !valid;
    }

    BiletConcert& operator++() {
        loc++;
        return *this;
    }
};

int BiletConcert::nextId = 1;

int main() {
    BiletConcert b1("Popescu Ana", 45, 200, true, "Gold");
    BiletConcert b2("Ionescu Mihai", 0, 0, false, "Bronze");

    cout << b1 << endl;
    cout << b2 << endl;

    cout << (!b2 ? "Bilet invalid" : "Bilet valid") << endl;

    ~b1;
    cout << b1 << endl;

    BiletConcert b3 = b1;
    cout << b3 << endl;

    ++b2;
    cout << b2 << endl;

    return 0;
}
