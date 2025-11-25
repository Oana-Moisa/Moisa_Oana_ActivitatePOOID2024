#include <iostream>
#include <cstring>
using namespace std;

class Abonament {
private:
    const int id;
    static int nextId;

    string client;
    double pret;
    bool activ;
    int luni;
    char* tip;

public:
    Abonament() : id(nextId++) {
        client = "";
        pret = 0;
        activ = false;
        luni = 0;
        tip = nullptr;
    }

    Abonament(string client, double pret, bool activ, int luni, const char* tip)
        : id(nextId++) {
        this->client = client;
        this->pret = pret;
        this->activ = activ;
        this->luni = luni;

        if (tip != nullptr) {
            this->tip = new char[strlen(tip) + 1];
            strcpy_s(this->tip, strlen(tip) + 1, tip);
        }
        else {
            this->tip = nullptr;
        }
    }

    Abonament(const Abonament& a) : id(a.id) {
        client = a.client;
        pret = a.pret;
        activ = a.activ;
        luni = a.luni;

        if (a.tip != nullptr) {
            tip = new char[strlen(a.tip) + 1];
            strcpy_s(tip, strlen(a.tip) + 1, a.tip);
        }
        else {
            tip = nullptr;
        }
    }

    ~Abonament() {
        if (tip != nullptr)
            delete[] tip;
    }

    Abonament& operator=(const Abonament& a) {
        if (this == &a) return *this;

        if (tip != nullptr) delete[] tip;

        client = a.client;
        pret = a.pret;
        activ = a.activ;
        luni = a.luni;

        if (a.tip != nullptr) {
            tip = new char[strlen(a.tip) + 1];
            strcpy_s(tip, strlen(a.tip) + 1, a.tip);
        }
        else {
            tip = nullptr;
        }

        return *this;
    }

    int getId() const { return id; }
    string getClient() const { return client; }
    double getPret() const { return pret; }
    bool getActiv() const { return activ; }
    int getLuni() const { return luni; }
    const char* getTip() const { return tip; }

    void setPret(double p) { pret = p; }
    void setActiv(bool a) { activ = a; }
    void setLuni(int l) { luni = l; }

    void setTip(const char* t) {
        if (tip != nullptr) delete[] tip;
        if (t != nullptr) {
            tip = new char[strlen(t) + 1];
            strcpy_s(tip, strlen(t) + 1, t);
        }
        else {
            tip = nullptr;
        }
    }

    friend ostream& operator<<(ostream& out, const Abonament& a) {
        out << "ID: " << a.id << endl;
        out << "Client: " << a.client << endl;
        out << "Pret: " << a.pret << endl;
        out << "Activ: " << (a.activ ? "DA" : "NU") << endl;
        out << "Luni: " << a.luni << endl;
        out << "Tip: " << (a.tip ? a.tip : "-") << endl;
        return out;
    }

    bool operator!() const {
        return !activ || pret <= 0;
    }

    void operator~() {
        activ = !activ;
    }

    Abonament& operator++() {
        luni++;
        pret += 10;
        return *this;
    }
};

int Abonament::nextId = 1;

int main() {
    Abonament a1("Popescu Ion", 120, true, 6, "Standard");
    Abonament a2("Ionescu Maria", 0, false, 0, "Basic");

    cout << a1 << endl;
    cout << a2 << endl;

    cout << (!a2 ? "Abonament invalid" : "Abonament valid") << endl;

    ~a1;
    cout << a1 << endl;

    Abonament a3 = a1;
    cout << a3 << endl;

    ++a2;
    cout << a2 << endl;

    return 0;
}
