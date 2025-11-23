#include <iostream>
#include <cstring>
using namespace std;

class RezervareHotel {
private:
    const int id;
    static int nextId;

    string numeClient;
    int nopti;
    bool confirmata;
    double pretTotal;
    char* tipCamera;

public:
    RezervareHotel() : id(nextId++) {
        numeClient = "";
        nopti = 0;
        confirmata = false;
        pretTotal = 0;
        tipCamera = nullptr;
    }

    RezervareHotel(string numeClient, int nopti, bool confirmata, double pretTotal, const char* tipCamera)
        : id(nextId++) {
        this->numeClient = numeClient;
        this->nopti = nopti;
        this->confirmata = confirmata;
        this->pretTotal = pretTotal;

        if (tipCamera != nullptr) {
            this->tipCamera = new char[strlen(tipCamera) + 1];
            strcpy_s(this->tipCamera, strlen(tipCamera) + 1, tipCamera);
        }
        else {
            this->tipCamera = nullptr;
        }
    }

    RezervareHotel(const RezervareHotel& r) : id(r.id) {
        numeClient = r.numeClient;
        nopti = r.nopti;
        confirmata = r.confirmata;
        pretTotal = r.pretTotal;

        if (r.tipCamera != nullptr) {
            tipCamera = new char[strlen(r.tipCamera) + 1];
            strcpy_s(tipCamera, strlen(r.tipCamera) + 1, r.tipCamera);
        }
        else {
            tipCamera = nullptr;
        }
    }

    ~RezervareHotel() {
        if (tipCamera != nullptr)
            delete[] tipCamera;
    }

    RezervareHotel& operator=(const RezervareHotel& r) {
        if (this == &r) return *this;

        if (tipCamera != nullptr) delete[] tipCamera;

        numeClient = r.numeClient;
        nopti = r.nopti;
        confirmata = r.confirmata;
        pretTotal = r.pretTotal;

        if (r.tipCamera != nullptr) {
            tipCamera = new char[strlen(r.tipCamera) + 1];
            strcpy_s(tipCamera, strlen(r.tipCamera) + 1, r.tipCamera);
        }
        else {
            tipCamera = nullptr;
        }

        return *this;
    }

    int getId() const { return id; }
    string getNumeClient() const { return numeClient; }
    int getNopti() const { return nopti; }
    bool getConfirmata() const { return confirmata; }
    double getPretTotal() const { return pretTotal; }
    const char* getTipCamera() const { return tipCamera; }

    void setNopti(int n) { nopti = n; }
    void setConfirmata(bool c) { confirmata = c; }
    void setPretTotal(double p) { pretTotal = p; }

    void setTipCamera(const char* t) {
        if (tipCamera != nullptr) delete[] tipCamera;
        if (t != nullptr) {
            tipCamera = new char[strlen(t) + 1];
            strcpy_s(tipCamera, strlen(t) + 1, t);
        }
        else {
            tipCamera = nullptr;
        }
    }

    friend ostream& operator<<(ostream& out, const RezervareHotel& r) {
        out << "ID: " << r.id << endl;
        out << "Nume client: " << r.numeClient << endl;
        out << "Nopti: " << r.nopti << endl;
        out << "Confirmata: " << (r.confirmata ? "DA" : "NU") << endl;
        out << "Pret total: " << r.pretTotal << endl;
        out << "Tip camera: " << (r.tipCamera ? r.tipCamera : "-") << endl;
        return out;
    }

    bool operator!() const {
        return !confirmata || pretTotal <= 0;
    }

    void operator~() {
        confirmata = !confirmata;
    }

    RezervareHotel& operator++() {
        nopti++;
        pretTotal += 100;
        return *this;
    }
};

int RezervareHotel::nextId = 1;

int main() {
    RezervareHotel r1("Popescu Ana", 3, true, 900, "Double");
    RezervareHotel r2("Ionescu Mihai", 0, false, 0, "Single");

    cout << r1 << endl;
    cout << r2 << endl;

    cout << (!r2 ? "Rezervare invalida" : "Rezervare valida") << endl;

    ~r1;
    cout << r1 << endl;

    RezervareHotel r3 = r1;
    cout << r3 << endl;

    ++r2;
    cout << r2 << endl;

    return 0;
}
