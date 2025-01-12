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

string Ochelari::getTipLentile() const {
    return tipLentile;
}

void Ochelari::setTipLentile(string tipLentile) {
    this->tipLentile = tipLentile;
}

const char* Ochelari::getMaterialRama() const {
    return materialRama;
}

void Ochelari::setMaterialRama(const char* materialRama) {
    delete[] this->materialRama;
    this->materialRama = new char[strlen(materialRama) + 1];
    strcpy_s(this->materialRama, strlen(materialRama) + 1, materialRama);
}

int Ochelari::getCodUnic() const {
    return codUnic;
}

int Ochelari::getNumarOchelari() {
    return numarOchelari;
}

void Ochelari::AfiseazaNumarOchelari() {
    cout << "Total ochelari: " << numarOchelari << endl;
}

ostream& operator<<(ostream& out, const Ochelari& o) {
    out << "Tip Lentile: " << o.tipLentile
        << " Material Rama: " << o.materialRama
        << " Cod Unic: " << o.codUnic;
    return out;
}

void procesareOchelari(Ochelari& o) {
    o.setTipLentile("Procesate");
    o.setMaterialRama("Metal");
}

Lentile::Lentile() : codSerie(0) {
    tipMaterial = "Silicon";
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

string Lentile::getTipMaterial() const {
    return tipMaterial;
}

void Lentile::setTipMaterial(string tipMaterial) {
    this->tipMaterial = tipMaterial;
}

float Lentile::getDiametru() const {
    return diametru;
}

void Lentile::setDiametru(float diametru) {
    this->diametru = diametru;
}

const char* Lentile::getPrescriptie() const {
    return prescriptie;
}

void Lentile::setPrescriptie(const char* prescriptie) {
    delete[] this->prescriptie;
    this->prescriptie = new char[strlen(prescriptie) + 1];
    strcpy_s(this->prescriptie, strlen(prescriptie) + 1, prescriptie);
}

int Lentile::getCodSerie() const {
    return codSerie;
}

int Lentile::getNumarLentile() {
    return numarLentile;
}

void Lentile::AfiseazaNumarLentile() {
    cout << "Total lentile: " << numarLentile << endl;
}

ostream& operator<<(ostream& out, const Lentile& l) {
    out << "Material Lentile: " << l.tipMaterial
        << " Diametru: " << l.diametru
        << " Prescriptie: " << l.prescriptie
        << " Cod lentile: " << l.codSerie;
    return out;
}

void procesareLentile(Lentile& l) {
    l.setTipMaterial("Procesat");
    l.setDiametru(15.0f);
}

Aparat::Aparat() : numarSerie(0) {
    model = "Standard";
    tehnologie = new char[strlen("Laser") + 1];
    strcpy_s(tehnologie, strlen("Laser") + 1, "Laser");
    numarAparate++;
}

Aparat::Aparat(string model, const char* tehnologie, int numarSerie) : numarSerie(numarSerie) {
    this->model = model;
    this->tehnologie = new char[strlen(tehnologie) + 1];
    strcpy_s(this->tehnologie, strlen(tehnologie) + 1, tehnologie);
    numarAparate++;
}

Aparat::Aparat(const Aparat& other) : numarSerie(other.numarSerie) {
    model = other.model;
    tehnologie = new char[strlen(other.tehnologie) + 1];
    strcpy_s(tehnologie, strlen(other.tehnologie) + 1, other.tehnologie);
}

Aparat::~Aparat() {
    delete[] tehnologie;
    numarAparate--;
}

string Aparat::getModel() const {
    return model;
}

void Aparat::setModel(string model) {
    this->model = model;
}

const char* Aparat::getTehnologie() const {
    return tehnologie;
}

void Aparat::setTehnologie(const char* tehnologie) {
    delete[] this->tehnologie;
    this->tehnologie = new char[strlen(tehnologie) + 1];
    strcpy_s(this->tehnologie, strlen(tehnologie) + 1, tehnologie);
}

int Aparat::getNumarSerie() const {
    return numarSerie;
}

int Aparat::getNumarAparate() {
    return numarAparate;
}

void Aparat::AfiseazaNumarAparate() {
    cout << "Total aparate: " << numarAparate << endl;
}

ostream& operator<<(ostream& out, const Aparat& a) {
    out << "Aparat: " << a.model
        << " Tehnologie: " << a.tehnologie
        << " Serie aparat: " << a.numarSerie;
    return out;
}

void procesareAparat(Aparat& a) {
    a.setModel("Procesat");
    a.setTehnologie("Ultrasunete");
}
