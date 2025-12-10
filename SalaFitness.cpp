#include <iostream>
#include <cstring>
using namespace std;

class SalaFitnessMembri {
private:
    const int id;
    static int nextId;

    string nume;
    int varsta;
    double abonamentLunar;
    bool activ;
    char* tipAbonament;

public:
    SalaFitnessMembri() : id(nextId++) {
        nume = "";
        varsta = 0;
        abonamentLunar = 0;
        activ = false;
        tipAbonament = nullptr;
    }

    SalaFitnessMembri(string nume, int varsta, double abonamentLunar, bool activ, const char* tipAbonament)
        : id(nextId++) {
        this->nume = nume;
        this->varsta = varsta;
        this->abonamentLunar = abonamentLunar;
        this->activ = activ;

        if (tipAbonament != nullptr) {
            this->tipAbonament = new char[strlen(tipAbonament) + 1];
            strcpy_s(this->tipAbonament, strlen(tipAbonament) + 1, tipAbonament);
        }
        else {
            this->tipAbonament = nullptr;
        }
    }

    SalaFitnessMembri(const SalaFitnessMembri& m) : id(m.id) {
        nume = m.nume;
        varsta = m.varsta;
        abonamentLunar = m.abonamentLunar;
        activ = m.activ;

        if (m.tipAbonament != nullptr) {
            tipAbonament = new char[strlen(m.tipAbonament) + 1];
            strcpy_s(tipAbonament, strlen(m.tipAbonament) + 1, m.tipAbonament);
        }
        else {
            tipAbonament = nullptr;
        }
    }

    ~SalaFitnessMembri() {
        if (tipAbonament != nullptr) {
            delete[] tipAbonament;
        }
    }

    SalaFitnessMembri& operator=(const SalaFitnessMembri& m) {
        if (this == &m) {
            return *this;
        }

        if (tipAbonament != nullptr) {
            delete[] tipAbonament;
        }

        nume = m.nume;
        varsta = m.varsta;
        abonamentLunar = m.abonamentLunar;
        activ = m.activ;

        if (m.tipAbonament != nullptr) {
            tipAbonament = new char[strlen(m.tipAbonament) + 1];
            strcpy_s(tipAbonament, strlen(m.tipAbonament) + 1, m.tipAbonament);
        }
        else {
            tipAbonament = nullptr;
        }

        return *this;
    }

    int getId() const { return id; }
    string getNume() const { return nume; }
    int getVarsta() const { return varsta; }
    double getAbonamentLunar() const { return abonamentLunar; }
    bool getActiv() const { return activ; }
    const char* getTipAbonament() const { return tipAbonament; }

    void setVarsta(int v) { varsta = v; }
    void setAbonamentLunar(double a) { abonamentLunar = a; }
    void setActiv(bool a) { activ = a; }

    void setTipAbonament(const char* t) {
        if (tipAbonament != nullptr) {
            delete[] tipAbonament;
        }
        if (t != nullptr) {
            tipAbonament = new char[strlen(t) + 1];
            strcpy_s(tipAbonament, strlen(tipAbonament) + 1, t);
        }
        else {
            tipAbonament = nullptr;
        }
    }

    friend ostream& operator<<(ostream& out, const SalaFitnessMembri& m) {
        out << "ID: " << m.id << endl;
        out << "Nume: " << m.nume << endl;
        out << "Varsta: " << m.varsta << endl;
        out << "Abonament lunar: " << m.abonamentLunar << endl;
        out << "Activ: " << (m.activ ? "DA" : "NU") << endl;
        out << "Tip abonament: " << (m.tipAbonament ? m.tipAbonament : "-") << endl;
        return out;
    }

    bool operator!() const {
        return abonamentLunar == 0;
    }

    void operator~() {
        activ = !activ;
    }

    SalaFitnessMembri& operator++() {
        varsta++;
        return *this;
    }
};

int SalaFitnessMembri::nextId = 1;

int main() {
    SalaFitnessMembri m1("Alex Pop", 25, 150.0, true, "Full");
    SalaFitnessMembri m2("Maria Iancu", 19, 0, false, "Weekend");

    cout << m1 << endl;
    cout << m2 << endl;

    ~m1;
    cout << m1 << endl;

    SalaFitnessMembri m3 = m1;
    cout << m3 << endl;

    ++m2;
    cout << m2 << endl;

    return 0;
}
