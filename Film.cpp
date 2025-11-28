#include <iostream>
#include <cstring>
using namespace std;

class Film {
private:
    const int id;
    static int nextId;

    string titlu;
    double rating;
    int durata;
    bool difuzare;
    char* gen;

public:
    Film() : id(nextId++) {
        titlu = "";
        rating = 0;
        durata = 0;
        difuzare = false;
        gen = nullptr;
    }

    Film(string titlu, double rating, int durata, bool difuzare, const char* gen)
        : id(nextId++) {
        this->titlu = titlu;
        this->rating = rating;
        this->durata = durata;
        this->difuzare = difuzare;

        if (gen != nullptr) {
            this->gen = new char[strlen(gen) + 1];
            strcpy_s(this->gen, strlen(gen) + 1, gen);
        }
        else {
            this->gen = nullptr;
        }
    }

    Film(const Film& f) : id(f.id) {
        titlu = f.titlu;
        rating = f.rating;
        durata = f.durata;
        difuzare = f.difuzare;

        if (f.gen != nullptr) {
            gen = new char[strlen(f.gen) + 1];
            strcpy_s(gen, strlen(f.gen) + 1, f.gen);
        }
        else {
            gen = nullptr;
        }
    }

    ~Film() {
        if (gen != nullptr)
            delete[] gen;
    }

    Film& operator=(const Film& f) {
        if (this == &f) return *this;

        if (gen != nullptr) delete[] gen;

        titlu = f.titlu;
        rating = f.rating;
        durata = f.durata;
        difuzare = f.difuzare;

        if (f.gen != nullptr) {
            gen = new char[strlen(f.gen) + 1];
            strcpy_s(gen, strlen(f.gen) + 1, f.gen);
        }
        else {
            gen = nullptr;
        }

        return *this;
    }

    int getId() const { return id; }
    string getTitlu() const { return titlu; }
    double getRating() const { return rating; }
    int getDurata() const { return durata; }
    bool getDifuzare() const { return difuzare; }
    const char* getGen() const { return gen; }

    void setRating(double r) { rating = r; }
    void setDurata(int d) { durata = d; }
    void setDifuzare(bool df) { difuzare = df; }

    void setGen(const char* g) {
        if (gen != nullptr) delete[] gen;
        if (g != nullptr) {
            gen = new char[strlen(g) + 1];
            strcpy_s(gen, strlen(gen) + 1, g);
        }
        else {
            gen = nullptr;
        }
    }

    friend ostream& operator<<(ostream& out, const Film& f) {
        out << "ID: " << f.id << endl;
        out << "Titlu: " << f.titlu << endl;
        out << "Rating: " << f.rating << endl;
        out << "Durata: " << f.durata << endl;
        out << "Difuzare: " << (f.difuzare ? "DA" : "NU") << endl;
        out << "Gen: " << (f.gen ? f.gen : "-") << endl;
        return out;
    }

    bool operator!() const {
        return rating <= 0 || durata <= 0 || !difuzare;
    }

    void operator~() {
        difuzare = !difuzare;
    }

    Film& operator++() {
        durata++;
        return *this;
    }
};

int Film::nextId = 1;

int main() {
    Film f1("Matrix", 9.5, 130, true, "SciFi");
    Film f2("Test", 0, 0, false, "Necunoscut");

    cout << f1 << endl;
    cout << f2 << endl;

    cout << (!f2 ? "Exista film" : "Nu exista film") << endl;

    ~f1;
    cout << f1 << endl;

    Film f3 = f1;
    cout << f3 << endl;

    ++f2;
    cout << f2 << endl;

    return 0;
}
