#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    const int id;
    static int nextId;

    string nume;
    int varsta;
    double medie;
    bool bursier;
    char* specializare;

public:
    Student() : id(nextId++) {
        nume = "";
        varsta = 0;
        medie = 0;
        bursier = false;
        specializare = nullptr;
    }

    Student(string nume, int varsta, double medie, bool bursier, const char* specializare)
        : id(nextId++) {
        this->nume = nume;
        this->varsta = varsta;
        this->medie = medie;
        this->bursier = bursier;

        if (specializare != nullptr) {
            this->specializare = new char[strlen(specializare) + 1];
            strcpy_s(this->specializare, strlen(specializare) + 1, specializare);
        }
        else {
            this->specializare = nullptr;
        }
    }

    Student(const Student& s) : id(s.id) {
        nume = s.nume;
        varsta = s.varsta;
        medie = s.medie;
        bursier = s.bursier;

        if (s.specializare != nullptr) {
            specializare = new char[strlen(s.specializare) + 1];
            strcpy_s(specializare, strlen(s.specializare) + 1, s.specializare);
        }
        else {
            specializare = nullptr;
        }
    }

    ~Student() {
        if (specializare != nullptr)
            delete[] specializare;
    }

    Student& operator=(const Student& s) {
        if (this == &s) return *this;

        if (specializare != nullptr) delete[] specializare;

        nume = s.nume;
        varsta = s.varsta;
        medie = s.medie;
        bursier = s.bursier;

        if (s.specializare != nullptr) {
            specializare = new char[strlen(s.specializare) + 1];
            strcpy_s(specializare, strlen(s.specializare) + 1, s.specializare);
        }
        else {
            specializare = nullptr;
        }

        return *this;
    }

    int getId() const { return id; }
    string getNume() const { return nume; }
    int getVarsta() const { return varsta; }
    double getMedie() const { return medie; }
    bool getBursier() const { return bursier; }
    const char* getSpecializare() const { return specializare; }

    void setVarsta(int v) { varsta = v; }
    void setMedie(double m) { medie = m; }
    void setBursier(bool b) { bursier = b; }

    void setSpecializare(const char* s) {
        if (specializare != nullptr) delete[] specializare;
        if (s != nullptr) {
            specializare = new char[strlen(s) + 1];
            strcpy_s(specializare, strlen(specializare) + 1, s);
        }
        else {
            specializare = nullptr;
        }
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "ID: " << s.id << endl;
        out << "Nume: " << s.nume << endl;
        out << "Varsta: " << s.varsta << endl;
        out << "Medie: " << s.medie << endl;
        out << "Bursier: " << (s.bursier ? "DA" : "NU") << endl;
        out << "Specializare: " << (s.specializare ? s.specializare : "-") << endl;
        return out;
    }

    bool operator!() const {
        return medie < 5;
    }

    void operator~() {
        bursier = !bursier;
    }

    Student& operator++() {
        varsta++;
        return *this;
    }
};

int Student::nextId = 1;

int main() {
    Student s1("Popescu Andrei", 20, 8.7, true, "Informatica");
    Student s2("Ionescu Maria", 19, 4.5, false, "Management");

    cout << s1 << endl;
    cout << s2 << endl;

    cout << (!s2 ? "Sub medie" : "Peste medie") << endl;

    ~s1;
    cout << s1 << endl;

    Student s3 = s1;
    cout << s3 << endl;

    ++s2;
    cout << s2 << endl;

    return 0;
}
