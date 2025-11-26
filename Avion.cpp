#include <iostream>
#include <cstring>
using namespace std;

class CursaAvion {
private:
    const int id;
    static int nextId;

    string destinatie;
    double durata;
    bool plecareConfirmata;
    int nrPasageri;
    char* tipAeronava;

public:
    CursaAvion() : id(nextId++) {
        destinatie = "";
        durata = 0;
        plecareConfirmata = false;
        nrPasageri = 0;
        tipAeronava = nullptr;
    }

    CursaAvion(string destinatie, double durata, bool plecareConfirmata, int nrPasageri, const char* tipAeronava)
        : id(nextId++) {
        this->destinatie = destinatie;
        this->durata = durata;
        this->plecareConfirmata = plecareConfirmata;
        this->nrPasageri = nrPasageri;

        if (tipAeronava != nullptr) {
            this->tipAeronava = new char[strlen(tipAeronava) + 1];
            strcpy_s(this->tipAeronava, strlen(tipAeronava) + 1, tipAeronava);
        }
        else {
            this->tipAeronava = nullptr;
        }
    }

    CursaAvion(const CursaAvion& c) : id(c.id) {
        destinatie = c.destinatie;
        durata = c.durata;
        plecareConfirmata = c.plecareConfirmata;
        nrPasageri = c.nrPasageri;

        if (c.tipAeronava != nullptr) {
            tipAeronava = new char[strlen(c.tipAeronava) + 1];
            strcpy_s(tipAeronava, strlen(c.tipAeronava) + 1, c.tipAeronava);
        }
        else {
            tipAeronava = nullptr;
        }
    }

    ~CursaAvion() {
        if (tipAeronava != nullptr)
            delete[] tipAeronava;
    }

    CursaAvion& operator=(const CursaAvion& c) {
        if (this == &c) return *this;

        if (tipAeronava != nullptr) delete[] tipAeronava;

        destinatie = c.destinatie;
        durata = c.durata;
        plecareConfirmata = c.plecareConfirmata;
        nrPasageri = c.nrPasageri;

        if (c.tipAeronava != nullptr) {
            tipAeronava = new char[strlen(c.tipAeronava) + 1];
            strcpy_s(tipAeronava, strlen(c.tipAeronava) + 1, c.tipAeronava);
        }
        else {
            tipAeronava = nullptr;
        }

        return *this;
    }

    int getId() const { return id; }
    string getDestinatie() const { return destinatie; }
    double getDurata() const { return durata; }
    bool getPlecareConfirmata() const { return plecareConfirmata; }
    int getNrPasageri() const { return nrPasageri; }
    const char* getTipAeronava() const { return tipAeronava; }

    void setDurata(double d) { durata = d; }
    void setPlecareConfirmata(bool p) { plecareConfirmata = p; }
    void setNrPasageri(int n) { nrPasageri = n; }

    void setTipAeronava(const char* t) {
        if (tipAeronava != nullptr) delete[] tipAeronava;
        if (t != nullptr) {
            tipAeronava = new char[strlen(t) + 1];
            strcpy_s(tipAeronava, strlen(tipAeronava) + 1, t);
        }
        else {
            tipAeronava = nullptr;
        }
    }

    friend ostream& operator<<(ostream& out, const CursaAvion& c) {
        out << "ID: " << c.id << endl;
        out << "Destinatie: " << c.destinatie << endl;
        out << "Durata: " << c.durata << endl;
        out << "Plecare confirmata: " << (c.plecareConfirmata ? "DA" : "NU") << endl;
        out << "Numar pasageri: " << c.nrPasageri << endl;
        out << "Tip aeronava: " << (c.tipAeronava ? c.tipAeronava : "-") << endl;
        return out;
    }

    bool operator!() const {
        return !plecareConfirmata || nrPasageri <= 0 || durata <= 0;
    }

    void operator~() {
        plecareConfirmata = !plecareConfirmata;
    }

    CursaAvion& operator++() {
        nrPasageri++;
        return *this;
    }
};

int CursaAvion::nextId = 1;

int main() {
    CursaAvion c1("Londra", 3.5, true, 150, "Boeing 737");
    CursaAvion c2("Paris", 0, false, 0, "Airbus A320");

    cout << c1 << endl;
    cout << c2 << endl;

    cout << (!c2 ? "Cursa efectuata" : "Cursa neefectuata") << endl;

    ~c1;
    cout << c1 << endl;

    CursaAvion c3 = c1;
    cout << c3 << endl;

    ++c2;
    cout << c2 << endl;

    return 0;
}
