#include <iostream>
#include <cstring>
using namespace std;

class EvenimentAgenda {
private:
    const int id;
    static int nextId;

    string titlu;
    int durata;
    double cost;
    bool confirmat;
    char* locatie;

public:
    EvenimentAgenda() : id(nextId++) {
        titlu = "";
        durata = 0;
        cost = 0;
        confirmat = false;
        locatie = nullptr;
    }

    EvenimentAgenda(string titlu, int durata, double cost, bool confirmat, const char* locatie)
        : id(nextId++) {

        this->titlu = titlu;
        this->durata = durata;
        this->cost = cost;
        this->confirmat = confirmat;

        if (locatie != nullptr) {
            this->locatie = new char[strlen(locatie) + 1];
            strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
        }
        else {
            this->locatie = nullptr;
        }
    }

    EvenimentAgenda(const EvenimentAgenda& e) : id(e.id) {
        titlu = e.titlu;
        durata = e.durata;
        cost = e.cost;
        confirmat = e.confirmat;

        if (e.locatie != nullptr) {
            locatie = new char[strlen(e.locatie) + 1];
            strcpy_s(locatie, strlen(e.locatie) + 1, e.locatie);
        }
        else {
            locatie = nullptr;
        }
    }

    ~EvenimentAgenda() {
        if (locatie != nullptr)
            delete[] locatie;
    }

    EvenimentAgenda& operator=(const EvenimentAgenda& e) {
        if (this == &e) return *this;

        if (locatie != nullptr) delete[] locatie;

        titlu = e.titlu;
        durata = e.durata;
        cost = e.cost;
        confirmat = e.confirmat;

        if (e.locatie != nullptr) {
            locatie = new char[strlen(e.locatie) + 1];
            strcpy_s(locatie, strlen(e.locatie) + 1, e.locatie);
        }
        else {
            locatie = nullptr;
        }

        return *this;
    }

    int getId() const { return id; }
    string getTitlu() const { return titlu; }
    int getDurata() const { return durata; }
    double getCost() const { return cost; }
    bool getConfirmat() const { return confirmat; }
    const char* getLocatie() const { return locatie; }

    void setDurata(int d) { durata = d; }
    void setCost(double c) { cost = c; }
    void setConfirmat(bool c) { confirmat = c; }

    void setLocatie(const char* l) {
        if (locatie != nullptr) delete[] locatie;
        if (l != nullptr) {
            locatie = new char[strlen(l) + 1];
            strcpy_s(locatie, strlen(locatie) + 1, l);
        }
        else {
            locatie = nullptr;
        }
    }

    friend ostream& operator<<(ostream& out, const EvenimentAgenda& e) {
        out << "ID: " << e.id << endl;
        out << "Titlu: " << e.titlu << endl;
        out << "Durata: " << e.durata << " min" << endl;
        out << "Cost: " << e.cost << endl;
        out << "Confirmat: " << (e.confirmat ? "DA" : "NU") << endl;
        out << "Locatie: " << (e.locatie ? e.locatie : "-") << endl;
        return out;
    }

    bool operator!() const {
        return durata == 0;
    }

    void operator~() {
        confirmat = !confirmat;
    }

    EvenimentAgenda& operator++() {
        durata++;
        return *this;
    }
};

int EvenimentAgenda::nextId = 1;

int main() {
    EvenimentAgenda e1("Sedinta", 60, 0, true, "Sala 201");
    EvenimentAgenda e2("Prezentare", 0, 150, false, "Amfiteatru");

    cout << e1 << endl;
    cout << e2 << endl;

    ~e1;
    cout << e1 << endl;

    EvenimentAgenda e3 = e1;
    cout << e3 << endl;

    ++e2;
    cout << e2 << endl;

    return 0;
}
