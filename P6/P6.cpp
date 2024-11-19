#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// Functie pentru afisarea cerintelor
void afisareCerinta() {
    cout << "Proiect - Faza 6\n"
        << "-----------------\n"
        << "1. Adaugati metode sau operatori pentru lucru cu fisiere text in cel putin doua clase.\n"
        << "2. Adaugati metode sau operatori pentru lucru cu fisiere binare in cel putin alte doua clase.\n"
        << "3. Testati functionalitatea metodelor in functia main.\n"
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

    // Metoda pentru scriere in fisier text
    void scrieInFisierText(const string& numeFisier) const {
        ofstream fout(numeFisier, ios::app);
        if (fout.is_open()) {
            fout << "Ochelari [Tip Lentile: " << tipLentile
                << ", Material Rama: " << materialRama
                << ", Cod Unic: " << codUnic << "]\n";
            fout.close();
        }
        else {
            cout << "Eroare la deschiderea fisierului " << numeFisier << endl;
        }
    }

    // Metoda pentru citire din fisier text
    void citesteDinFisierText(const string& numeFisier) {
        ifstream fin(numeFisier);
        if (fin.is_open()) {
            string buffer;
            getline(fin, buffer);
            cout << "Continut din fisier: " << buffer << endl;
            fin.close();
        }
        else {
            cout << "Eroare la deschiderea fisierului " << numeFisier << endl;
        }
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

    // Metoda pentru scriere in fisier binar
    void scrieInFisierBinar(const string& numeFisier) const {
        ofstream fout(numeFisier, ios::binary | ios::app);
        if (fout.is_open()) {
            int lungime = tipMaterial.length();
            fout.write((char*)&lungime, sizeof(lungime));
            fout.write(tipMaterial.c_str(), lungime);

            fout.write((char*)&diametru, sizeof(diametru));

            lungime = strlen(prescriptie);
            fout.write((char*)&lungime, sizeof(lungime));
            fout.write(prescriptie, lungime);

            fout.write((char*)&codSerie, sizeof(codSerie));

            fout.close();
        }
        else {
            cout << "Eroare la deschiderea fisierului " << numeFisier << endl;
        }
    }

    // Metoda pentru citire din fisier binar
    void citesteDinFisierBinar(const string& numeFisier) {
        ifstream fin(numeFisier, ios::binary);
        if (fin.is_open()) {
            int lungime;
            fin.read((char*)&lungime, sizeof(lungime));
            char* buffer = new char[lungime + 1];
            fin.read(buffer, lungime);
            buffer[lungime] = '\0';
            tipMaterial = buffer;
            delete[] buffer;

            fin.read((char*)&diametru, sizeof(diametru));

            fin.read((char*)&lungime, sizeof(lungime));
            buffer = new char[lungime + 1];
            fin.read(buffer, lungime);
            buffer[lungime] = '\0';
            delete[] prescriptie;
            prescriptie = buffer;

            int cod;
            fin.read((char*)&cod, sizeof(cod));
            cout << "Lentile [Tip Material: " << tipMaterial
                << ", Diametru: " << diametru
                << ", Prescriptie: " << prescriptie
                << ", Cod Serie: " << cod << "]\n";

            fin.close();
        }
        else {
            cout << "Eroare la deschiderea fisierului " << numeFisier << endl;
        }
    }
};
int Lentile::numarLentile = 0;

// ------------------------------------
// Functia main
// ------------------------------------
int main() {
    afisareCerinta();

    // Testare metode pentru fisiere text - Ochelari
    Ochelari o1("Progresive", 101, "Metal");
    o1.scrieInFisierText("ochelari.txt");
    o1.citesteDinFisierText("ochelari.txt");

    // Testare metode pentru fisiere binare - Lentile
    Lentile l1("Hidrogel", 12.5, "Miopie", 202);
    l1.scrieInFisierBinar("lentile.bin");
    l1.citesteDinFisierBinar("lentile.bin");

    return 0;
}
