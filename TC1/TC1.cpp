/*
Cerintele clasei Autobuz:
1. Clasa are: nrAutobuze (static), idAutobuz (constant), capacitate, numarCalatori, producator.
2. Constructori: implicit, cu parametri (validari), de copiere.
3. Destructor elibereaza memoria pentru producator.
4. Operatorii: =, <<, >, cast la int.
5. Metoda getNumarLocuriLibere() calculeaza locurile ramase.
*/

#include <iostream> // Biblioteca pentru input si output standard
#include <cstring>  // Biblioteca pentru lucrul cu siruri de caractere
#define _CRT_SECURE_NO_WARNINGS // Dezactiveaza avertismentele legate de strcpy_s
using namespace std;

// Definirea clasei Autobuz
class Autobuz {
private:
    static int nrAutobuze;         // Contor static pentru numarul total de autobuze
    const int idAutobuz;           // ID unic al autobuzului (constant)
    int capacitate;                // Capacitatea maxima a autobuzului
    int numarCalatori;             // Numarul curent de calatori
    char* producator;              // Numele producatorului (alocat dinamic)

public:
    // Constructor implicit
    Autobuz() : idAutobuz(++nrAutobuze) {
        capacitate = 50; // Capacitatea default
        numarCalatori = 0; // Fara calatori initial
        producator = new char[strlen("Necunoscut") + 1]; // Aloc memorie pentru producator
        strcpy_s(producator, strlen("Necunoscut") + 1, "Necunoscut"); // Setez producatorul implicit
    }

    // Constructor cu parametri
    Autobuz(int capacitate, int numarCalatori, const char* producator) : idAutobuz(++nrAutobuze) {
        this->capacitate = (capacitate > 0) ? capacitate : 50; // Validare capacitate
        this->numarCalatori = (numarCalatori >= 0 && numarCalatori <= capacitate) ? numarCalatori : 0; // Validare numar calatori
        this->producator = new char[strlen(producator) + 1]; // Aloc memorie pentru producator
        strcpy_s(this->producator, strlen(producator) + 1, producator); // Copiez numele producatorului
    }

    // Constructor de copiere
    Autobuz(const Autobuz& autobuz) : idAutobuz(++nrAutobuze) {
        this->capacitate = autobuz.capacitate; // Copiez capacitatea
        this->numarCalatori = autobuz.numarCalatori; // Copiez numarul de calatori
        this->producator = new char[strlen(autobuz.producator) + 1]; // Aloc memorie pentru producator
        strcpy_s(this->producator, strlen(autobuz.producator) + 1, autobuz.producator); // Copiez numele producatorului
    }

    // Destructor
    ~Autobuz() {
        delete[] producator; // Eliberez memoria alocata pentru producator
    }

    // Getter pentru capacitate
    int getCapacitate() const { return capacitate; }

    // Setter pentru capacitate
    void setCapacitate(int capacitate) {
        if (capacitate > 0) {
            this->capacitate = capacitate;
        }
    }

    // Getter pentru producator
    const char* getProducator() const { return producator; }

    // Setter pentru producator
    void setProducator(const char* producator) {
        delete[] this->producator; // Eliberez memoria veche
        this->producator = new char[strlen(producator) + 1]; // Aloc memorie noua
        strcpy_s(this->producator, strlen(producator) + 1, producator); // Copiez numele noului producator
    }

    // Operator de atribuire
    Autobuz& operator=(const Autobuz& autobuz) {
        if (this != &autobuz) { // Evit auto-atribuirea
            this->capacitate = autobuz.capacitate;
            this->numarCalatori = autobuz.numarCalatori;
            delete[] this->producator; // Eliberez memoria veche
            this->producator = new char[strlen(autobuz.producator) + 1];
            strcpy_s(this->producator, strlen(autobuz.producator) + 1, autobuz.producator); // Copiez numele producatorului
        }
        return *this;
    }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Autobuz& autobuz) {
        out << autobuz.idAutobuz << "; " << autobuz.capacitate << "; "
            << autobuz.numarCalatori << "; " << autobuz.producator;
        return out;
    }

    // Metoda care calculeaza locurile libere
    int getNumarLocuriLibere() const {
        return capacitate - numarCalatori;
    }

    // Operator de cast la int
    operator int() const { return numarCalatori; }

    // Supraincarcare operator >
    bool operator>(const Autobuz& autobuz) const {
        return this->capacitate > autobuz.capacitate;
    }
};

// Initializare variabila statica
int Autobuz::nrAutobuze = 0;

int main() {
    Autobuz autobuz1;
    Autobuz autobuz2(60, 30, "DaciaBus");
    Autobuz autobuz3 = autobuz2;

    cout << "Producator initial: " << autobuz1.getProducator() << endl;
    autobuz1.setProducator("CarpatBus");
    cout << "Producator modificat: " << autobuz1.getProducator() << endl;

    cout << "Afisare autobuz1: " << autobuz1 << endl;
    cout << "Locuri libere autobuz2: " << autobuz2.getNumarLocuriLibere() << endl;
    cout << "Calatori in autobuz2: " << (int)autobuz2 << endl;

    if (autobuz2 > autobuz1) {
        cout << "Autobuzul 2 are capacitate mai mare" << endl;
    }
    else {
        cout << "Autobuzul 1 are capacitate mai mare sau egala" << endl;
    }

    cout << "Enter pentru a inchide programul" << endl;
    cin.get();
    return 0;
}
