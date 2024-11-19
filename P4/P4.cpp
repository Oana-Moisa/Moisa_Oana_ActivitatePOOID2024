#include <iostream>
#include <vector>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// Functie pentru afisarea cerintelor
void afisareCerinta() {
    cout << "Proiect - Faza 4\n"
        << "-----------------\n"
        << "1. Creati 3 vectori in functia main:\n"
        << "   - Un vector cu obiecte de tipul primei clase.\n"
        << "   - Un vector cu obiecte de tipul celei de-a doua clase.\n"
        << "   - Un vector cu obiecte de tipul celei de-a treia clase.\n"
        << "2. Cititi obiectele pentru acesti vectori de la tastatura.\n"
        << "3. Afisati obiectele din fiecare vector la consola si parcurgeti vectorii separat.\n"
        << "4. Creati o matrice de obiecte pentru o clasa la alegere si afisati continutul ei.\n"
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

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Ochelari& o) {
        out << "Ochelari [Tip Lentile: " << o.tipLentile
            << ", Material Rama: " << o.materialRama
            << ", Cod Unic: " << o.codUnic << "]";
        return out;
    }

    // Supraincarcare operator >>
    friend istream& operator>>(istream& in, Ochelari& o) {
        char buffer[100];
        cout << "Introduceti tipul lentilelor: ";
        in >> o.tipLentile;
        cout << "Introduceti materialul ramei: ";
        in >> buffer;
        delete[] o.materialRama;
        o.materialRama = new char[strlen(buffer) + 1];
        strcpy(o.materialRama, buffer);
        return in;
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

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Lentile& l) {
        out << "Lentile [Tip Material: " << l.tipMaterial
            << ", Diametru: " << l.diametru
            << ", Prescriptie: " << l.prescriptie
            << ", Cod Serie: " << l.codSerie << "]";
        return out;
    }

    // Supraincarcare operator >>
    friend istream& operator>>(istream& in, Lentile& l) {
        char buffer[100];
        cout << "Introduceti tipul materialului: ";
        in >> l.tipMaterial;
        cout << "Introduceti diametrul: ";
        in >> l.diametru;
        cout << "Introduceti prescriptia: ";
        in >> buffer;
        delete[] l.prescriptie;
        l.prescriptie = new char[strlen(buffer) + 1];
        strcpy(l.prescriptie, buffer);
        return in;
    }
};
int Lentile::numarLentile = 0;

// ------------------------------------
// Functia main
// ------------------------------------
int main() {
    afisareCerinta();

    // Vector pentru obiecte de tip Ochelari
    vector<Ochelari> vectorOchelari(3);
    cout << "Citire obiecte pentru vectorul de ochelari:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Ochelari " << i + 1 << ":\n";
        cin >> vectorOchelari[i];
    }

    cout << "\nAfisare obiecte din vectorul de ochelari:\n";
    for (const auto& o : vectorOchelari) {
        cout << o << endl;
    }

    // Vector pentru obiecte de tip Lentile
    vector<Lentile> vectorLentile(3);
    cout << "\nCitire obiecte pentru vectorul de lentile:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Lentile " << i + 1 << ":\n";
        cin >> vectorLentile[i];
    }

    cout << "\nAfisare obiecte din vectorul de lentile:\n";
    for (const auto& l : vectorLentile) {
        cout << l << endl;
    }

    // Matrice pentru obiecte de tip Ochelari
    Ochelari matriceOchelari[2][2];
    cout << "\nCitire obiecte pentru matricea de ochelari:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "Ochelari [" << i + 1 << "][" << j + 1 << "]:\n";
            cin >> matriceOchelari[i][j];
        }
    }

    cout << "\nAfisare obiecte din matricea de ochelari:\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "Ochelari [" << i + 1 << "][" << j + 1 << "]: " << matriceOchelari[i][j] << endl;
        }
    }

    return 0;
}
