#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Materie {
private:
    const int idMaterie;
    static int contorMaterii;

    string nume;
    int nrCredite;
    int nrNote;
    float* note;

public:
    Materie() : idMaterie(++contorMaterii) {
        nume = "Necunoscuta";
        nrCredite = 0;
        nrNote = 0;
        note = NULL;
    }

    Materie(string nume, int nrCredite) : idMaterie(++contorMaterii) {
        this->nume = nume;
        this->nrCredite = (nrCredite > 0 ? nrCredite : 0);
        nrNote = 0;
        note = NULL;
    }

    Materie(string nume, int nrCredite, int nrNote, float* note) : idMaterie(++contorMaterii) {
        this->nume = nume;
        this->nrCredite = (nrCredite > 0 ? nrCredite : 0);

        if (nrNote > 0 && note != NULL) {
            this->nrNote = nrNote;
            this->note = new float[this->nrNote];
            for (int i = 0; i < this->nrNote; i++) {
                this->note[i] = note[i];
            }
        }
        else {
            this->nrNote = 0;
            this->note = NULL;
        }
    }

    Materie(const Materie& m) : idMaterie(m.idMaterie) {
        nume = m.nume;
        nrCredite = m.nrCredite;

        if (m.nrNote > 0 && m.note != NULL) {
            nrNote = m.nrNote;
            note = new float[nrNote];
            for (int i = 0; i < nrNote; i++) note[i] = m.note[i];
        }
        else {
            nrNote = 0;
            note = NULL;
        }
    }

    ~Materie() {
        if (note != NULL) delete[] note;
    }

    Materie& operator=(const Materie& m) {
        if (this != &m) {
            if (note != NULL) delete[] note;

            nume = m.nume;
            nrCredite = m.nrCredite;

            if (m.nrNote > 0 && m.note != NULL) {
                nrNote = m.nrNote;
                note = new float[nrNote];
                for (int i = 0; i < nrNote; i++) note[i] = m.note[i];
            }
            else {
                nrNote = 0;
                note = NULL;
            }
        }
        return *this;
    }

    string getNume() const { return nume; }
    int getNrCredite() const { return nrCredite; }
    int getNrNote() const { return nrNote; }
    float* getNote() const {
        if (nrNote <= 0 || note == NULL) return NULL;
        float* copie = new float[nrNote];
        for (int i = 0; i < nrNote; i++) copie[i] = note[i];
        return copie;
    }
    int getIdMaterie() const { return idMaterie; }

    void setNume(string nume) { this->nume = nume; }
    void setNrCredite(int nrCredite) { this->nrCredite = (nrCredite > 0 ? nrCredite : 0); }

    void setNote(int nrNote, float* note) {
        if (this->note != NULL) delete[] this->note;

        if (nrNote > 0 && note != NULL) {
            this->nrNote = nrNote;
            this->note = new float[this->nrNote];
            for (int i = 0; i < this->nrNote; i++) this->note[i] = note[i];
        }
        else {
            this->nrNote = 0;
            this->note = NULL;
        }
    }

    static int getContorMaterii() { return contorMaterii; }
    static void setContorMaterii(int c) { contorMaterii = c; }

    static float calculeazaMedie(int nr, float* v) {
        if (nr <= 0 || v == NULL) return 0;
        float s = 0;
        for (int i = 0; i < nr; i++) s += v[i];
        return s / nr;
    }

    float medieNote() const {
        if (nrNote <= 0 || note == NULL) return 0;
        float s = 0;
        for (int i = 0; i < nrNote; i++) s += note[i];
        return s / nrNote;
    }

    bool areRestante() const {
        if (nrNote <= 0 || note == NULL) return true;
        for (int i = 0; i < nrNote; i++) {
            if (note[i] < 5) return true;
        }
        return false;
    }

    Materie operator+(int crediteInPlus) const {
        Materie copie(*this);
        copie.nrCredite = copie.nrCredite + (crediteInPlus > 0 ? crediteInPlus : 0);
        return copie;
    }

    float operator[](int index) const {
        if (index >= 0 && index < nrNote && note != NULL) return note[index];
        return -1;
    }

    bool operator<(const Materie& m) const {
        return this->nrCredite < m.nrCredite;
    }

    void afisare() const {
        cout << "Materie ID: " << idMaterie << endl;
        cout << "Nume: " << nume << endl;
        cout << "Nr credite: " << nrCredite << endl;
        cout << "Nr note: " << nrNote << endl;
        if (note != NULL && nrNote > 0) {
            cout << "Note: ";
            for (int i = 0; i < nrNote; i++) cout << note[i] << " ";
            cout << endl;
        }
        cout << " " << endl;
    }

    friend float sumaCredite(const Materie& m);
    friend int totalRestanteMaterie(const Materie& m);

    friend ostream& operator<<(ostream& out, const Materie& m) {
        out << m.idMaterie << endl;
        out << m.nume << endl;
        out << m.nrCredite << endl;
        out << m.nrNote << endl;
        for (int i = 0; i < m.nrNote; i++) out << m.note[i] << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Materie& m) {
        if (m.note != NULL) { delete[] m.note; m.note = NULL; }
        m.nrNote = 0;

        cout << "Nume materie: ";
        in >> ws;
        getline(in, m.nume);

        cout << "Nr credite: ";
        in >> m.nrCredite;
        if (m.nrCredite < 0) m.nrCredite = 0;

        cout << "Nr note: ";
        in >> m.nrNote;
        if (m.nrNote > 0) {
            m.note = new float[m.nrNote];
            for (int i = 0; i < m.nrNote; i++) {
                cout << "Nota " << i << ": ";
                in >> m.note[i];
            }
        }
        else {
            m.nrNote = 0;
            m.note = NULL;
        }
        return in;
    }

    void salveazaText(const char* numeFisier) const {
        ofstream f(numeFisier, ios::out);
        f << *this;
        f.close();
    }

    void incarcaText(const char* numeFisier) {
        ifstream f(numeFisier, ios::in);
        if (!f.is_open()) return;

        int idDummy;
        f >> idDummy;
        f >> ws;
        getline(f, nume);
        f >> nrCredite;
        f >> nrNote;

        if (note != NULL) delete[] note;
        if (nrNote > 0) {
            note = new float[nrNote];
            for (int i = 0; i < nrNote; i++) f >> note[i];
        }
        else {
            note = NULL;
        }
        f.close();
    }
};
int Materie::contorMaterii = 0;

class Nota {
private:
    const int idNota;
    static int contorNote;

    float valoare;
    string data;
    int nrRestante;
    float* noteRestante;

public:
    Nota() : idNota(++contorNote) {
        valoare = 0;
        data = "N/A";
        nrRestante = 0;
        noteRestante = NULL;
    }

    Nota(float valoare, string data) : idNota(++contorNote) {
        this->valoare = valoare;
        this->data = data;
        nrRestante = 0;
        noteRestante = NULL;
    }

    Nota(float valoare, string data, int nrRestante, float* noteRestante) : idNota(++contorNote) {
        this->valoare = valoare;
        this->data = data;

        if (nrRestante > 0 && noteRestante != NULL) {
            this->nrRestante = nrRestante;
            this->noteRestante = new float[this->nrRestante];
            for (int i = 0; i < this->nrRestante; i++) this->noteRestante[i] = noteRestante[i];
        }
        else {
            this->nrRestante = 0;
            this->noteRestante = NULL;
        }
    }

    Nota(const Nota& n) : idNota(n.idNota) {
        valoare = n.valoare;
        data = n.data;

        if (n.nrRestante > 0 && n.noteRestante != NULL) {
            nrRestante = n.nrRestante;
            noteRestante = new float[nrRestante];
            for (int i = 0; i < nrRestante; i++) noteRestante[i] = n.noteRestante[i];
        }
        else {
            nrRestante = 0;
            noteRestante = NULL;
        }
    }

    ~Nota() {
        if (noteRestante != NULL) delete[] noteRestante;
    }

    Nota& operator=(const Nota& n) {
        if (this != &n) {
            if (noteRestante != NULL) delete[] noteRestante;

            valoare = n.valoare;
            data = n.data;

            if (n.nrRestante > 0 && n.noteRestante != NULL) {
                nrRestante = n.nrRestante;
                noteRestante = new float[nrRestante];
                for (int i = 0; i < nrRestante; i++) noteRestante[i] = n.noteRestante[i];
            }
            else {
                nrRestante = 0;
                noteRestante = NULL;
            }
        }
        return *this;
    }

    float getValoare() const { return valoare; }
    string getData() const { return data; }
    int getNrRestante() const { return nrRestante; }
    float* getNoteRestante() const {
        if (nrRestante <= 0 || noteRestante == NULL) return NULL;
        float* copie = new float[nrRestante];
        for (int i = 0; i < nrRestante; i++) copie[i] = noteRestante[i];
        return copie;
    }
    int getIdNota() const { return idNota; }

    void setValoare(float v) { valoare = v; }
    void setData(string d) { data = d; }
    void setRestante(int nr, float* v) {
        if (noteRestante != NULL) delete[] noteRestante;

        if (nr > 0 && v != NULL) {
            nrRestante = nr;
            noteRestante = new float[nrRestante];
            for (int i = 0; i < nrRestante; i++) noteRestante[i] = v[i];
        }
        else {
            nrRestante = 0;
            noteRestante = NULL;
        }
    }

    static int getContorNote() { return contorNote; }
    static void setContorNote(int c) { contorNote = c; }

    static float inProcent(float nota) {
        if (nota < 0) return 0;
        if (nota > 10) nota = 10;
        return nota * 10;
    }

    Nota& operator++() {
        valoare = valoare + 1;
        if (valoare > 10) valoare = 10;
        return *this;
    }

    bool operator>(const Nota& n) const {
        return this->valoare > n.valoare;
    }

    explicit operator float() const {
        return valoare;
    }

    void afisare() const {
        cout << "Nota ID: " << idNota << endl;
        cout << "Valoare: " << valoare << endl;
        cout << "Data: " << data << endl;
        cout << "Nr restante: " << nrRestante << endl;
        if (noteRestante != NULL && nrRestante > 0) {
            cout << "Note restante: ";
            for (int i = 0; i < nrRestante; i++) cout << noteRestante[i] << " ";
            cout << endl;
        }
        cout << " " << endl;
    }

    friend int totalRestanteNota(const Nota& n);
    friend float maximRestante(const Nota& n);

    friend ostream& operator<<(ostream& out, const Nota& n) {
        out << n.idNota << endl;
        out << n.valoare << endl;
        out << n.data << endl;
        out << n.nrRestante << endl;
        for (int i = 0; i < n.nrRestante; i++) out << n.noteRestante[i] << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Nota& n) {
        if (n.noteRestante != NULL) { delete[] n.noteRestante; n.noteRestante = NULL; }
        n.nrRestante = 0;

        cout << "Valoare nota: ";
        in >> n.valoare;

        cout << "Data: ";
        in >> ws;
        getline(in, n.data);

        cout << "Nr restante: ";
        in >> n.nrRestante;
        if (n.nrRestante > 0) {
            n.noteRestante = new float[n.nrRestante];
            for (int i = 0; i < n.nrRestante; i++) {
                cout << "Restanta " << i << ": ";
                in >> n.noteRestante[i];
            }
        }
        else {
            n.nrRestante = 0;
            n.noteRestante = NULL;
        }

        return in;
    }

    void salveazaBinar(const char* numeFisier) const {
        ofstream f(numeFisier, ios::binary | ios::out);
        if (!f.is_open()) return;

        f.write((char*)&valoare, sizeof(valoare));

        int lg = (int)data.size();
        f.write((char*)&lg, sizeof(lg));
        f.write(data.c_str(), lg);

        f.write((char*)&nrRestante, sizeof(nrRestante));
        for (int i = 0; i < nrRestante; i++) f.write((char*)&noteRestante[i], sizeof(float));

        f.close();
    }

    void incarcaBinar(const char* numeFisier) {
        ifstream f(numeFisier, ios::binary | ios::in);
        if (!f.is_open()) return;

        if (noteRestante != NULL) { delete[] noteRestante; noteRestante = NULL; }
        nrRestante = 0;

        f.read((char*)&valoare, sizeof(valoare));

        int lg = 0;
        f.read((char*)&lg, sizeof(lg));
        char* buffer = new char[lg + 1];
        f.read(buffer, lg);
        buffer[lg] = '\0';
        data = buffer;
        delete[] buffer;

        f.read((char*)&nrRestante, sizeof(nrRestante));
        if (nrRestante > 0) {
            noteRestante = new float[nrRestante];
            for (int i = 0; i < nrRestante; i++) f.read((char*)&noteRestante[i], sizeof(float));
        }
        else {
            noteRestante = NULL;
        }

        f.close();
    }
};
int Nota::contorNote = 0;

class Orar {
private:
    const int idOrar;
    static int contorOrar;

    string numeStudent;
    int nrZile;
    int* orePeZi;
    int nrMaterii;
    string* denumiriMaterii;

public:
    Orar() : idOrar(++contorOrar) {
        numeStudent = "Anonim";
        nrZile = 0;
        orePeZi = NULL;
        nrMaterii = 0;
        denumiriMaterii = NULL;
    }

    Orar(string numeStudent, int nrZile) : idOrar(++contorOrar) {
        this->numeStudent = numeStudent;

        if (nrZile > 0) {
            this->nrZile = nrZile;
            orePeZi = new int[this->nrZile];
            for (int i = 0; i < this->nrZile; i++) orePeZi[i] = 0;
        }
        else {
            this->nrZile = 0;
            orePeZi = NULL;
        }

        nrMaterii = 0;
        denumiriMaterii = NULL;
    }

    Orar(string numeStudent, int nrZile, int* orePeZi, int nrMaterii) : idOrar(++contorOrar) {
        this->numeStudent = numeStudent;

        if (nrZile > 0 && orePeZi != NULL) {
            this->nrZile = nrZile;
            this->orePeZi = new int[this->nrZile];
            for (int i = 0; i < this->nrZile; i++) this->orePeZi[i] = orePeZi[i];
        }
        else {
            this->nrZile = 0;
            this->orePeZi = NULL;
        }

        if (nrMaterii > 0) {
            this->nrMaterii = nrMaterii;
            denumiriMaterii = new string[this->nrMaterii];
            for (int i = 0; i < this->nrMaterii; i++) denumiriMaterii[i] = "Materie" + to_string(i + 1);
        }
        else {
            this->nrMaterii = 0;
            denumiriMaterii = NULL;
        }
    }

    Orar(const Orar& o) : idOrar(o.idOrar) {
        numeStudent = o.numeStudent;

        if (o.nrZile > 0 && o.orePeZi != NULL) {
            nrZile = o.nrZile;
            orePeZi = new int[nrZile];
            for (int i = 0; i < nrZile; i++) orePeZi[i] = o.orePeZi[i];
        }
        else {
            nrZile = 0;
            orePeZi = NULL;
        }

        if (o.nrMaterii > 0 && o.denumiriMaterii != NULL) {
            nrMaterii = o.nrMaterii;
            denumiriMaterii = new string[nrMaterii];
            for (int i = 0; i < nrMaterii; i++) denumiriMaterii[i] = o.denumiriMaterii[i];
        }
        else {
            nrMaterii = 0;
            denumiriMaterii = NULL;
        }
    }

    ~Orar() {
        if (orePeZi != NULL) delete[] orePeZi;
        if (denumiriMaterii != NULL) delete[] denumiriMaterii;
    }

    Orar& operator=(const Orar& o) {
        if (this != &o) {
            if (orePeZi != NULL) delete[] orePeZi;
            if (denumiriMaterii != NULL) delete[] denumiriMaterii;

            numeStudent = o.numeStudent;

            if (o.nrZile > 0 && o.orePeZi != NULL) {
                nrZile = o.nrZile;
                orePeZi = new int[nrZile];
                for (int i = 0; i < nrZile; i++) orePeZi[i] = o.orePeZi[i];
            }
            else {
                nrZile = 0;
                orePeZi = NULL;
            }

            if (o.nrMaterii > 0 && o.denumiriMaterii != NULL) {
                nrMaterii = o.nrMaterii;
                denumiriMaterii = new string[nrMaterii];
                for (int i = 0; i < nrMaterii; i++) denumiriMaterii[i] = o.denumiriMaterii[i];
            }
            else {
                nrMaterii = 0;
                denumiriMaterii = NULL;
            }
        }
        return *this;
    }

    string getNumeStudent() const { return numeStudent; }
    int getNrZile() const { return nrZile; }
    int* getOrePeZi() const {
        if (nrZile <= 0 || orePeZi == NULL) return NULL;
        int* copie = new int[nrZile];
        for (int i = 0; i < nrZile; i++) copie[i] = orePeZi[i];
        return copie;
    }
    int getNrMaterii() const { return nrMaterii; }
    string* getDenumiriMaterii() const {
        if (nrMaterii <= 0 || denumiriMaterii == NULL) return NULL;
        string* copie = new string[nrMaterii];
        for (int i = 0; i < nrMaterii; i++) copie[i] = denumiriMaterii[i];
        return copie;
    }
    int getIdOrar() const { return idOrar; }

    void setNumeStudent(string s) { numeStudent = s; }

    void setOrePeZi(int nrZile, int* v) {
        if (orePeZi != NULL) delete[] orePeZi;

        if (nrZile > 0 && v != NULL) {
            this->nrZile = nrZile;
            orePeZi = new int[this->nrZile];
            for (int i = 0; i < this->nrZile; i++) orePeZi[i] = v[i];
        }
        else {
            this->nrZile = 0;
            orePeZi = NULL;
        }
    }

    void setMaterii(int nrMaterii, string* v) {
        if (denumiriMaterii != NULL) delete[] denumiriMaterii;

        if (nrMaterii > 0 && v != NULL) {
            this->nrMaterii = nrMaterii;
            denumiriMaterii = new string[this->nrMaterii];
            for (int i = 0; i < this->nrMaterii; i++) denumiriMaterii[i] = v[i];
        }
        else {
            this->nrMaterii = 0;
            denumiriMaterii = NULL;
        }
    }

    static int getContorOrar() { return contorOrar; }
    static void setContorOrar(int c) { contorOrar = c; }

    static int calculeazaTotalOre(int nrZile, int* v) {
        if (nrZile <= 0 || v == NULL) return 0;
        int total = 0;
        for (int i = 0; i < nrZile; i++) total += v[i];
        return total;
    }

    Orar& operator+=(int oreInPlus) {
        if (nrZile > 0 && orePeZi != NULL && oreInPlus > 0) {
            orePeZi[0] = orePeZi[0] + oreInPlus;
        }
        return *this;
    }

    int operator[](int zi) const {
        if (zi >= 0 && zi < nrZile && orePeZi != NULL) return orePeZi[zi];
        return -1;
    }

    bool operator!() const {
        return (nrZile == 0 || orePeZi == NULL);
    }

    void afisare() const {
        cout << "Orar ID: " << idOrar << endl;
        cout << "Student: " << numeStudent << endl;
        cout << "Nr zile: " << nrZile << endl;
        if (orePeZi != NULL && nrZile > 0) {
            cout << "Ore pe zi: ";
            for (int i = 0; i < nrZile; i++) cout << orePeZi[i] << " ";
            cout << endl;
        }
        cout << "Nr materii: " << nrMaterii << endl;
        if (denumiriMaterii != NULL && nrMaterii > 0) {
            cout << "Materii: ";
            for (int i = 0; i < nrMaterii; i++) cout << denumiriMaterii[i] << " ";
            cout << endl;
        }
        cout << " " << endl;
    }

    friend int totalOreOrar(const Orar& o);
    friend bool studentAreMulteOre(const Orar& o);

    friend ostream& operator<<(ostream& out, const Orar& o) {
        out << o.idOrar << endl;
        out << o.numeStudent << endl;
        out << o.nrZile << endl;
        for (int i = 0; i < o.nrZile; i++) out << o.orePeZi[i] << endl;
        out << o.nrMaterii << endl;
        for (int i = 0; i < o.nrMaterii; i++) out << o.denumiriMaterii[i] << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Orar& o) {
        if (o.orePeZi != NULL) { delete[] o.orePeZi; o.orePeZi = NULL; }
        if (o.denumiriMaterii != NULL) { delete[] o.denumiriMaterii; o.denumiriMaterii = NULL; }
        o.nrZile = 0;
        o.nrMaterii = 0;

        cout << "Nume student: ";
        in >> ws;
        getline(in, o.numeStudent);

        cout << "Nr zile: ";
        in >> o.nrZile;

        if (o.nrZile > 0) {
            o.orePeZi = new int[o.nrZile];
            for (int i = 0; i < o.nrZile; i++) {
                cout << "Ore zi " << i << ": ";
                in >> o.orePeZi[i];
            }
        }
        else {
            o.nrZile = 0;
            o.orePeZi = NULL;
        }

        cout << "Nr materii: ";
        in >> o.nrMaterii;

        if (o.nrMaterii > 0) {
            o.denumiriMaterii = new string[o.nrMaterii];
            for (int i = 0; i < o.nrMaterii; i++) {
                cout << "Materie " << i << ": ";
                in >> ws;
                getline(in, o.denumiriMaterii[i]);
            }
        }
        else {
            o.nrMaterii = 0;
            o.denumiriMaterii = NULL;
        }

        return in;
    }

    void salveazaText(const char* numeFisier) const {
        ofstream f(numeFisier, ios::out);
        f << *this;
        f.close();
    }

    void incarcaText(const char* numeFisier) {
        ifstream f(numeFisier, ios::in);
        if (!f.is_open()) return;

        int idDummy;
        f >> idDummy;

        f >> ws;
        getline(f, numeStudent);

        f >> nrZile;
        if (orePeZi != NULL) delete[] orePeZi;
        if (nrZile > 0) {
            orePeZi = new int[nrZile];
            for (int i = 0; i < nrZile; i++) f >> orePeZi[i];
        }
        else {
            orePeZi = NULL;
        }

        f >> nrMaterii;
        if (denumiriMaterii != NULL) delete[] denumiriMaterii;
        if (nrMaterii > 0) {
            denumiriMaterii = new string[nrMaterii];
            f >> ws;
            for (int i = 0; i < nrMaterii; i++) {
                getline(f, denumiriMaterii[i]);
            }
        }
        else {
            denumiriMaterii = NULL;
        }

        f.close();
    }
};
int Orar::contorOrar = 0;

float sumaCredite(const Materie& m) {
    return (float)m.nrCredite;
}

int totalRestanteMaterie(const Materie& m) {
    if (m.nrNote <= 0 || m.note == NULL) return 0;
    int c = 0;
    for (int i = 0; i < m.nrNote; i++) if (m.note[i] < 5) c++;
    return c;
}

int totalRestanteNota(const Nota& n) {
    return n.nrRestante;
}

float maximRestante(const Nota& n) {
    if (n.nrRestante <= 0 || n.noteRestante == NULL) return 0;
    float mx = n.noteRestante[0];
    for (int i = 1; i < n.nrRestante; i++) if (n.noteRestante[i] > mx) mx = n.noteRestante[i];
    return mx;
}

int totalOreOrar(const Orar& o) {
    if (o.nrZile <= 0 || o.orePeZi == NULL) return 0;
    int s = 0;
    for (int i = 0; i < o.nrZile; i++) s += o.orePeZi[i];
    return s;
}

bool studentAreMulteOre(const Orar& o) {
    return totalOreOrar(o) >= 25;
}

class Catalog {
private:
    const int idCatalog;
    static int contorCataloage;

    string numeStudent;
    Materie materie;
    int nrNote;
    Nota* note;

public:
    Catalog() : idCatalog(++contorCataloage), materie() {
        numeStudent = "Anonim";
        nrNote = 0;
        note = NULL;
    }

    Catalog(string numeStudent, Materie materie) : idCatalog(++contorCataloage), materie(materie) {
        this->numeStudent = numeStudent;
        nrNote = 0;
        note = NULL;
    }

    Catalog(string numeStudent, Materie materie, int nrNote, Nota* note) : idCatalog(++contorCataloage), materie(materie) {
        this->numeStudent = numeStudent;

        if (nrNote > 0 && note != NULL) {
            this->nrNote = nrNote;
            this->note = new Nota[this->nrNote];
            for (int i = 0; i < this->nrNote; i++) this->note[i] = note[i];
        }
        else {
            this->nrNote = 0;
            this->note = NULL;
        }
    }

    Catalog(const Catalog& c) : idCatalog(c.idCatalog), materie(c.materie) {
        numeStudent = c.numeStudent;

        if (c.nrNote > 0 && c.note != NULL) {
            nrNote = c.nrNote;
            note = new Nota[nrNote];
            for (int i = 0; i < nrNote; i++) note[i] = c.note[i];
        }
        else {
            nrNote = 0;
            note = NULL;
        }
    }

    ~Catalog() {
        if (note != NULL) delete[] note;
    }

    Catalog& operator=(const Catalog& c) {
        if (this != &c) {
            if (note != NULL) delete[] note;

            numeStudent = c.numeStudent;
            materie = c.materie;

            if (c.nrNote > 0 && c.note != NULL) {
                nrNote = c.nrNote;
                note = new Nota[nrNote];
                for (int i = 0; i < nrNote; i++) note[i] = c.note[i];
            }
            else {
                nrNote = 0;
                note = NULL;
            }
        }
        return *this;
    }

    int getIdCatalog() const { return idCatalog; }
    string getNumeStudent() const { return numeStudent; }
    Materie getMaterie() const { return materie; }
    int getNrNote() const { return nrNote; }

    Nota* getNote() const {
        if (nrNote <= 0 || note == NULL) return NULL;
        Nota* copie = new Nota[nrNote];
        for (int i = 0; i < nrNote; i++) copie[i] = note[i];
        return copie;
    }

    void setNumeStudent(string s) { numeStudent = s; }
    void setMaterie(const Materie& m) { materie = m; }

    void setNote(int nr, Nota* v) {
        if (note != NULL) delete[] note;

        if (nr > 0 && v != NULL) {
            nrNote = nr;
            note = new Nota[nrNote];
            for (int i = 0; i < nrNote; i++) note[i] = v[i];
        }
        else {
            nrNote = 0;
            note = NULL;
        }
    }

    static int getContorCataloage() { return contorCataloage; }

    void afisare() const {
        cout << "Catalog ID: " << idCatalog << endl;
        cout << "Student: " << numeStudent << endl;
        cout << "Materie: " << materie.getNume() << endl;
        cout << "Nr note: " << nrNote << endl;
        for (int i = 0; i < nrNote; i++) {
            cout << "Nota " << i << ": " << note[i].getValoare() << " (" << note[i].getData() << ")" << endl;
        }
        cout << " " << endl;
    }

    Catalog& operator+=(const Nota& n) {
        Nota* nou = new Nota[nrNote + 1];
        for (int i = 0; i < nrNote; i++) nou[i] = note[i];
        nou[nrNote] = n;

        if (note != NULL) delete[] note;
        note = nou;
        nrNote++;

        return *this;
    }

    Catalog& operator-=(int) {
        if (nrNote <= 0) return *this;

        Nota* nou = NULL;
        if (nrNote - 1 > 0) {
            nou = new Nota[nrNote - 1];
            for (int i = 0; i < nrNote - 1; i++) nou[i] = note[i];
        }

        if (note != NULL) delete[] note;
        note = nou;
        nrNote--;

        return *this;
    }

    Nota operator[](int index) const {
        if (index >= 0 && index < nrNote && note != NULL) return note[index];
        return Nota();
    }

    void salveazaBinar(const char* numeFisier) const {
        ofstream f(numeFisier, ios::binary | ios::out);
        if (!f.is_open()) return;

        int lg = (int)numeStudent.size();
        f.write((char*)&lg, sizeof(lg));
        f.write(numeStudent.c_str(), lg);

        string numeMaterie = materie.getNume();
        int lgm = (int)numeMaterie.size();
        f.write((char*)&lgm, sizeof(lgm));
        f.write(numeMaterie.c_str(), lgm);

        int cred = materie.getNrCredite();
        f.write((char*)&cred, sizeof(cred));

        f.write((char*)&nrNote, sizeof(nrNote));
        for (int i = 0; i < nrNote; i++) {
            float v = note[i].getValoare();
            f.write((char*)&v, sizeof(v));

            string d = note[i].getData();
            int lgd = (int)d.size();
            f.write((char*)&lgd, sizeof(lgd));
            f.write(d.c_str(), lgd);
        }

        f.close();
    }

    void incarcaBinar(const char* numeFisier) {
        ifstream f(numeFisier, ios::binary | ios::in);
        if (!f.is_open()) return;

        if (note != NULL) { delete[] note; note = NULL; }
        nrNote = 0;

        int lg = 0;
        f.read((char*)&lg, sizeof(lg));
        char* buf = new char[lg + 1];
        f.read(buf, lg);
        buf[lg] = '\0';
        numeStudent = buf;
        delete[] buf;

        int lgm = 0;
        f.read((char*)&lgm, sizeof(lgm));
        char* bufm = new char[lgm + 1];
        f.read(bufm, lgm);
        bufm[lgm] = '\0';
        string numeMat = bufm;
        delete[] bufm;

        int cred = 0;
        f.read((char*)&cred, sizeof(cred));
        materie = Materie(numeMat, cred);

        f.read((char*)&nrNote, sizeof(nrNote));
        if (nrNote > 0) {
            note = new Nota[nrNote];
            for (int i = 0; i < nrNote; i++) {
                float v = 0;
                f.read((char*)&v, sizeof(v));

                int lgd = 0;
                f.read((char*)&lgd, sizeof(lgd));
                char* bufd = new char[lgd + 1];
                f.read(bufd, lgd);
                bufd[lgd] = '\0';
                string d = bufd;
                delete[] bufd;

                note[i] = Nota(v, d);
            }
        }
        else {
            note = NULL;
        }

        f.close();
    }
};
int Catalog::contorCataloage = 0;

class MaterieOptionala : public Materie {
private:
    bool esteOptionala;
public:
    MaterieOptionala() : Materie() {
        esteOptionala = true;
    }
    MaterieOptionala(string nume, int credite, bool opt) : Materie(nume, credite) {
        esteOptionala = opt;
    }
    bool getEsteOptionala() const { return esteOptionala; }
    void setEsteOptionala(bool v) { esteOptionala = v; }
};

class OrarSemestru : public Orar {
private:
    int semestru;
public:
    OrarSemestru() : Orar() {
        semestru = 1;
    }
    OrarSemestru(string student, int nrZile, int semestru) : Orar(student, nrZile) {
        this->semestru = (semestru > 0 ? semestru : 1);
    }
    int getSemestru() const { return semestru; }
    void setSemestru(int s) { semestru = (s > 0 ? s : 1); }
};

int main() {
    cout << "FAZA 1 + 2 + 3 (teste constructori, get/set, friend, operatori)" << endl;
    cout << " " << endl;

    float notePOO[3] = { 8.5f, 9.0f, 10.0f };
    Materie m1;
    Materie m2("Programare", 5);
    Materie m3("POO", 6, 3, notePOO);

    m1.afisare();
    m2.afisare();
    m3.afisare();

    cout << "Media POO (static): " << Materie::calculeazaMedie(3, notePOO) << endl;
    cout << "Suma credite (friend): " << sumaCredite(m3) << endl;
    cout << "Restante in materie (friend): " << totalRestanteMaterie(m3) << endl;
    cout << " " << endl;

    float restante[2] = { 4.0f, 6.5f };
    Nota n1;
    Nota n2(9.5f, "2025-01-10");
    Nota n3(6.0f, "2025-01-12", 2, restante);

    n1.afisare();
    n2.afisare();
    n3.afisare();

    cout << "Nota 9.5 in procent: " << Nota::inProcent(9.5f) << endl;
    cout << "Total restante (friend): " << totalRestanteNota(n3) << endl;
    cout << "Max restanta (friend): " << maximRestante(n3) << endl;
    cout << " " << endl;

    int ore[5] = { 4, 6, 5, 3, 4 };
    Orar o1;
    Orar o2("Oana Moisa", 5);
    Orar o3("Oana Nicoleta Moisa", 5, ore, 3);

    o1.afisare();
    o2.afisare();
    o3.afisare();

    cout << "Total ore (static): " << Orar::calculeazaTotalOre(5, ore) << endl;
    cout << "Total ore (friend): " << totalOreOrar(o3) << endl;
    cout << "Are multe ore (friend): " << (studentAreMulteOre(o3) ? "Da" : "Nu") << endl;
    cout << " " << endl;

    Materie m4 = m3 + 2;
    cout << "m3 credite: " << m3.getNrCredite() << " | m4 credite: " << m4.getNrCredite() << endl;
    cout << "m3[1]: " << m3[1] << endl;
    cout << "m2 < m3: " << (m2 < m3 ? "Da" : "Nu") << endl;
    cout << " " << endl;

    ++n2;
    cout << "n2 dupa ++: " << n2.getValoare() << endl;
    cout << "n2 > n3: " << (n2 > n3 ? "Da" : "Nu") << endl;
    float castNota = (float)n2;
    cout << "cast float n2: " << castNota << endl;
    cout << " " << endl;

    o2 += 3;
    cout << "o2[0] dupa += 3: " << o2[0] << endl;
    cout << "!o1: " << (!o1 ? "true" : "false") << endl;
    cout << " " << endl;

    cout << "FAZA 4 (vectori + o matrice citire/afisare)" << endl;
    cout << " " << endl;

    const int DIM = 2;
    Materie vMaterii[DIM];
    Nota vNote[DIM];
    Orar vOrar[DIM];

    for (int i = 0; i < DIM; i++) {
        cout << "Citire Materie " << i << endl;
        cin >> vMaterii[i];
        cout << " " << endl;
    }
    for (int i = 0; i < DIM; i++) vMaterii[i].afisare();

    for (int i = 0; i < DIM; i++) {
        cout << "Citire Nota " << i << endl;
        cin >> vNote[i];
        cout << " " << endl;
    }
    for (int i = 0; i < DIM; i++) vNote[i].afisare();

    for (int i = 0; i < DIM; i++) {
        cout << "Citire Orar " << i << endl;
        cin >> vOrar[i];
        cout << " " << endl;
    }
    for (int i = 0; i < DIM; i++) vOrar[i].afisare();

    const int R = 2, C = 2;
    Materie matMaterii[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << "Citire Materie matrice [" << i << "][" << j << "]" << endl;
            cin >> matMaterii[i][j];
            cout << " " << endl;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) matMaterii[i][j].afisare();
    }

    cout << "FAZA 5 (Catalog - has-a + operatori)" << endl;
    cout << " " << endl;

    Catalog c1;
    Catalog c2("Oana Nicoleta Moisa", m3);

    c1.afisare();
    c2.afisare();

    c2 += n2;
    c2 += n3;
    c2.afisare();

    c2 -= 0;
    c2.afisare();

    Nota nIdx = c2[0];
    cout << "Catalog[0] valoare: " << nIdx.getValoare() << endl;
    cout << " " << endl;

    cout << "FAZA 6 (fisiere text si binare)" << endl;
    cout << " " << endl;

    m3.salveazaText("Materie_ONM.txt");
    Materie mFis;
    mFis.incarcaText("Materie_ONM.txt");
    mFis.afisare();

    o3.salveazaText("Orar_ONM.txt");
    Orar oFis;
    oFis.incarcaText("Orar_ONM.txt");
    oFis.afisare();

    n3.salveazaBinar("Nota_ONM.bin");
    Nota nFis;
    nFis.incarcaBinar("Nota_ONM.bin");
    nFis.afisare();

    c2.salveazaBinar("Catalog_ONM.bin");
    Catalog cFis;
    cFis.incarcaBinar("Catalog_ONM.bin");
    cFis.afisare();

    cout << "FAZA 7 (mostenire + upcasting)" << endl;
    cout << " " << endl;

    MaterieOptionala mo("Psihologie", 3, true);
    cout << "Optionala: " << (mo.getEsteOptionala() ? "Da" : "Nu") << endl;
    cout << " " << endl;

    OrarSemestru os("Oana Nicoleta Moisa", 5, 2);
    cout << "Semestru: " << os.getSemestru() << endl;
    cout << " " << endl;

    Materie* pMaterie = new MaterieOptionala("Sport", 2, true);
    cout << "Upcasting Materie* -> getNrCredite: " << pMaterie->getNrCredite() << endl;
    delete pMaterie;

    Orar* pOrar = new OrarSemestru("Oana Nicoleta Moisa", 5, 1);
    cout << "Upcasting Orar* -> getNumeStudent: " << pOrar->getNumeStudent() << endl;
    delete pOrar;

    cout << " " << endl;
    cout << "FINAL" << endl;
    cout << " " << endl;

    return 0;
}