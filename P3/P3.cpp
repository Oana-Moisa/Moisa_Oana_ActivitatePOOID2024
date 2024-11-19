#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// Functie pentru afisarea cerintelor
void afisareCerinta() {
    cout << "Proiect - Faza 3\n"
        << "-----------------\n"
        << "1. Supraincarcati operatorul = (de atribuire) pentru toate clasele.\n"
        << "2. Supraincarcati minim alti trei operatori diferiti pentru fiecare clasa.\n"
        << "   Exemple: +, -, ==, !=, <, >, [].\n"
        << "3. Creati cel putin o functie prietena pentru fiecare clasa.\n"
        << "4. In functia main, apelati atat functiile prietene, cat si toti operatorii supraincarcati.\n"
        << "-----------------\n\n";
}

// ------------------------------------
// Clasa 1: Ochelari de vedere
// ------------------------------------
class Ochelari {
private:
    string tipLentile;
    char* materialRama;
    const int codUnic;
    static int numarOchelari;

public:
    // Constructor fara parametri
    Ochelari() : codUnic(0) {
        tipLentile = "Monofocale";
        materialRama = new char[strlen("Plastic") + 1];
        strcpy(materialRama, "Plastic");
        numarOchelari++;
    }

    // Constructor cu parametri
    Ochelari(string tipLentile, const int codUnic, const char* materialRama) : codUnic(codUnic) {
        this->tipLentile = tipLentile;
        this->materialRama = new char[strlen(materialRama) + 1];
        strcpy(this->materialRama, materialRama);
        numarOchelari++;
    }

    // Constructor de copiere
    Ochelari(const Ochelari& other) : codUnic(other.codUnic) {
        tipLentile = other.tipLentile;
        materialRama = new char[strlen(other.materialRama) + 1];
        strcpy(materialRama, other.materialRama);
        numarOchelari++;
    }

    // Destructor
    ~Ochelari() {
        delete[] materialRama;
        numarOchelari--;
    }

    // Operator de atribuire
    Ochelari& operator=(const Ochelari& other) {
        if (this != &other) {
            delete[] materialRama;
            tipLentile = other.tipLentile;
            materialRama = new char[strlen(other.materialRama) + 1];
            strcpy(materialRama, other.materialRama);
        }
        return *this;
    }

    // Operator de comparatie ==
    bool operator==(const Ochelari& other) const {
        return tipLentile == other.tipLentile && strcmp(materialRama, other.materialRama) == 0;
    }

    // Operator de adaugare +
    Ochelari operator+(const string& extraTip) const {
        Ochelari rezultat = *this;
        rezultat.tipLentile += " + " + extraTip;
        return rezultat;
    }

    // Operator de indexare []
    char operator[](int index) const {
        if (index < 0 || index >= strlen(materialRama)) {
            throw out_of_range("Index invalid!");
        }
        return materialRama[index];
    }

    // Functie prietena
    friend ostream& operator<<(ostream& out, const Ochelari& o) {
        out << "Ochelari [Tip Lentile: " << o.tipLentile
            << ", Material Rama: " << o.materialRama
            << ", Cod Unic: " << o.codUnic << "]";
        return out;
    }
};
int Ochelari::numarOchelari = 0;

// ------------------------------------
// Clasa 2: Lentile de contact
// ------------------------------------
class Lentile {
private:
    string tipMaterial;
    float diametru;
    char* prescriptie;
    const int codSerie;
    static int numarLentile;

public:
    // Constructor fara parametri
    Lentile() : codSerie(0) {
        tipMaterial = "Silicon";
        diametru = 14.0f;
        prescriptie = new char[strlen("General") + 1];
        strcpy(prescriptie, "General");
        numarLentile++;
    }

    // Constructor cu parametri
    Lentile(string tipMaterial, float diametru, const char* prescriptie, int codSerie) : codSerie(codSerie) {
        this->tipMaterial = tipMaterial;
        this->diametru = diametru;
        this->prescriptie = new char[strlen(prescriptie) + 1];
        strcpy(this->prescriptie, prescriptie);
        numarLentile++;
    }

    // Destructor
    ~Lentile() {
        delete[] prescriptie;
        numarLentile--;
    }

    // Operator de atribuire
    Lentile& operator=(const Lentile& other) {
        if (this != &other) {
            delete[] prescriptie;
            tipMaterial = other.tipMaterial;
            diametru = other.diametru;
            prescriptie = new char[strlen(other.prescriptie) + 1];
            strcpy(prescriptie, other.prescriptie);
        }
        return *this;
    }

    // Operator de comparatie <
    bool operator<(const Lentile& other) const {
        return diametru < other.diametru;
    }

    // Operator de scadere -
    Lentile operator-(float reducereDiametru) const {
        Lentile rezultat = *this;
        rezultat.diametru -= reducereDiametru;
        if (rezultat.diametru < 0) rezultat.diametru = 0;
        return rezultat;
    }

    // Operator de concatenare +
    Lentile operator+(const string& extraPrescriptie) const {
        Lentile rezultat = *this;
        rezultat.tipMaterial += " + " + extraPrescriptie;
        return rezultat;
    }

    // Functie prietena
    friend ostream& operator<<(ostream& out, const Lentile& l) {
        out << "Lentile [Tip Material: " << l.tipMaterial
            << ", Diametru: " << l.diametru
            << ", Prescriptie: " << l.prescriptie
            << ", Cod Serie: " << l.codSerie << "]";
        return out;
    }
};
int Lentile::numarLentile = 0;

// ------------------------------------
// Functia main
// ------------------------------------
int main() {
    afisareCerinta();

    // Testare operatori Ochelari
    Ochelari o1("Progresive", 101, "Metal");
    Ochelari o2 = o1;
    Ochelari o3 = o1 + "Anti-reflex";
    cout << (o1 == o2 ? "Ochelarii sunt identici" : "Ochelarii sunt diferiti") << endl;
    cout << "Primul caracter al ramei: " << o1[0] << endl;
    cout << o3 << endl;

    // Testare operatori Lentile
    Lentile l1("Hidrogel", 12.5, "Miopie", 202);
    Lentile l2 = l1 - 2.0f;
    Lentile l3 = l1 + "Astigmatism";
    cout << (l1 < l2 ? "L1 este mai mica decat L2" : "L1 nu este mai mica") << endl;
    cout << l3 << endl;

    return 0;
}
