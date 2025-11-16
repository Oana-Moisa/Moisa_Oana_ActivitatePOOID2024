#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Mobilier {
    int                greutate;
    float              pret;
    string             nume;
    int                nrVariantePret;
    float* variantePret;
    char* descriere;
    static int         nrMobilierCreate;
    const int          codIntern;
    vector<int>        coduriLivrare = { 10,20 };

public:
    Mobilier(int cod) : codIntern(cod) {}
};

class Student {
    int                varsta;
    float              medieGenerala;
    string             nume;
    int                nrNote;
    int* note;
    char* facultate;
    static int         nrStudenti;
    const int          codMatricol;
    vector<int>        noteInitiale = { 7,8,9 };

public:
    Student(int cod) : codMatricol(cod) {}
};

class Masina {
    int                anFabricatie;
    float              consumMediu;
    string             marca;
    int                nrTronsoane;
    float* consumPeTronson;
    char* serieSasiu;
    static int         nrMasini;
    const int          codInmatriculare;
    vector<int>        vitezeTest = { 40,60,80 };

public:
    Masina(int cod) : codInmatriculare(cod) {}
};

class Carte {
    int                nrPagini;
    float              rating;
    string             titlu;
    int                nrCapitole;
    string* capitole;
    char* ISBN;
    static int         nrCarti;
    const int          anAparitie;
    vector<int>        paginiPref = { 10,50,100 };

public:
    Carte(int an) : anAparitie(an) {}
};

class Farmacie {
    int                nrProduse;
    float              venitZilnic;
    string             nume;
    int                nrMedicamente;
    float* preturiMedicamente;
    char* adresa;
    static int         nrFarmacii;
    const int          codAutorizare;
    vector<int>        coduriMed = { 101,202 };

public:
    Farmacie(int cod) : codAutorizare(cod) {}
};

class Film {
    int                durataMinute;
    float              rating;
    string             titlu;
    int                nrActori;
    string* actori;
    char* descriere;
    static int         nrFilme;
    const int          codFilm;
    vector<int>        scoruri = { 8,9,10 };

public:
    Film(int cod) : codFilm(cod) {}
};

class CosCumparaturi {
    int                nrProduse;
    float              total;
    string             numeClient;
    int                dimPreturi;
    float* preturi;
    char* dataCreare;
    static int         nrCosuri;
    const float        TVA;
    vector<int>        coduri = { 1,2,3 };

public:
    CosCumparaturi(float tva) : TVA(tva) {}
};

class Restaurant {
    int                nrPreparate;
    float              rating;
    string             nume;
    int                nrIngrediente;
    string* ingrediente;
    char* adresa;
    static int         nrRestaurante;
    const int          codFiscal;
    vector<int>        timpiPreparare = { 5,10 };

public:
    Restaurant(int cod) : codFiscal(cod) {}
};

class Laptop {
    int                memorieRAM;
    float              pret;
    string             model;
    int                nrTemperaturi;
    float* temperaturi;
    char* serie;
    static int         nrLaptopuri;
    const int          garantieLuni;
    vector<int>        frecvente = { 2,3,4 };

public:
    Laptop(int garantie) : garantieLuni(garantie) {}
};

class FirmaCatering {
    int                nrAngajati;
    float              cifraAfaceri;
    string             nume;
    int                nrMeniuri;
    float* preturiMeniuri;
    char* locatie;
    static int         nrFirme;
    const int          codAutorizare;
    vector<int>        timpiLivrare = { 20,30 };

public:
    FirmaCatering(int cod) : codAutorizare(cod) {}
};

class CabinetStomatologic {
    int                nrPacienti;
    float              pretConsultatie;
    string             numeMedic;
    int                nrTratamente;
    string* tratamente;
    char* adresa;
    static int         nrCabinete;
    const int          codMedical;
    vector<int>        durateTratamente = { 15,30 };

public:
    CabinetStomatologic(int cod) : codMedical(cod) {}
};

class StatieAlimentareAuto {
    int                nrPompe;
    float              pretBenzina;
    string             nume;
    int                nrTipuriCarburant;
    float* preturiCarburant;
    char* locatie;
    static int         nrStatii;
    const int          idStatie;
    vector<int>        niveluriTanc = { 50,70 };

public:
    StatieAlimentareAuto(int id) : idStatie(id) {}
};

class ProfilInfluencer {
    int                nrUrmaritori;
    float              rating;
    string             nume;
    int                nrPostari;
    string* postari;
    char* descriere;
    static int         nrProfiluri;
    const int          codInfluencer;
    vector<int>        likeUri = { 100,200 };

public:
    ProfilInfluencer(int cod) : codInfluencer(cod) {}
};

class Cred {
    int                suma;
    float              dobanda;
    string             titular;
    int                durataLuni;
    float* rateLunare;
    char* codContract;
    static int         nrCredite;
    const int          codBanca;
    vector<int>        scadente = { 5,10,15 };

public:
    Cred(int cod) : codBanca(cod) {}
};

class BazeDate {
    int                nrTabele;
    float              versiune;
    string             nume;
    int                nrUtilizatori;
    string* utilizatori;
    char* adresaServer;
    static int         nrBD;
    const int          port;
    vector<int>        idTabele = { 1,2,3 };

public:
    BazeDate(int p) : port(p) {}
};

class Procese {
    int                pid;
    float              memorie;
    string             nume;
    int                nrThreaduri;
    int* threaduri;
    char* stare;
    static int         nrProcese;
    const int          prioritateDefault;
    vector<int>        coduriStatus = { 0,1,2 };

public:
    Procese(int prio) : prioritateDefault(prio) {}
};

class Tramvai {
    int                nrTraseu;
    float              tarif;
    string             linie;
    int                nrStatii;
    string* statii;
    char* serie;
    static int         nrTramvaie;
    const int          capacitateMax;
    vector<int>        opriri = { 1,2,3 };

public:
    Tramvai(int cap) : capacitateMax(cap) {}
};

class Fisier {
    int                dimensiune;
    float              versiune;
    string             nume;
    int                nrLinii;
    char** linii;
    char* extensie;
    static int         nrFisiere;
    const int          permisiuni;
    vector<int>        timpiAcces = { 1,5,10 };

public:
    Fisier(int perm) : permisiuni(perm) {}
};

class DBUser {
    int                id;
    float              nivelAcces;
    string             username;
    int                nrRoluri;
    string* roluri;
    char* parola;
    static int         nrUseri;
    const int          nivelMinim;
    vector<int>        privilegii = { 1,2,3 };

public:
    DBUser(int minLevel) : nivelMinim(minLevel) {}
};

class Autobuz {
    int                nrLocuri;
    float              pretBilet;
    string             linie;
    int                nrStatii;
    string* statii;
    char* serie;
    static int         nrAutobuze;
    const int          capacitateMax;
    vector<int>        timpi = { 10,20,30 };

public:
    Autobuz(int cap) : capacitateMax(cap) {}
};

class Pompieri {
    int                nrInterventii;
    float              salariu;
    string             numeEchipa;
    int                nrEchipamente;
    string* echipamente;
    char* locatie;
    static int         nrEchipe;
    const int          codUnitate;
    vector<int>        timpiReactiv = { 5,7,10 };

public:
    Pompieri(int cod) : codUnitate(cod) {}
};

class DosarAdmitere {
    int                nrDocumente;
    float              taxa;
    string             numeCandidat;
    int                nrNote;
    float* note;
    char* facultate;
    static int         nrDosare;
    const int          anAdmitere;
    vector<int>        examene = { 1,2,3 };

public:
    DosarAdmitere(int an) : anAdmitere(an) {}
};

class Casa {
    int                nrCamere;
    float              suprafata;
    string             adresa;
    int                nrVecini;
    string* vecini;
    char* codPostal;
    static int         nrCase;
    const int          anConstructie;
    vector<int>        niveluri = { 1,2 };

public:
    Casa(int an) : anConstructie(an) {}
};

class CartiVizita {
    int                nrContacte;
    float              pretTotal;
    string             numeFirma;
    int                nrTipuri;
    string* tipuri;
    char* design;
    static int         nrComenzi;
    const int          codComanda;
    vector<int>        cantitati = { 50,100,200 };

public:
    CartiVizita(int cod) : codComanda(cod) {}
};
