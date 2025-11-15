//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//
//using namespace std;
//
//class IActiune {
//public:
//    virtual void deschide() = 0;
//    virtual ~IActiune() {}
//};
//
//class Fisier {
//protected:
//    static int nrFisiere;
//    const int idFisier;
//    string nume;
//    int dimensiune;
//    char* extensie;
//    string numeComplet;
//    string stare;
//
//public:
//    Fisier() :idFisier(++nrFisiere) {
//        this->nume = "Necunoscut";
//        this->dimensiune = 0;
//        this->extensie = nullptr;
//        this->numeComplet = this->nume + "extensie necunoscuta";
//        this->stare = "disponibil";
//    }
//
//    Fisier(string nume, int dimensiune, const char* ext, string stare) :idFisier(++nrFisiere) {
//        this->nume = nume;
//        this->dimensiune = dimensiune;
//        if (ext != nullptr) {
//            this->extensie = new char[strlen(ext) + 1];
//            strcpy_s(this->extensie, strlen(ext) + 1, ext);
//        }
//        else {
//            this->extensie = new char[strlen("Necunoscut") + 1];
//            strcpy_s(this->extensie, strlen("Necunoscut") + 1, "Necunoscut");
//        }
//        this->numeComplet = this->nume + this->extensie;
//
//        if (stare == "disponibil" || stare == "utilizat" || stare == "sters") {
//            this->stare = stare;
//        }
//        else {
//            this->stare = "Necunoscuta";
//        };
//
//    };
//
//    Fisier(const Fisier& f) :idFisier(f.idFisier) {
//        this->nume = f.nume;
//        this->dimensiune = f.dimensiune;
//        if (f.extensie != nullptr) {
//            this->extensie = new char[strlen(f.extensie) + 1];
//            strcpy_s(this->extensie, strlen(f.extensie) + 1, f.extensie);
//        }
//        else {
//            this->extensie = nullptr;
//        }
//
//        if (f.extensie != nullptr) {
//            this->numeComplet = f.nume + f.extensie;
//        }
//        else {
//            this->numeComplet = f.nume;
//        }
//        this->stare = f.stare;
//    };
//
//    string getNume() {
//        if (this->nume.size() > 0) {
//            return this->nume;
//        }
//    };
//
//    void setNume(string newName) {
//        if (newName.size() > 0) {
//            this->nume = newName;
//        };
//    };
//
//    string getStare() {
//        return this->stare;
//    }
//
//    Fisier& operator=(const Fisier& f) {
//        if (this != &f) {
//            if (this->extensie != nullptr) {
//                delete[] this->extensie;
//            }
//
//            if (f.dimensiune >= 0) {
//                this->dimensiune = f.dimensiune;
//            }
//            else {
//                this->dimensiune = 0;
//            }
//            if (f.nume.size() >= 1) {
//                this->nume = f.nume;
//            }
//            else {
//                this->nume = "Necunoscut";
//            }
//            if (f.numeComplet.size() >= 1) {
//                this->numeComplet = f.numeComplet;
//            }
//            else {
//                this->numeComplet = "Necunoscut";
//            }
//            if (f.stare == "disponibil" || f.stare == "utilizat" || f.stare == "sters") {
//                this->stare = f.stare;
//            }
//            else {
//                this->stare = "Necunoscuta";
//            }
//            if (f.extensie != nullptr) {
//                this->extensie = new char[strlen(f.extensie) + 1];
//                strcpy_s(this->extensie, strlen(f.extensie) + 1, f.extensie);
//            }
//            else {
//                this->extensie = nullptr;
//            }
//
//        }
//        return *this;
//    }
//
//    friend istream& operator>>(istream& in, Fisier& f) {
//        getline(in, f.nume);
//        in >> f.dimensiune;
//
//        if (f.extensie != nullptr) {
//            delete[] f.extensie;
//            f.extensie = nullptr;
//        }
//
//        char buffer[50];
//        in >> buffer;
//        f.extensie = new char[strlen(buffer) + 1];
//        strcpy_s(buffer, strlen(buffer) + 1, f.extensie);
//
//
//        getline(in, f.numeComplet);
//        getline(in, f.stare);
//        return in;
//    };
//
//    friend ostream& operator<<(ostream& out, Fisier& f) {
//        out << "nume: " << f.nume << endl;
//        out << "dimensiune: " << f.dimensiune << endl;
//        if (f.extensie != nullptr) {
//            out << "extensie: " << f.extensie << endl;
//        }
//        else {
//            out << "extensie: N/A" << endl;
//        }
//        out << "nume complet:" << f.numeComplet << endl;
//        out << "stare: " << f.stare << endl;
//
//        return out;
//
//
//    }
//};
//
//class FisierAudio : public Fisier, public IActiune {
//    int bitRate;
//
//public:
//
//    FisierAudio() :Fisier() {
//        this->bitRate = 0;
//    };
//
//    FisierAudio(string nume, int dimensiune, const char* ext, string stare, int bitRate) : Fisier(nume, dimensiune, ext, stare) {
//        this->bitRate = bitRate;
//    }
//
//    friend istream& operator>>(istream& in, FisierAudio& fa) {
//        getline(in, fa.nume);
//        in >> fa.dimensiune;
//
//        if (fa.extensie != nullptr) {
//            delete[] fa.extensie;
//            fa.extensie = nullptr;
//        }
//        else {
//            char buffer[50];
//            in >> buffer;
//            fa.extensie = new char[strlen(buffer) + 1];
//            strcpy_s(fa.extensie, strlen(buffer) + 1, buffer);
//        }
//
//        //getline(in, fa.numeComplet);
//        getline(in, fa.stare);
//        in >> fa.bitRate;
//        return in;
//    };
//
//    friend ostream& operator<<(ostream& out, FisierAudio& fa) {
//        out << "nume: " << fa.nume << endl;
//        out << "dimensiune: " << fa.dimensiune << endl;
//        if (fa.extensie != nullptr) {
//            out << "extensie: " << fa.extensie << endl;
//        }
//        else {
//            out << "extensie: N/A" << endl;
//        }
//        //out << "nume complet:" << fa.numeComplet << endl;
//        out << "stare: " << fa.stare << endl;
//        out << "bit rate: " << fa.bitRate << endl;
//
//        return out;
//    }
//
//    void deschide() override {
//        cout << "Deschidem fisierul audio cu numele: " << nume << endl;
//    }
//};
//
//class FisierVideo : public Fisier, public IActiune {
//    char* codec;
//
//public:
//
//    FisierVideo() :Fisier() {
//
//        this->codec = new char[strlen("Necunoscut") + 1];
//        strcpy_s(this->codec, strlen("Necunoscut") + 1, "Necunoscut");
//    };
//
//
//    FisierVideo(string nume, int dimensiune, const char* ext, string stare, const char* codec) : Fisier(nume, dimensiune, ext, stare) {
//
//        this->codec = new char[strlen(codec) + 1];
//        strcpy_s(this->codec, strlen(codec) + 1, codec);
//    };
//
//    friend istream& operator >>(istream& in, FisierVideo& fv) {
//        getline(in, fv.nume);
//        in >> fv.dimensiune;
//
//        if (fv.extensie != nullptr) {
//            delete[] fv.extensie;
//            fv.extensie = nullptr;
//        }
//        else {
//            char buffer[100];
//            in >> buffer;
//            fv.extensie = new char[strlen(buffer) + 1];
//            strcpy_s(fv.extensie, strlen(buffer) + 1, buffer);
//        }
//        //getline(in, fv.numeComplet);
//        getline(in, fv.stare);
//
//        if (fv.codec != nullptr) {
//            delete[] fv.codec;
//            fv.codec = nullptr;
//        }
//        else {
//            char buffer[50];
//            in >> buffer;
//            fv.codec = new char[strlen(buffer) + 1];
//            strcpy_s(fv.codec, strlen(buffer) + 1, buffer);
//        }
//
//        return in;
//    };
//
//    friend ostream& operator<<(ostream& out, FisierVideo fv) {
//        out << "nume: " << fv.nume << endl;
//        out << "dimensiune: " << fv.dimensiune << endl;
//        if (fv.extensie != nullptr) {
//            out << "extensie: " << fv.extensie << endl;
//        }
//        else {
//            out << "extensie: N/A" << endl;
//        }
//        //out << "nume complet:" << fv.numeComplet << endl;
//        out << "stare: " << fv.stare << endl;
//        if (fv.codec != nullptr) {
//            out << "codec: " << fv.codec << endl;
//        }
//        else {
//            out << "codec: N/A" << fv.codec << endl;
//        }
//
//        return out;
//    }
//
//    void deschide() override {
//        cout << "Deschidem fisierul video cu numele: " << this->nume << endl;
//    }
//
//
//};
//
//class Folder : public IActiune {
//    const int idFolder;
//    static int nrFoldere;
//    string nume;
//    int nrFisiere;
//    vector<Fisier> fisiere;
//
//public:
//    Folder() :idFolder(++nrFoldere) {
//        this->nume = "Necunoscut";
//    }
//
//    Folder(string nume, int nrFisiere, vector<Fisier> fis) :idFolder(++nrFoldere) {
//        this->nume = nume;
//        this->nrFisiere = nrFisiere;
//        this->fisiere = fis;
//    }
//
//    Folder(const Folder& f) :idFolder(f.idFolder) {
//        this->nume = f.nume;
//        this->nrFisiere = f.nrFisiere;
//        this->fisiere = f.fisiere;
//
//
//    };
//
//    string getNume() {
//        if (this->nume.size() > 0) {
//            return this->nume;
//        }
//    };
//
//    void setNume(string newName) {
//        if (newName.size() > 0) {
//            this->nume = newName;
//        };
//    };
//
//    friend istream& operator>>(istream& in, Folder& f) {
//        getline(in, f.nume);
//        in >> f.nrFisiere;
//        f.fisiere.clear();
//        for (size_t i = 0; i < f.nrFisiere; ++i) {
//            Fisier fisier;
//            string numeFisier;
//            getline(in, numeFisier);
//            fisier.setNume(numeFisier);
//            f.fisiere.push_back(fisier);
//        }
//        return in;
//
//    }
//
//    friend ostream& operator<<(ostream& out, Folder& f) {
//        out << f.nume << endl;
//        out << f.nrFisiere << endl;
//        out << "FISIERE:" << endl;
//        for (int i = 0; i < f.nrFisiere; i++) {
//            out << f.fisiere[i].getNume() << endl;
//        }
//        return out;
//    }
//
//    vector<Fisier> operator()(string stare) {
//        vector<Fisier> result;
//        if (stare != "disponibil" && stare != "utilizat" && stare != "sters") {
//            cout << "stare invalida!" << endl;
//        }
//        else {
//            for (int i = 0; i < this->nrFisiere; i++) {
//                if (this->fisiere[i].getStare() == stare) {
//                    result.push_back(this->fisiere[i]);
//                }
//            }
//        }
//        return result;
//    }
//
//    void deschide() override {
//        cout << "deschidem folderul cu numele: " << this->nume << endl;
//    }
//};
//
//
//
//int Fisier::nrFisiere = 0;
//int Folder::nrFoldere = 0;
//int main()
//{
//    Fisier f1;
//    Fisier f2("fis2", 20, ".exe", "utilizat");
//    Fisier f3 = f2;
//
//    cout << f1 << endl;
//    cout << f2 << endl;
//    cout << f3 << endl;
//
//    cout << f1.getNume() << endl;
//    f1.setNume("fis1");
//    cout << f1.getNume() << endl;
//
//    Folder fd1;
//    vector<Fisier> vectorFisiere;
//    vectorFisiere.push_back(f1);
//    vectorFisiere.push_back(f2);
//    Folder fd2("folder2", 2, vectorFisiere);
//    Folder fd3 = fd2;
//
//    cout << fd1 << endl;
//    cout << fd2 << endl;
//    cout << fd3 << endl;
//
//    cout << fd1.getNume() << endl;
//    fd1.setNume("folder1");
//    cout << fd1.getNume() << endl;
//
//    vector<Fisier> disponibile = fd2("utilizat");
//    for (Fisier fisier : disponibile) {
//        cout << "Nume: " << fisier.getNume() << endl;
//        cout << "STARE: " << fisier.getStare() << endl;
//
//    }
//
//    FisierAudio fa1;
//    FisierAudio fa2("fa2", 10, ".mp3", "utilizat", 20);
//    cout << fa1 << endl;
//    cout << fa2 << endl;
//
//    //TODO: FIX >> operator for FisierAudio and FisierVideo
///*    FisierAudio fa3;
//    cout << "Introduceti datele pentru FA (nume, dimensiune, extensie, stare, bitrate):" << endl;
//    cin >> fa3;
//    cout << fa3 << endl*/;
//
//    FisierVideo fv1;
//    FisierVideo fv2("fv2", 40, ".mp4", "sters", "un codec");
//    cout << fv1 << endl;
//    cout << fv2 << endl;
//
//    //FisierVideo fv3;
//    //cout << "Introduceti datele pentru FV (nume, dimensiune, extensie, stare, codec):" << endl;
//    //cin >> fv3;
//    //cout << fv3 << endl;
//
//    ///overriding, nu late-binding////
//    fd2.deschide();
//    fa2.deschide();
//    fv2.deschide();
//
//    //////late-binding//////
//    IActiune* actiunevideo = &fv2;
//
//    // Late binding: calls FisierVideo::deschide
//    actiunevideo->deschide();
//
//    IActiune* actiuneaudio = &fa2;
//    actiuneaudio->deschide();
//
//    IActiune* actiunefolder = &fd2;
//    actiunefolder->deschide();
//}
