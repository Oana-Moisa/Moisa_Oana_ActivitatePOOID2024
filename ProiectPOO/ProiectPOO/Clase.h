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

    static void AfiseazaNumarOchelari();

    friend ostream& operator<<(ostream& out, const Ochelari& o);
    friend void procesareOchelari(Ochelari& o);
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

    static void AfiseazaNumarLentile();

    friend ostream& operator<<(ostream& out, const Lentile& l);
    friend void procesareLentile(Lentile& l);
};

class Aparat {
private:
    string model;
    char* tehnologie;
    const int numarSerie;
    static int numarAparate;

public:
    Aparat();
    Aparat(string model, const char* tehnologie, int numarSerie);
    Aparat(const Aparat& other);
    ~Aparat();

    string getModel() const;
    void setModel(string model);

    const char* getTehnologie() const;
    void setTehnologie(const char* tehnologie);

    int getNumarSerie() const;

    static int getNumarAparate();

    static void AfiseazaNumarAparate();

    friend ostream& operator<<(ostream& out, const Aparat& a);
    friend void procesareAparat(Aparat& a);
};

#endif
