#include <iostream>
#include <vector>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// Functie pentru afisarea cerintelor
void afisareCerinta() {
    cout << "Proiect - Faza 5\n"
        << "-----------------\n"
        << "1. Creati o clasa noua care sa aiba cel putin un atribut de tipul unei clase existente (relatie de has-a).\n"
        << "2. Atributul poate fi un obiect, un pointer sau un vector de obiecte/pointeri.\n"
        << "3. Adaugati atribute suplimentare relevante pentru noua clasa.\n"
        << "4. Implementati geteri si seteri pentru toate atributele si 3 operatori la alegere.\n"
        << "5. Testati functionalitatea clasei in functia main.\n"
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

    // Geteri si seteri
    string getTipLentile() const { return tipLentile; }
    void setTipLentile(const string& tip) { tipLentile = tip; }

    const char* getMaterialRama() const { return materialRama; }
    void setMaterialRama(const char* material) {
        delete[] materialRama;
        materialRama = new char[strlen(material) + 1];
        strcpy(materialRama, material);
    }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Ochelari& o) {
        out << "Ochelari [Tip Lentile: " << o.tipLentile
            << ", Material Rama: " << o.materialRama
            << ", Cod Unic: " << o.codUnic << "]";
        return out;
    }
};
int Ochelari::numarOchelari = 0;

// ------------------------------------
// Clasa noua: Optica
// ------------------------------------
class Optica {
private:
    vector<Ochelari> ochelariDisponibili;  // Vector de obiecte Ochelari
    string locatie;                       // Atribut suplimentar
    int numarAngajati;                    // Atribut suplimentar

public:
    // Constructor fara parametri
    Optica() : locatie("Necunoscuta"), numarAngajati(0) {}

    // Constructor cu parametri
    Optica(string locatie, int numarAngajati, vector<Ochelari> ochelariDisponibili)
        : locatie(locatie), numarAngajati(numarAngajati), ochelariDisponibili(ochelariDisponibili) {}

    // Constructor de copiere
    Optica(const Optica& other)
        : locatie(other.locatie), numarAngajati(other.numarAngajati), ochelariDisponibili(other.ochelariDisponibili) {}

    // Destructor
    ~Optica() {}

    // Geteri si seteri
    string getLocatie() const { return locatie; }
    void setLocatie(const string& loc) { locatie = loc; }

    int getNumarAngajati() const { return numarAngajati; }
    void setNumarAngajati(int numar) { numarAngajati = numar; }

    vector<Ochelari> getOchelariDisponibili() const { return ochelariDisponibili; }
    void setOchelariDisponibili(const vector<Ochelari>& ochelari) { ochelariDisponibili = ochelari; }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Optica& opt) {
        out << "Optica [Locatie: " << opt.locatie
            << ", Numar Angajati: " << opt.numarAngajati
            << ", Numar Ochelari Disponibili: " << opt.ochelariDisponibili.size() << "]";
        return out;
    }

    // Supraincarcare operator +=
    Optica& operator+=(const Ochelari& o) {
        ochelariDisponibili.push_back(o);
        return *this;
    }

    // Supraincarcare operator ==
    bool operator==(const Optica& other) const {
        return locatie == other.locatie && numarAngajati == other.numarAngajati;
    }

    // Supraincarcare operator []
    Ochelari& operator[](int index) {
        if (index < 0 || index >= ochelariDisponibili.size()) {
            throw out_of_range("Index invalid!");
        }
        return ochelariDisponibili[index];
    }
};

// ------------------------------------
// Functia main
// ------------------------------------
int main() {
    afisareCerinta();

    // Creare vector de ochelari
    vector<Ochelari> ochelari = {
        Ochelari("Progresive", 101, "Metal"),
        Ochelari("Monofocale", 102, "Plastic"),
        Ochelari("Bifocale", 103, "Titan")
    };

    // Creare obiect Optica
    Optica optica1("Bucuresti", 5, ochelari);

    // Adaugare ochelari cu operatorul +=
    optica1 += Ochelari("Antireflex", 104, "Carbon");

    // Afisare obiect Optica
    cout << optica1 << endl;

    // Testare operator ==
    Optica optica2("Bucuresti", 5, ochelari);
    cout << (optica1 == optica2 ? "Opticile sunt identice" : "Opticile sunt diferite") << endl;

    // Testare operator []
    try {
        cout << "Primul ochelar din lista: " << optica1[0] << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}
