#include <iostream>
#include <cstring>

using namespace std;

class ContBancar {
private:
    const int id;
    static int contor;

    string titular;
    string moneda;
    double sold;
    bool activ;
    char* tipCont;

public:
    // Constructor default
    ContBancar() : id(contor++) {
        this->titular = "";
        this->moneda = "RON";
        this->sold = 0;
        this->activ = false;
        this->tipCont = nullptr;
    }

    // Constructor cu parametri (cu valori default)
    ContBancar(string titular,
        string moneda,
        double sold,
        bool activ,
        const char* tipCont)
        : id(contor++) {
        this->titular = titular;
        this->moneda = moneda;
        this->sold = sold;
        this->activ = activ;

        if (tipCont != nullptr) {
            this->tipCont = new char[strlen(tipCont) + 1];
            strcpy_s(this->tipCont, strlen(tipCont) + 1, tipCont);
        }
        else {
            this->tipCont = nullptr;
        }
    }

    // Constructor de copiere
    ContBancar(const ContBancar& c) : id(c.id) {
        this->titular = c.titular;
        this->moneda = c.moneda;
        this->sold = c.sold;
        this->activ = c.activ;

        if (c.tipCont != nullptr) {
            this->tipCont = new char[strlen(c.tipCont) + 1];
            strcpy_s(this->tipCont, strlen(c.tipCont) + 1, c.tipCont);
        }
        else {
            this->tipCont = nullptr;
        }
    }

    // Destructor
    ~ContBancar() {
        if (this->tipCont != nullptr) {
            delete[] this->tipCont;
        }
    }

    // Operator =
    ContBancar& operator=(const ContBancar& c) {
        if (this == &c) {
            return *this;
        }

        if (this->tipCont != nullptr) {
            delete[] this->tipCont;
        }

        // id este const

        this->titular = c.titular;
        this->moneda = c.moneda;
        this->sold = c.sold;
        this->activ = c.activ;

        if (c.tipCont != nullptr) {
            this->tipCont = new char[strlen(c.tipCont) + 1];
            strcpy_s(this->tipCont, strlen(c.tipCont) + 1, c.tipCont);
        }
        else {
            this->tipCont = nullptr;
        }

        return *this;
    }

    // Getteri
    int getId() const {
        return this->id;
    }

    string getTitular() const {
        return this->titular;
    }

    string getMoneda() const {
        return this->moneda;
    }

    double getSold() const {
        return this->sold;
    }

    bool getActiv() const {
        return this->activ;
    }

    char* getTipCont() const {
        return this->tipCont;
    }

    // Setteri minimali
    void setSold(double soldNou) {
        this->sold = soldNou;
    }

    void setActiv(bool activNou) {
        this->activ = activNou;
    }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const ContBancar& c) {
        out << "ID: " << c.id << endl;
        out << "Titular: " << c.titular << endl;
        out << "Moneda: " << c.moneda << endl;
        out << "Sold: " << c.sold << endl;
        out << "Activ: " << (c.activ ? "DA" : "NU") << endl;
        out << "Tip cont: ";
        if (c.tipCont != nullptr) {
            out << c.tipCont;
        }
        else {
            out << "-";
        }
        out << endl;
        return out;
    }

    // Operator ! 
    bool operator!() const {
        return (this->sold < 0 || this->activ == false);
    }

    // Operator ~  (activ/inactiv)
    void operator~() {
        this->activ = !this->activ;
    }

    // Operator ++ (adauga dobanda)
    ContBancar& operator++() {
        this->sold = this->sold * 1.01;
        return *this;
    }
};

// initializare membru static
int ContBancar::contor = 1;

int main() {
    // Conturi create cu constructor cu parametri
    ContBancar c1("Popescu Ion", "RON", 1500.75, true, "Curent");
    ContBancar c2("Ionescu Maria", "EUR", -200.0, false, "Economii");

    cout << "=== Cont 1 ===" << endl;
    cout << c1 << endl;

    cout << "=== Cont 2 ===" << endl;
    cout << c2 << endl;

    // Testare operator !
    cout << "Contul 1 este in stare critica? "
        << (!c1 ? "DA" : "NU") << endl;
    cout << "Contul 2 este in stare critica? "
        << (!c2 ? "DA" : "NU") << endl << endl;

    // Testare operator ~ (activ/inactiv)
    cout << "Schimbam statusul activ pentru contul 2 cu ~c2..." << endl;
    ~c2;
    cout << c2 << endl;

    // Testare constructor de copiere
    cout << "=== Cont 3 (copie dupa c1) ===" << endl;
    ContBancar c3 = c1;
    cout << c3 << endl;

    // Testare operator =
    cout << "Dupa c3 = c2:" << endl;
    c3 = c2;
    cout << c3 << endl;

    // Testare ++ (dobanda)
    cout << "Aplicam ++c1 (dobanda 1%)..." << endl;
    ++c1;
    cout << c1 << endl;

    return 0;
}
