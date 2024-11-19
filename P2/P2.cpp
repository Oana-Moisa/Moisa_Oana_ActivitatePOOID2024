#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// Functie pentru afisarea cerintelor
void afisareCerinta() {
    cout << "Proiect - Faza 2\n"
        << "-----------------\n"
        << "1. Pentru clasele din tema precedenta, mutati atributele in zona privata.\n"
        << "2. Implementati destructorii pentru a sterge memoria alocata in HEAP.\n"
        << "3. Adaugati constructorul de copiere pentru toate clasele.\n"
        << "4. Creati get-eri si set-eri pentru toate atributele private.\n"
        << "5. Implementati functii statice pentru a accesa atributele statice.\n"
        << "6. Creati doua functii globale prietene care sa proceseze obiectele claselor.\n"
        << "7. In functia main, apelati toate metodele si functiile pentru testare.\n"
        << "-----------------\n\n";
}

// ------------------------------------
// Clasa 1: Ochelari de vedere
// ------------------------------------
class Ochelari {
private:
    string tipLentile;        // Atribut normal
    char* materialRama;       // Pointer alocat dinamic
    const int codUnic;        // Atribut constant
    static int numarOchelari; // Atribut static

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

    // Get-eri si set-eri
    string getTipLentile() const { return tipLentile; }
    void setTipLentile(const string& tip) { tipLentile = tip; }

    const char* getMaterialRama() const { return materialRama; }
    void setMaterialRama(const char* material) {
        delete[] materialRama;
        materialRama = new char[strlen(material) + 1];
        strcpy(materialRama, material);
    }

    int getCodUnic() const { return codUnic; }

    // Functii statice pentru acces la numarOchelari
    static int getNumarOchelari() { return numarOchelari; }
};

// Initializare atribut static
int Ochelari::numarOchelari = 0;

// ------------------------------------
// Clasa 2: Lentile de contact
// ------------------------------------
class Lentile {
private:
    string tipMaterial;        // Atribut normal
    float diametru;            // Atribut normal
    char* prescriptie;         // Pointer alocat dinamic
    const int codSerie;        // Atribut constant
    static int numarLentile;   // Atribut static

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

    // Constructor de copiere
    Lentile(const Lentile& other) : codSerie(other.codSerie) {
        tipMaterial = other.tipMaterial;
        diametru = other.diametru;
        prescriptie = new char[strlen(other.prescriptie) + 1];
        strcpy(prescriptie, other.prescriptie);
        numarLentile++;
    }

    // Destructor
    ~Lentile() {
        delete[] prescriptie;
        numarLentile--;
    }

    // Get-eri si set-eri
    string getTipMaterial() const { return tipMaterial; }
    void setTipMaterial(const string& material) { tipMaterial = material; }

    float getDiametru() const { return diametru; }
    void setDiametru(float diam) { diametru = diam; }

    const char* getPrescriptie() const { return prescriptie; }
    void setPrescriptie(const char* presc) {
        delete[] prescriptie;
        prescriptie = new char[strlen(presc) + 1];
        strcpy(prescriptie, presc);
    }

    int getCodSerie() const { return codSerie; }

    // Functii statice pentru acces la numarLentile
    static int getNumarLentile() { return numarLentile; }
};

// Initializare atribut static
int Lentile::numarLentile = 0;

// ------------------------------------
// Clasa 3: Aparat de masurare a dioptriilor
// ------------------------------------
class Aparat {
private:
    string model;             // Atribut normal
    char* tehnologie;         // Pointer alocat dinamic
    const int numarSerie;     // Atribut constant
    static int numarAparate;  // Atribut static

public:
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
        numarAparate++;
    }

    // Destructor
    ~Aparat() {
        delete[] tehnologie;
        numarAparate--;
    }

    // Get-eri si set-eri
    string getModel() const { return model; }
    void setModel(const string& mod) { model = mod; }

    const char* getTehnologie() const { return tehnologie; }
    void setTehnologie(const char* tech) {
        delete[] tehnologie;
        tehnologie = new char[strlen(tech) + 1];
        strcpy(tehnologie, tech);
    }

    int getNumarSerie() const { return numarSerie; }

    // Functii statice pentru acces la numarAparate
    static int getNumarAparate() { return numarAparate; }
};

// Initializare atribut static
int Aparat::numarAparate = 0;

// ------------------------------------
// Functii globale prietene
// ------------------------------------
void modificaOchelari(Ochelari& o, const string& tip, const char* material) {
    o.setTipLentile(tip);
    o.setMaterialRama(material);
}

void modificaLentile(Lentile& l, const string& tip, float diam, const char* presc) {
    l.setTipMaterial(tip);
    l.setDiametru(diam);
    l.setPrescriptie(presc);
}

// ------------------------------------
// Functia main
// ------------------------------------
int main() {
    afisareCerinta();

    // Testare clase si functii
    Ochelari o1;
    modificaOchelari(o1, "Progresive", "Metal");
    cout << "Tip Lentile: " << o1.getTipLentile() << ", Material Rama: " << o1.getMaterialRama() << endl;

    Lentile l1;
    modificaLentile(l1, "Hidrogel", 12.5, "Miopie");
    cout << "Tip Material: " << l1.getTipMaterial() << ", Diametru: " << l1.getDiametru() << ", Prescriptie: " << l1.getPrescriptie() << endl;

    cout << "Numar total ochelari: " << Ochelari::getNumarOchelari() << endl;
    cout << "Numar total lentile: " << Lentile::getNumarLentile() << endl;

    return 0;
}
