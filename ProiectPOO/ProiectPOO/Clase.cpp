#include "Clase.h"

int Ochelari::numarOchelari = 0;
int Lentile::numarLentile = 0;
int Aparat::numarAparate = 0;

Ochelari::Ochelari() : codUnic(0) {
    tipLentile = "Monofocale";
    materialRama = new char[strlen("Plastic") + 1];
    strcpy_s(materialRama, strlen("Plastic") + 1, "Plastic");
    numarOchelari++;
}

Ochelari::Ochelari(string tipLentile, const int codUnic, const char* materialRama) : codUnic(codUnic) {
    this->tipLentile = tipLentile;
    this->materialRama = new char[strlen(materialRama) + 1];
    strcpy_s(this->materialRama, strlen(materialRama) + 1, materialRama);
    numarOchelari++;
}

Ochelari::Ochelari(const Ochelari& other) : codUnic(other.codUnic) {
    tipLentile = other.tipLentile;
    materialRama = new char[strlen(other.materialRama) + 1];
    strcpy_s(materialRama, strlen(other.materialRama) + 1, other.materialRama);
}

Ochelari::~Ochelari() {
    delete[] materialRama;
    numarOchelari--;
}

Ochelari& Ochelari::operator=(const Ochelari& other) {
    if (this != &other) {
        delete[] materialRama;
        tipLentile = other.tipLentile;
        materialRama = new char[strlen(other.materialRama) + 1];
        strcpy_s(materialRama, strlen(other.materialRama) + 1, other.materialRama);
    }
    return *this;
}

Ochelari Ochelari::operator+(const Ochelari& other) {
    Ochelari temp(*this);
    temp.tipLentile += " & " + other.tipLentile;
    return temp;
}

bool Ochelari::operator==(const Ochelari& other) {
    return tipLentile == other.tipLentile && strcmp(materialRama, other.materialRama) == 0;
}

Ochelari& Ochelari::operator++() {
    tipLentile += " Premium";
    return *this;
}

void Ochelari::AfiseazaNumarOchelari() {
    cout << "Numar total de ochelari: " << numarOchelari << endl;
}

ostream& operator<<(ostream& out, const Ochelari& o) {
    out << "Tip Lentile: " << o.tipLentile
        << ", Material Rama: " << o.materialRama
        << ", Cod Unic: " << o.codUnic;
    return out;
}

void schimbaMaterial(Ochelari& o, const char* materialNou) {
    delete[] o.materialRama;
    o.materialRama = new char[strlen(materialNou) + 1];
    strcpy_s(o.materialRama, strlen(materialNou) + 1, materialNou);
}

Lentile::Lentile() : codSerie(0) {
    tipMaterial = "Policarbonat";
    diametru = 14.0f;
    prescriptie = new char[strlen("General") + 1];
    strcpy_s(prescriptie, strlen("General") + 1, "General");
    numarLentile++;
}

Lentile::Lentile(string tipMaterial, float diametru, const char* prescriptie, int codSerie) : codSerie(codSerie) {
    this->tipMaterial = tipMaterial;
    this->diametru = diametru;
    this->prescriptie = new char[strlen(prescriptie) + 1];
    strcpy_s(this->prescriptie, strlen(prescriptie) + 1, prescriptie);
    numarLentile++;
}

Lentile::Lentile(const Lentile& other) : codSerie(other.codSerie) {
    tipMaterial = other.tipMaterial;
    diametru = other.diametru;
    prescriptie = new char[strlen(other.prescriptie) + 1];
    strcpy_s(prescriptie, strlen(other.prescriptie) + 1, other.prescriptie);
}

Lentile::~Lentile() {
    delete[] prescriptie;
    numarLentile--;
}

Lentile& Lentile::operator=(const Lentile& other) {
    if (this != &other) {
        delete[] prescriptie;
        tipMaterial = other.tipMaterial;
        diametru = other.diametru;
        prescriptie = new char[strlen(other.prescriptie) + 1];
        strcpy_s(prescriptie, strlen(other.prescriptie) + 1, other.prescriptie);
    }
    return *this;
}

Lentile Lentile::operator-(float reducereDiametru) {
    Lentile temp(*this);
    temp.diametru -= reducereDiametru;
    return temp;
}

bool Lentile::operator!=(const Lentile& other) {
    return tipMaterial != other.tipMaterial || diametru != other.diametru;
}

Lentile& Lentile::operator--() {
    diametru -= 1.0f;
    return *this;
}

void Lentile::AfiseazaNumarLentile() {
    cout << "Numar total de lentile: " << numarLentile << endl;
}

ostream& operator<<(ostream& out, const Lentile& l) {
    out << "Material: " << l.tipMaterial
        << ", Diametru: " << l.diametru
        << ", Prescriptie: " << l.prescriptie
        << ", Cod Serie: " << l.codSerie;
    return out;
}

float calculPret(const Lentile& l) {
    return l.diametru * 10.0f;
}

// Implementare clasa Aparat
Aparat::Aparat() : numarSerie(0) {
    model = "Standard";
    tehnologie = new char[strlen("Laser") + 1];
    strcpy_s(tehnologie, strlen("Laser") + 1, "Laser");
    filtru = "N/A";
    rezolutieOptica = 0.0f;
    numarAparate++;
}

Aparat::Aparat(string model, const char* tehnologie, int numarSerie, string filtru, float rezolutieOptica) : numarSerie(numarSerie) {
    this->model = model;
    this->tehnologie = new char[strlen(tehnologie) + 1];
    strcpy_s(this->tehnologie, strlen(tehnologie) + 1, tehnologie);
    this->filtru = filtru;
    this->rezolutieOptica = rezolutieOptica;
    numarAparate++;
}

Aparat::Aparat(const Aparat& other) : numarSerie(other.numarSerie) {
    model = other.model;
    tehnologie = new char[strlen(other.tehnologie) + 1];
    strcpy_s(tehnologie, strlen(other.tehnologie) + 1, other.tehnologie);
    filtru = other.filtru;
    rezolutieOptica = other.rezolutieOptica;
}

Aparat::~Aparat() {
    delete[] tehnologie;
    numarAparate--;
}

Aparat& Aparat::operator=(const Aparat& other) {
    if (this != &other) {
        delete[] tehnologie;
        model = other.model;
        tehnologie = new char[strlen(other.tehnologie) + 1];
        strcpy_s(tehnologie, strlen(other.tehnologie) + 1, other.tehnologie);
        filtru = other.filtru;
        rezolutieOptica = other.rezolutieOptica;
    }
    return *this;
}

Aparat Aparat::operator+(const Aparat& other) {
    Aparat temp(*this);
    temp.model += " & " + other.model;
    return temp;
}

bool Aparat::operator==(const Aparat& other) {
    return model == other.model && filtru == other.filtru;
}

Aparat& Aparat::operator++() {
    rezolutieOptica += 1.0f;
    return *this;
}

Aparat Aparat::operator!() {
    Aparat temp(*this);
    temp.filtru = "Invers_" + temp.filtru;
    return temp;
}

void Aparat::AfiseazaNumarAparate() {
    cout << "Numar total de aparate: " << numarAparate << endl;
}

ostream& operator<<(ostream& out, const Aparat& a) {
    out << "Model: " << a.model
        << ", Tehnologie: " << a.tehnologie
        << ", Filtru: " << a.filtru
        << ", Rezolutie Optica: " << a.rezolutieOptica
        << ", Serie: " << a.numarSerie;
    return out;
}

void actualizeazaRezolutie(Aparat& a, float nouaRezolutie) {
    a.rezolutieOptica = nouaRezolutie;
}

void schimbaFiltru(Aparat& a, const string& nouFiltru) {
    a.filtru = nouFiltru;
}

/*void procesareOchelari(Ochelari& o) {
    o.setTipLentile("Progresive");
    o.setMaterialRama("Titan");
}

void procesareLentile(Lentile& l) {
    l.setTipMaterial("Antireflex");
    l.setDiametru(l.getDiametru() + 0.5f);
}

void procesareAparat(Aparat& a) {
    a.setModel("Avansat");
    a.setTehnologie("Ultrasunete");
}*/
