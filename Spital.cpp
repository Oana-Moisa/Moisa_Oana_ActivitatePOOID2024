#include <iostream>
#include <cstring>

using namespace std;

class Pacient {
private:
    const int id;          // ID unic, constant
    static int nextId;     // generator de ID-uri

    string nume;
    int varsta;
    bool internat;
    int zileSpitalizare;
    char* diagnostic;      // sir de caractere alocat dinamic

public:
    // Constructor default
    Pacient() : id(nextId++) {
        this->nume = "";
        this->varsta = 0;
        this->internat = false;
        this->zileSpitalizare = 0;
        this->diagnostic = nullptr;
    }

    // Constructor cu parametri
    Pacient(string nume,
        int varsta,
        bool internat,
        int zileSpitalizare,
        const char* diagnostic)
        : id(nextId++) {
        this->nume = nume;
        this->varsta = varsta;
        this->internat = internat;
        this->zileSpitalizare = zileSpitalizare;

        if (diagnostic != nullptr) {
            this->diagnostic = new char[strlen(diagnostic) + 1];
            strcpy_s(this->diagnostic, strlen(diagnostic) + 1, diagnostic);
        }
        else {
            this->diagnostic = nullptr;
        }
    }

    // Constructor de copiere
    Pacient(const Pacient& p) : id(p.id) {
        this->nume = p.nume;
        this->varsta = p.varsta;
        this->internat = p.internat;
        this->zileSpitalizare = p.zileSpitalizare;

        if (p.diagnostic != nullptr) {
            this->diagnostic = new char[strlen(p.diagnostic) + 1];
            strcpy_s(this->diagnostic, strlen(p.diagnostic) + 1, p.diagnostic);
        }
        else {
            this->diagnostic = nullptr;
        }
    }

    // Destructor
    ~Pacient() {
        if (this->diagnostic != nullptr) {
            delete[] this->diagnostic;
        }
    }

    // Operator =
    Pacient& operator=(const Pacient& p) {
        if (this == &p) {
            return *this;
        }

        if (this->diagnostic != nullptr) {
            delete[] this->diagnostic;
        }

        // id este const, nu se reasigneazã
        this->nume = p.nume;
        this->varsta = p.varsta;
        this->internat = p.internat;
        this->zileSpitalizare = p.zileSpitalizare;

        if (p.diagnostic != nullptr) {
            this->diagnostic = new char[strlen(p.diagnostic) + 1];
            strcpy_s(this->diagnostic, strlen(p.diagnostic) + 1, p.diagnostic);
        }
        else {
            this->diagnostic = nullptr;
        }

        return *this;
    }

    // Getteri
    int getId() const {
        return this->id;
    }

    string getNume() const {
        return this->nume;
    }

    int getVarsta() const {
        return this->varsta;
    }

    bool getInternat() const {
        return this->internat;
    }

    int getZileSpitalizare() const {
        return this->zileSpitalizare;
    }

    const char* getDiagnostic() const {
        return this->diagnostic;
    }

    // Setteri (pentru câmpuri modificabile)
    void setNume(const string& numeNou) {
        this->nume = numeNou;
    }

    void setVarsta(int varstaNoua) {
        this->varsta = varstaNoua;
    }

    void setInternat(bool internatNou) {
        this->internat = internatNou;
    }

    void setZileSpitalizare(int zile) {
        this->zileSpitalizare = zile;
    }

    void setDiagnostic(const char* diagNou) {
        if (this->diagnostic != nullptr) {
            delete[] this->diagnostic;
        }
        if (diagNou != nullptr) {
            this->diagnostic = new char[strlen(diagNou) + 1];
            strcpy_s(this->diagnostic, strlen(diagNou) + 1, diagNou);
        }
        else {
            this->diagnostic = nullptr;
        }
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Pacient& p) {
        out << "ID: " << p.id << endl;
        out << "Nume: " << p.nume << endl;
        out << "Varsta: " << p.varsta << " ani" << endl;
        out << "Internat: " << (p.internat ? "DA" : "NU") << endl;
        out << "Zile spitalizare: " << p.zileSpitalizare << endl;
        out << "Diagnostic: ";
        if (p.diagnostic != nullptr) {
            out << p.diagnostic;
        }
        else {
            out << "-";
        }
        out << endl;
        return out;
    }

    // Operator ! 
    // Considerãm "caz critic" dacã pacientul este internat ?i are peste 10 zile de spitalizare
    bool operator!() const {
        return (this->internat && this->zileSpitalizare > 10);
    }

    // Operator ~
    // Inverseazã statusul de internare (externare / reinternare)
    void operator~() {
        this->internat = !this->internat;
    }

    // Operator ++ prefix
    // Cre?te cu o zi perioada de spitalizare
    Pacient& operator++() {
        this->zileSpitalizare++;
        return *this;
    }

    // Operator -- prefix (nu lasã zilele sa scadã sub 0)
    Pacient& operator--() {
        if (this->zileSpitalizare > 0) {
            this->zileSpitalizare--;
        }
        return *this;
    }
};

// Ini?ializare membru static
int Pacient::nextId = 1;

int main() {
    // Pacient creat cu constructor cu parametri
    Pacient p1("Ionescu Mihai", 45, true, 5, "Pneumonie");
    Pacient p2("Popescu Ana", 30, true, 12, "Interventie chirurgicala");

    cout << "=== Pacient 1 ===" << endl;
    cout << p1 << endl;

    cout << "=== Pacient 2 ===" << endl;
    cout << p2 << endl;

    // Testare operator !
    cout << "Pacientul 1 este caz critic? " << (!p1 ? "DA" : "NU") << endl;
    cout << "Pacientul 2 este caz critic? " << (!p2 ? "DA" : "NU") << endl << endl;

    // Testare operator ~ (toggle internat)
    cout << "Aplicam ~p1 (schimbam statusul de internare)..." << endl;
    ~p1;
    cout << p1 << endl;

    // Testare constructor de copiere
    cout << "=== Pacient 3 (copie dupa p2) ===" << endl;
    Pacient p3 = p2;
    cout << p3 << endl;

    // Testare operator =
    cout << "Dupa p3 = p1:" << endl;
    p3 = p1;
    cout << p3 << endl;

    // Testare ++ ?i --
    cout << "Aplicam ++p2 (mai trece o zi de spitalizare)..." << endl;
    ++p2;
    cout << p2 << endl;

    cout << "Aplicam --p2 (corectam numarul de zile)..." << endl;
    --p2;
    cout << p2 << endl;

    // Testare setDiagnostic
    cout << "Actualizam diagnosticul pentru p1..." << endl;
    p1.setDiagnostic("Stare imbunatatita, pregatit pentru externare");
    cout << p1 << endl;

    return 0;
}
