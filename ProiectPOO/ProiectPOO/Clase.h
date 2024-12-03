#ifndef CLASE_H
#define CLASE_H

#include <iostream>
#include <cstring>
using namespace std;

class Ochelari {
public:
    string tipLentile;
    char* materialRama;
    const int codUnic;
    static int numarOchelari;

    Ochelari();
    Ochelari(string tipLentile, const int codUnic, const char* materialRama);
    Ochelari(const Ochelari& other);
    ~Ochelari();
    static void AfiseazaNumarOchelari();
    friend ostream& operator<<(ostream& out, const Ochelari& o);
};

class Lentile {
public:
    string tipMaterial;
    float diametru;
    char* prescriptie;
    const int codSerie;
    static int numarLentile;

    Lentile();
    Lentile(string tipMaterial, float diametru, const char* prescriptie, int codSerie);
    Lentile(const Lentile& other);
    ~Lentile();
    static void AfiseazaNumarLentile();
    friend ostream& operator<<(ostream& out, const Lentile& l);
};

class Aparat {
public:
    string model;
    char* tehnologie;
    const int numarSerie;
    static int numarAparate;

    Aparat();
    Aparat(string model, const char* tehnologie, int numarSerie);
    Aparat(const Aparat& other);
    ~Aparat();
    static void AfiseazaNumarAparate();
    friend ostream& operator<<(ostream& out, const Aparat& a);
};

#endif
