#include <iostream>
#include <cstring>
using namespace std;

class ComandaRestaurant {
private:
    const int id;
    static int nextId;

    string numeClient;
    int nrProduse;
    double total;
    bool livrata;
    char* metodaPlata;

public:
    ComandaRestaurant() : id(nextId++) {
        numeClient = "";
        nrProduse = 0;
        total = 0;
        livrata = false;
        metodaPlata = nullptr;
    }

    ComandaRestaurant(string numeClient, int nrProduse, double total, bool livrata, const char* metodaPlata)
        : id(nextId++) {
        this->numeClient = numeClient;
        this->nrProduse = nrProduse;
        this->total = total;
        this->livrata = livrata;

        if (metodaPlata != nullptr) {
            this->metodaPlata = new char[strlen(metodaPlata) + 1];
            strcpy_s(this->metodaPlata, strlen(metodaPlata) + 1, metodaPlata);
        }
        else {
            this->metodaPlata = nullptr;
        }
    }

    ComandaRestaurant(const ComandaRestaurant& c) : id(c.id) {
        numeClient = c.numeClient;
        nrProduse = c.nrProduse;
        total = c.total;
        livrata = c.livrata;

        if (c.metodaPlata != nullptr) {
            metodaPlata = new char[strlen(c.metodaPlata) + 1];
            strcpy_s(metodaPlata, strlen(c.metodaPlata) + 1, c.metodaPlata);
        }
        else {
            metodaPlata = nullptr;
        }
    }

    ~ComandaRestaurant() {
        if (metodaPlata != nullptr)
            delete[] metodaPlata;
    }

    ComandaRestaurant& operator=(const ComandaRestaurant& c) {
        if (this == &c) return *this;

        if (metodaPlata != nullptr) delete[] metodaPlata;

        numeClient = c.numeClient;
        nrProduse = c.nrProduse;
        total = c.total;
        livrata = c.livrata;

        if (c.metodaPlata != nullptr) {
            metodaPlata = new char[strlen(c.metodaPlata) + 1];
            strcpy_s(metodaPlata, strlen(c.metodaPlata) + 1, c.metodaPlata);
        }
        else {
            metodaPlata = nullptr;
        }

        return *this;
    }

    int getId() const { return id; }
    string getNumeClient() const { return numeClient; }
    int getNrProduse() const { return nrProduse; }
    double getTotal() const { return total; }
    bool getLivrata() const { return livrata; }
    const char* getMetodaPlata() const { return metodaPlata; }

    void setNrProduse(int n) { nrProduse = n; }
    void setTotal(double t) { total = t; }
    void setLivrata(bool l) { livrata = l; }

    void setMetodaPlata(const char* m) {
        if (metodaPlata != nullptr) delete[] metodaPlata;
        if (m != nullptr) {
            metodaPlata = new char[strlen(m) + 1];
            strcpy_s(metodaPlata, strlen(metodaPlata) + 1, m);
        }
        else {
            metodaPlata = nullptr;
        }
    }

    friend ostream& operator<<(ostream& out, const ComandaRestaurant& c) {
        out << "ID: " << c.id << endl;
        out << "Client: " << c.numeClient << endl;
        out << "Produse: " << c.nrProduse << endl;
        out << "Total: " << c.total << endl;
        out << "Livrata: " << (c.livrata ? "DA" : "NU") << endl;
        out << "Metoda plata: " << (c.metodaPlata ? c.metodaPlata : "-") << endl;
        return out;
    }

    bool operator!() const {
        return total == 0;
    }

    void operator~() {
        livrata = !livrata;
    }

    ComandaRestaurant& operator++() {
        nrProduse++;
        return *this;
    }
};

int ComandaRestaurant::nextId = 1;

int main() {
    ComandaRestaurant r1("Popescu Ion", 3, 75.5, false, "Card");
    ComandaRestaurant r2("Ionescu Ana", 0, 0, false, "Cash");

    cout << r1 << endl;
    cout << r2 << endl;

    ~r1;
    cout << r1 << endl;

    ComandaRestaurant r3 = r1;
    cout << r3 << endl;

    ++r2;
    cout << r2 << endl;

    return 0;
}
