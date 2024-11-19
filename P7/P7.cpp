#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// Functie pentru afisarea cerintelor
void afisareCerinta() {
    cout << "Proiect - Faza 7\n"
        << "-----------------\n"
        << "1. Creati doua clase noi care sa mosteneasca doua dintre clasele existente.\n"
        << "2. Adaugati atribute si metode specifice pentru noile clase.\n"
        << "3. Creati obiecte ale noilor clase si testati functionalitatea acestora in functia main.\n"
        << "4. Realizati upcasting si folositi-l in functia main.\n"
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
    virtual ~Ochelari() {
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
// Clasa derivata: OchelariProtectie
// ------------------------------------
class OchelariProtectie : public Ochelari {
private:
    string tipProtectie; // Exemplu: anti-laser, praf
    bool rezistentiLaImpact;

public:
    // Constructor fara parametri
    OchelariProtectie() : Ochelari(), tipProtectie("Standard"), rezistentiLaImpact(false) {}

    // Constructor cu parametri
    OchelariProtectie(string tipLentile, const int codUnic, const char* materialRama, string tipProtectie, bool rezistentiLaImpact)
        : Ochelari(tipLentile, codUnic, materialRama), tipProtectie(tipProtectie), rezistentiLaImpact(rezistentiLaImpact) {}

    // Destructor
    ~OchelariProtectie() {}

    // Geteri si seteri
    string getTipProtectie() const { return tipProtectie; }
    void setTipProtectie(const string& tip) { tipProtectie = tip; }

    bool getRezistentiLaImpact() const { return rezistentiLaImpact; }
    void setRezistentiLaImpact(bool rezistenta) { rezistentiLaImpact = rezistenta; }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const OchelariProtectie& o) {
        out << static_cast<const Ochelari&>(o)
            << ", Tip Protectie: " << o.tipProtectie
            << ", Rezistenti La Impact: " << (o.rezistentiLaImpact ? "Da" : "Nu");
        return out;
    }
};

// ------------------------------------
// Clasa derivata: LentileTerapeutice
// ------------------------------------
class LentileTerapeutice : public Lentile {
private:
    string tratament; // Exemplu: antiinflamator, hidratant

public:
    // Constructor fara parametri
    LentileTerapeutice() : Lentile(), tratament("Standard") {}

    // Constructor cu parametri
    LentileTerapeutice(string tipMaterial, float diametru, const char* prescriptie, int codSerie, string tratament)
        : Lentile(tipMaterial, diametru, prescriptie, codSerie), tratament(tratament) {}

    // Destructor
    ~LentileTerapeutice() {}

    // Geteri si seteri
    string getTratament() const { return tratament; }
    void setTratament(const string& trat) { tratament = trat; }

    // Supraincarcare operator <<
    friend ostream& operator<<(ostream& out, const LentileTerapeutice& l) {
        out << static_cast<const Lentile&>(l)
            << ", Tratament: " << l.tratament;
        return out;
    }
};

// ------------------------------------
// Functia main
// ------------------------------------
int main() {
    afisareCerinta();

    // Testare OchelariProtectie
    OchelariProtectie op1("Anti-reflex", 105, "Metal", "Anti-laser", true);
    cout << op1 << endl;

    // Testare LentileTerapeutice
    LentileTerapeutice lt1("Hidrogel", 14.2, "Miopie", 203, "Hidratant");
    cout << lt1 << endl;

    // Upcasting
    Ochelari* op2 = new OchelariProtectie("Progresive", 106, "Carbon", "Praf", false);
    cout << *op2 << endl;
    delete op2;

    Lentile* lt2 = new LentileTerapeutice("Silicon", 13.8, "Astigmatism", 204, "Antiinflamator");
    cout << *lt2 << endl;
    delete lt2;

    return 0;
}