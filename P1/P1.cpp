#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// Functie pentru afisarea cerintei
void afisareCerinta() {
    cout << "Proiect - Faza 1\n"
        << "-----------------\n"
        << "1. Alegeti trei obiecte din realitate.\n"
        << "   Nume student: Moisa Oana Nicoleta. Domeniul ales: 'Optica Medicala':\n"
        << "   - Ochelari de vedere\n"
        << "   - Lentile de contact\n"
        << "   - Aparat de masurare a dioptriilor\n"
        << "2. Realizati cate o clasa pentru fiecare obiect cu:\n"
        << "   - Atribute normale, statice si constante.\n"
        << "   - Cel putin un pointer alocat in HEAP.\n"
        << "   - 3 constructori diferiti (implicit, parametrizat, copiere).\n"
        << "3. Implementati cel putin o functie statica in fiecare clasa.\n"
        << "4. In functia main, creati cate 3 obiecte pentru fiecare clasa,\n"
        << "   utilizand toti constructorii.\n"
        << "5. Afisati obiectele create si numarul total de obiecte utilizand\n"
        << "   functiile statice.\n"
        << "-----------------\n\n";
}

// ------------------------------------
// Clasa 1: Ochelari de vedere
// ------------------------------------
class Ochelari {
public:
    string tipLentile;        // Atribut normal
    char* materialRama;       // Pointer alocat dinamic
    const int codUnic;        // Atribut constant
    static int numarOchelari; // Atribut static

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
    }

    // Destructor
    ~Ochelari() {
        delete[] materialRama;
        numarOchelari--;
    }

    // Functie statica pentru procesare
    static void afisareNumarOchelari() {
        cout << "Numar total de ochelari creati: " << numarOchelari << endl;
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
// Clasa 2: Lentile de contact
// ------------------------------------
class Lentile {
public:
    string tipMaterial;        // Atribut normal
    float diametru;            // Atribut normal
    char* prescriptie;         // Pointer alocat dinamic
    const int codSerie;        // Atribut constant
    static int numarLentile;   // Atribut static

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

    // Constructor de copiere
    Lentile(const Lentile& other) : codSerie(other.codSerie) {
        tipMaterial = other.tipMaterial;
        diametru = other.diametru;
        prescriptie = new char[strlen(other.prescriptie) + 1];
        strcpy(prescriptie, other.prescriptie);
    }

    // Destructor
    ~Lentile() {
        delete[] prescriptie;
        numarLentile--;
    }

    // Functie statica pentru procesare
    static void afisareNumarLentile() {
        cout << "Numar total de lentile create: " << numarLentile << endl;
    }

    // Supraincarcare operator <<
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
// Clasa 3: Aparat de masurare a dioptriilor
// ------------------------------------
class Aparat {
public:
    string model;             // Atribut normal
    char* tehnologie;         // Pointer alocat dinamic
    const int numarSerie;     // Atribut constant
    static int numarAparate;  // Atribut static

    // Constructor fara parametri
    Aparat() : numarSerie(0) {
        model = "Standard";
        tehnologie = new char[strlen("Laser") + 1];
        strcpy(tehnologie, "Laser");
        numarAparate++;
    }

    // Constructor cu parametri
    Aparat(string model, const char* tehnologie, int numarSerie) : numarSerie(numarSerie) {
        this->model = model;
        this->tehnologie = new char[strlen(tehnologie) + 1];
        strcpy(this->tehnologie, tehnologie);
        numarAparate++;
    }

    // Constructor de copiere
    Aparat(const Aparat& other) : numarSerie(other.numarSerie) {
        model = other.model;
        tehnologie = new char[strlen(other.tehnologie) + 1];
        strcpy(tehnologie, other.tehnologie);
    }

    // Destructor
    ~Aparat() {
        delete[] tehnologie;
        numarAparate--;
    }

    // Functie statica pentru procesare
    static void afisareNumarAparate() {
        cout << "Numar total de aparate create: " << numarAparate << endl;
    }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const Aparat& a) {
        out << "Aparat [Model: " << a.model
            << ", Tehnologie: " << a.tehnologie
            << ", Numar Serie: " << a.numarSerie << "]";
        return out;
    }
};
int Aparat::numarAparate = 0;

// ------------------------------------
// Functia main
// ------------------------------------
int main() {
    afisareCerinta();

    // Testare Ochelari
    Ochelari o1;
    Ochelari o2("Progresive", 101, "Metal");
    Ochelari o3 = o2;
    cout << o1 << endl << o2 << endl << o3 << endl;
    Ochelari::afisareNumarOchelari();

    // Testare Lentile
    Lentile l1;
    Lentile l2("Hidrogel", 12.5, "Miopie", 202);
    Lentile l3 = l2;
    cout << l1 << endl << l2 << endl << l3 << endl;
    Lentile::afisareNumarLentile();

    // Testare Aparat
    Aparat a1;
    Aparat a2("Avansat", "Ultrasunete", 303);
    Aparat a3 = a2;
    cout << a1 << endl << a2 << endl << a3 << endl;
    Aparat::afisareNumarAparate();

    system("pause");
    return 0;
}