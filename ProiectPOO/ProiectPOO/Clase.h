#ifndef CLASE_H
#define CLASE_H

#include <iostream>
#include <cstring>
using namespace std;

class Ochelari {
private:
    string tipLentile;
    char* materialRama;
    const int codUnic;
    static int numarOchelari;

public:
    Ochelari();
    Ochelari(string tipLentile, const int codUnic, const char* materialRama);
    Ochelari(const Ochelari& other);
    ~Ochelari();

    string getTipLentile() const;
    void setTipLentile(string tipLentile);

    const char* getMaterialRama() const;
    void setMaterialRama(const char* materialRama);

    int getCodUnic() const;
    static int getNumarOchelari();

    Ochelari& operator=(const Ochelari& other);
    Ochelari operator+(const Ochelari& other);
    bool operator==(const Ochelari& other);
    Ochelari& operator++();

    static void AfiseazaNumarOchelari();

    friend ostream& operator<<(ostream& out, const Ochelari& o);
    friend void procesareOchelari(Ochelari& o);
    friend void schimbaMaterial(Ochelari& o, const char* materialNou);
};

class Lentile {
private:
    string tipMaterial;
    float diametru;
    char* prescriptie;
    const int codSerie;
    static int numarLentile;

public:
    Lentile();
    Lentile(string tipMaterial, float diametru, const char* prescriptie, int codSerie);
    Lentile(const Lentile& other);
    ~Lentile();

    string getTipMaterial() const;
    void setTipMaterial(string tipMaterial);

    float getDiametru() const;
    void setDiametru(float diametru);

    const char* getPrescriptie() const;
    void setPrescriptie(const char* prescriptie);

    int getCodSerie() const;
    static int getNumarLentile();

    Lentile& operator=(const Lentile& other);
    Lentile operator-(float reducereDiametru);
    bool operator!=(const Lentile& other);
    Lentile& operator--();

    static void AfiseazaNumarLentile();

    friend ostream& operator<<(ostream& out, const Lentile& l);
    friend void procesareLentile(Lentile& l);
    friend float calculPret(const Lentile& l);
};

class Aparat {
private:
    string model;
    char* tehnologie;
    const int numarSerie;
    string filtru;
    float rezolutieOptica;
    static int numarAparate;

public:
    Aparat();
    Aparat(string model, const char* tehnologie, int numarSerie, string filtru, float rezolutieOptica);
    Aparat(const Aparat& other);
    ~Aparat();

    string getModel() const;
    void setModel(string model);

    const char* getTehnologie() const;
    void setTehnologie(const char* tehnologie);

    string getFiltru() const;
    void setFiltru(string filtru);

    float getRezolutieOptica() const;
    void setRezolutieOptica(float rezolutieOptica);

    int getNumarSerie() const;
    static int getNumarAparate();

    Aparat& operator=(const Aparat& other);
    Aparat operator+(const Aparat& other);
    bool operator==(const Aparat& other);
    Aparat& operator++();
    Aparat operator!();

    static void AfiseazaNumarAparate();

    friend ostream& operator<<(ostream& out, const Aparat& a);
    friend void procesareAparat(Aparat& a);
    friend void actualizeazaRezolutie(Aparat& a, float nouaRezolutie);
    friend void schimbaFiltru(Aparat& a, const string& nouFiltru);
};

#endif
