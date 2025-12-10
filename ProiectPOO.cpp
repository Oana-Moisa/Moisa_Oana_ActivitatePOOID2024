#include <iostream>
#include <string>
using namespace std;

class Materie {
public:
    const int idMaterie;
    static int contorMaterii;

    string nume;
    int nrCredite;
    int nrNote;
    float* note;

    Materie() : idMaterie(++contorMaterii) {
        nume = "Necunoscuta";
        nrCredite = 0;
        nrNote = 0;
        note = NULL;
    }

    Materie(string _nume, int _nrCredite) : idMaterie(++contorMaterii) {
        nume = _nume;
        if (_nrCredite > 0) {
            nrCredite = _nrCredite;
        }
        else {
            nrCredite = 0;
        }
        nrNote = 0;
        note = NULL;
    }

    Materie(string _nume, int _nrCredite, int _nrNote, float* _note)
        : idMaterie(++contorMaterii) {
        nume = _nume;

        if (_nrCredite > 0) {
            nrCredite = _nrCredite;
        }
        else {
            nrCredite = 0;
        }

        if (_nrNote > 0 && _note != NULL) {
            nrNote = _nrNote;
            note = new float[nrNote];
            for (int i = 0; i < nrNote; i++) {
                note[i] = _note[i];
            }
        }
        else {
            nrNote = 0;
            note = NULL;
        }
    }

    static float calculeazaMedie(int nr, float* v) {
        if (nr <= 0 || v == NULL) {
            return 0;
        }
        float suma = 0;
        for (int i = 0; i < nr; i++) {
            suma += v[i];
        }
        return suma / nr;
    }

    void afisare() {
        cout << "Materie ID: " << idMaterie << endl;
        cout << "Nume: " << nume << endl;
        cout << "Nr credite: " << nrCredite << endl;
        cout << "Nr note: " << nrNote << endl;
        if (note != NULL && nrNote > 0) {
            cout << "Note: ";
            for (int i = 0; i < nrNote; i++) {
                cout << note[i] << " ";
            }
            cout << endl;
        }
        cout << " " << endl;
    }
};

int Materie::contorMaterii = 0;

class Nota {
public:
    const int idNota;
    static int contorNote;

    float valoare;
    string data;
    int nrRestante;
    float* noteRestante;

    Nota() : idNota(++contorNote) {
        valoare = 0;
        data = "N/A";
        nrRestante = 0;
        noteRestante = NULL;
    }

    Nota(float _valoare, string _data) : idNota(++contorNote) {
        valoare = _valoare;
        data = _data;
        nrRestante = 0;
        noteRestante = NULL;
    }

    Nota(float _valoare, string _data, int _nrRestante, float* _noteRestante)
        : idNota(++contorNote) {
        valoare = _valoare;
        data = _data;

        if (_nrRestante > 0 && _noteRestante != NULL) {
            nrRestante = _nrRestante;
            noteRestante = new float[nrRestante];
            for (int i = 0; i < nrRestante; i++) {
                noteRestante[i] = _noteRestante[i];
            }
        }
        else {
            nrRestante = 0;
            noteRestante = NULL;
        }
    }

    static float inProcent(float nota) {
        if (nota < 0) {
            return 0;
        }
        if (nota > 10) {
            nota = 10;
        }
        return nota * 10;
    }

    void afisare() {
        cout << "Nota ID: " << idNota << endl;
        cout << "Valoare: " << valoare << endl;
        cout << "Data: " << data << endl;
        cout << "Nr restante: " << nrRestante << endl;
        if (noteRestante != NULL && nrRestante > 0) {
            cout << "Note restante: ";
            for (int i = 0; i < nrRestante; i++) {
                cout << noteRestante[i] << " ";
            }
            cout << endl;
        }
        cout << " " << endl;
    }
};

int Nota::contorNote = 0;

class Orar {
public:
    const int idOrar;
    static int contorOrar;

    string numeStudent;
    int nrZile;
    int* orePeZi;
    int nrMaterii;
    string* denumiriMaterii;

    Orar() : idOrar(++contorOrar) {
        numeStudent = "Anonim";
        nrZile = 0;
        orePeZi = NULL;
        nrMaterii = 0;
        denumiriMaterii = NULL;
    }

    Orar(string _numeStudent, int _nrZile) : idOrar(++contorOrar) {
        numeStudent = _numeStudent;

        if (_nrZile > 0) {
            nrZile = _nrZile;
            orePeZi = new int[nrZile];
            for (int i = 0; i < nrZile; i++) {
                orePeZi[i] = 0;
            }
        }
        else {
            nrZile = 0;
            orePeZi = NULL;
        }

        nrMaterii = 0;
        denumiriMaterii = NULL;
    }

    Orar(string _numeStudent, int _nrZile, int* _orePeZi, int _nrMaterii)
        : idOrar(++contorOrar) {
        numeStudent = _numeStudent;

        if (_nrZile > 0 && _orePeZi != NULL) {
            nrZile = _nrZile;
            orePeZi = new int[nrZile];
            for (int i = 0; i < nrZile; i++) {
                orePeZi[i] = _orePeZi[i];
            }
        }
        else {
            nrZile = 0;
            orePeZi = NULL;
        }

        if (_nrMaterii > 0) {
            nrMaterii = _nrMaterii;
            denumiriMaterii = new string[nrMaterii];
            for (int i = 0; i < nrMaterii; i++) {
                denumiriMaterii[i] = "Materie" + to_string(i + 1);
            }
        }
        else {
            nrMaterii = 0;
            denumiriMaterii = NULL;
        }
    }

    static int calculeazaTotalOre(int nrZile, int* v) {
        if (nrZile <= 0 || v == NULL) {
            return 0;
        }
        int total = 0;
        for (int i = 0; i < nrZile; i++) {
            total += v[i];
        }
        return total;
    }

    void afisare() {
        cout << "Orar ID: " << idOrar << endl;
        cout << "Student: " << numeStudent << endl;
        cout << "Nr zile: " << nrZile << endl;
        if (orePeZi != NULL && nrZile > 0) {
            cout << "Ore pe zi: ";
            for (int i = 0; i < nrZile; i++) {
                cout << orePeZi[i] << " ";
            }
            cout << endl;
        }
        cout << "Nr materii: " << nrMaterii << endl;
        if (denumiriMaterii != NULL && nrMaterii > 0) {
            cout << "Materii: ";
            for (int i = 0; i < nrMaterii; i++) {
                cout << denumiriMaterii[i] << " ";
            }
            cout << endl;
        }
        cout << " " << endl;
    }
};

int Orar::contorOrar = 0;

int main() {
    float notePOO[3] = { 8.5f, 9.0f, 10.0f };

    Materie m1;
    Materie m2("Programare", 5);
    Materie m3("POO", 6, 3, notePOO);

    cout << "=== MATERII ===" << endl;
    m1.afisare();
    m2.afisare();
    m3.afisare();
    cout << "Media la POO: " << Materie::calculeazaMedie(3, notePOO) << endl;
    cout << " " << endl;

    float restante[2] = { 4.0f, 6.5f };

    Nota n1;
    Nota n2(9.5f, "2025-01-10");
    Nota n3(6.0f, "2025-01-12", 2, restante);

    cout << "=== NOTE ===" << endl;
    n1.afisare();
    n2.afisare();
    n3.afisare();
    cout << "Nota 9.5 in procent: " << Nota::inProcent(9.5f) << endl;
    cout << " " << endl;

    int ore[5] = { 4, 6, 5, 3, 4 };

    Orar o1;
    Orar o2("Ion Popescu", 5);
    Orar o3("Ion Nicolae Popescu", 5, ore, 3);

    cout << "=== ORARE ===" << endl;
    o1.afisare();
    o2.afisare();
    o3.afisare();
    cout << "Total ore pe saptamana pentru o3: " << Orar::calculeazaTotalOre(5, ore) << endl;
    cout << " " << endl;

    return 0;
}
