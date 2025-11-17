//// destinatie, data de inceput, data de final, nr persoane, tip mese, tip camera, insotitori.
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<string>
//#include <vector> 
//using namespace std;
//
//enum TipCamera {
//	Single, Double, Deluxe
//};
//
//class Sejur {
//private:
//	int nrPers;
//	const int idSejur;
//	char* destinatie;
//	string dataInceput;
//	int tipMasa;
//	float* pretMese; // int tipMasa
//	static string Agentie;
//	bool cuInsotitor;
//	TipCamera camera;
//
//public:
//	Sejur() : idSejur(1) {
//		this->nrPers = 1;
//		this->destinatie = new char[strlen("Bali") + 1];
//		strcpy(this->destinatie, "Bali");
//		this->dataInceput = "Ian 2025";
//		this->tipMasa = 3;
//		this->pretMese = new float[tipMasa];
//		for (int i = 0; i < tipMasa; i++) {
//			this->pretMese[i] = 10.5;
//		}
//		this->cuInsotitor = false;
//		this->camera = Single;
//	}
//
//	Sejur(int nrPers, const int idSejur, const char* destinatie, string dataInceput, int tipMasa, float* pretMese, bool cuInsotitor, TipCamera camera) : idSejur(idSejur) {
//		this->nrPers = nrPers;
//		this->destinatie = new char[strlen(destinatie) + 1];
//		strcpy(this->destinatie, destinatie);
//		this->dataInceput = dataInceput;
//		this->tipMasa = tipMasa;
//		this->pretMese = new float[tipMasa];
//		for (int i = 0; i < tipMasa; i++) {
//			this->pretMese[i] = pretMese[i];
//		}
//		this->cuInsotitor = cuInsotitor;
//		this->camera = camera;
//	}
//	// nu mai includem aributul static - daca l-am initializat in afara clasei
//
//	Sejur(const Sejur& sej) : idSejur(sej.idSejur) {
//		this->nrPers = sej.nrPers;
//		this->destinatie = new char[strlen(sej.destinatie) + 1];
//		strcpy(this->destinatie, sej.destinatie);
//		this->dataInceput = sej.dataInceput;
//		this->tipMasa = sej.tipMasa;
//		this->pretMese = new float[sej.tipMasa];
//		for (int i = 0; i < sej.tipMasa; i++) {
//			this->pretMese[i] = sej.pretMese[i];
//		}
//		this->cuInsotitor = sej.cuInsotitor;
//		this->camera = sej.camera;
//	}
//
//	~Sejur() {
//		if (destinatie != nullptr) {
//			delete[] destinatie;
//			destinatie = nullptr;
//		}
//		if (pretMese != nullptr) {
//			delete[] pretMese;
//			pretMese = nullptr;
//		}
//	}
//
//	Sejur& operator=(const Sejur& sej) {
//		if (this != &sej) { // Verificare auto-atribuire
//			delete[] pretMese;
//			delete[] destinatie;
//
//			this->nrPers = sej.nrPers;
//			this->destinatie = new char[strlen(sej.destinatie) + 1];
//			strcpy(this->destinatie, sej.destinatie);
//			this->dataInceput = sej.dataInceput;
//			this->tipMasa = sej.tipMasa;
//			if (tipMasa > 0) {
//				this->pretMese = new float[tipMasa];
//				for (int i = 0; i < tipMasa; i++) {
//					this->pretMese[i] = sej.pretMese[i];
//				}
//			}
//			else {
//				this->pretMese = nullptr;
//			}
//			this->cuInsotitor = sej.cuInsotitor;
//			this->camera = sej.camera;
//		}
//		return *this;
//	}
//
//	// Op afisare
//	friend ostream& operator<<(ostream& out, const Sejur& sej) {
//		out << "Nr pers: " << sej.nrPers << endl;
//		out << "Destinatie: " << sej.destinatie << endl;
//		out << "Data inceput" << sej.dataInceput << endl;
//		out << "Tip masa (1/2/3): " << sej.tipMasa << endl;
//		out << "Pret mese: ";
//		for (int i = 0; i < sej.tipMasa; i++) {
//			out << sej.pretMese[i];
//			if (i < sej.tipMasa - 1) {
//				out << " ";
//			}
//		}
//		out << endl << "Cu insotitor (0/1): " << sej.cuInsotitor << endl;
//		out << "Tip camera: " << sej.camera << endl;
//		return out;
//	}
//
//	// Op scriere
//	friend istream& operator>>(istream& in, Sejur& sej) {
//		if (sej.destinatie != nullptr) {
//			delete[] sej.destinatie;
//			sej.destinatie = nullptr;
//		}
//
//		if (sej.pretMese != nullptr) {
//			delete[] sej.pretMese;
//			sej.pretMese = nullptr;
//		}
//
//		cout << "Nr pers (valoare pozitiva): ";
//		in >> sej.nrPers;
//		while (sej.nrPers <= 0) {
//			cout << "Numarul de persoane trebuie sa fie o valoare pozitiva. Introduceti din nou: ";
//			in >> sej.nrPers;
//		}
//
//		cout << "Destinatie (max 99 carac, nu poate fi gol): ";
//		char buffer[100];
//		in >> ws; // Elimina whitespace si newline
//		in.getline(buffer, 99); // Citire până la newline sau max 99 caractere
//		if (strlen(buffer) == 0) {
//			cerr << "Sir gol. Setam val implicita 'N/A'." << endl;
//			strcpy(buffer, "N/A");
//		}
//		sej.destinatie = new char[strlen(buffer) + 1];
//		strcpy(sej.destinatie, buffer);
//
//		cout << "Data inceput: ";
//		in >> ws;
//		getline(in, sej.dataInceput);
//
//		cout << "Tip masa (1 = Mic Dejun, 2 = Demipensiune, 3 = Pensiune completa): ";
//		in >> sej.tipMasa;
//		while (sej.tipMasa < 1 || sej.tipMasa > 3) {
//			cout << "Tip masa invalid. Introduceti o valoare intre 1 si 3: ";
//			in >> sej.tipMasa;
//		}
//
//		cout << "Preturi mese: " << endl;
//		sej.pretMese = new float[sej.tipMasa];
//		for (int i = 0; i < sej.tipMasa; i++) {
//			cout << "Pret masa " << (i + 1) << ": ";
//			in >> sej.pretMese[i];
//			while (sej.pretMese[i] < 0) {
//				cout << "Neacceptat. Introduceti din nou: ";
//				in >> sej.pretMese[i];
//			}
//		}
//		cout << "Agentie: ";
//		in >> ws;
//		getline(in, sej.Agentie);
//
//		cout << "Cu insotitor (1 = Da, 0 = Nu): ";
//		int temp;
//		in >> temp;
//		while (temp != 0 && temp != 1) {
//			cout << "Valoare invalida. Introduceti 1 (Da) sau 0 (Nu): ";
//			in >> temp;
//		}
//		sej.cuInsotitor = (temp == 1);
//
//		cout << "Tip camera (1 = Single, 2 = Double, 3 = Deluxe): ";
//		int conversie;
//		in >> conversie;
//		while (conversie < 1 || conversie > 3) {
//			cout << "Tip de camera invalid. Introduceti o valoare intre 1 si 3: ";
//			in >> conversie;
//		}
//		sej.camera = static_cast<TipCamera>(conversie);
//
//		return in;
//	}
//
//	
//	int getnrPers() {
//		return nrPers;
//	}
//
//	void setnrPers(int nrPers) {
//		if (nrPers > 0) {
//			this->nrPers = nrPers;
//		}
//		else {
//			this->nrPers = 2;
//		}
//	}
//
//	char* getdestinatie() {
//		return destinatie;
//	}
//
//	void setdestinatie(const char* destinatie) {
//		if (destinatie != nullptr) {
//			delete[] this->destinatie;
//			this->destinatie = new char[strlen(destinatie) + 1];
//			strcpy(this->destinatie, destinatie);
//		}
//		else {
//			delete[] this->destinatie;
//			this->destinatie = new char[strlen("default") + 1];
//			strcpy(this->destinatie, "default");
//		}
//	}
//
//	string getdataInceput() {
//		return dataInceput;
//	}
//
//	void setdataInceput(string dataInceput) {
//		if (!dataInceput.empty()) {
//			this->dataInceput = dataInceput;
//		}
//		else {
//			this->dataInceput = "Jan 2025";
//		}
//	}
//
//	int getTipMasa() {
//		return tipMasa;
//	}
//
//	void setpretMese(int tipMasa, float* pretMese) {
//		delete[] this->pretMese; // destructor vector
//		if (tipMasa > 0 && pretMese != nullptr) {
//			this->tipMasa = tipMasa; // copiem constructor cu param
//			this->pretMese = new float[tipMasa]; // copiem constructor cu param
//			for (int i = 0; i < tipMasa; i++) {
//				this->pretMese[i] = pretMese[i];
//			}
//		}
//		else { // copiem din default partea de vector
//			//this->tipMasa = 0;
//			//this->pretMese = nullptr;
//			this->tipMasa = 2;
//			this->pretMese = new float[tipMasa];
//			for (int i = 0; i < tipMasa; i++) {
//				this->pretMese[i] = 2.5;
//			}
//		}
//	}
//
//	static string getAgentie() {
//		return Agentie;
//	}
//
//	static void setAgentie(string Agentie) {
//		Agentie = Agentie;
//	}
//
//	bool getInsotitor() {
//		return cuInsotitor;
//	}
//
//	void setInsotitor(bool cuInsotitor) {
//		this->cuInsotitor = cuInsotitor;
//	}
//
//	TipCamera getCamera() {
//		return camera;
//	}
//
//	void setCamera(TipCamera camera) {
//		this->camera = camera;
//	}
//
//	Sejur operator+(float val) {
//		Sejur copie = *this; // Creeaza o copie a obiectului curent
//		for (int i = 0; i < this->tipMasa; i++) {
//			copie.pretMese[i] += val;
//		}
//		return copie;
//	}
//
//	float& operator[](int index) {
//		if (index >= 0 && index < tipMasa) {
//			return pretMese[index];
//		}
//		else {
//			throw exception(); // Arunca o exceptie pentru index invalid
//		}
//	}
//		
//};
//
//string Sejur::Agentie = "Cristian Tour";
//
//
//class SejurLux : public Sejur {
//public:
//	string tipTransport;
//
//	SejurLux() : Sejur() {
//		this->tipTransport = "Masina";
//	}
//
//	SejurLux(int nrPers, const int idSejur, const char* destinatie, string dataInceput, int tipMasa, float* pretMese, bool cuInsotitor, 
//		TipCamera camera, string tipTransport) : Sejur(nrPers, idSejur, destinatie, dataInceput, tipMasa, pretMese, cuInsotitor, camera) { 
//		this->tipTransport = tipTransport;
//	}
//
//
//	SejurLux(const SejurLux& lux) : Sejur(lux) {
//		this->tipTransport = lux.tipTransport;
//	}
//
//	SejurLux& operator=(const SejurLux& lux) {
//		if (this != &lux) {
//			Sejur :: operator=(lux);
//			this->tipTransport;
//		}
//		return *this;
//	}
//
//	friend ostream& operator<<(ostream& out, const SejurLux& lux) {
//		out << (Sejur&)lux;
//		out << "Tip Transport " << lux.tipTransport << endl;
//		return out;
//
//	}
//
//
//
//};
//
//class AgentieTurism {
//private:
//	vector<Sejur> sejururi;
//
//public:
//	void adaugaSejur(const Sejur& sej) {
//		sejururi.push_back(sej);
//		cout << endl << "Sejur adaugat: " << endl << sej << endl;
//	}
//
//	void afiseazaSejururi() const {
//		if (sejururi.empty()) {
//			cout << "Nu exista sejururi." << endl;
//		}
//		else {
//			cout << endl << "Total sejururi: " << endl;
//			for (size_t i = 0; i < sejururi.size(); i++) {
//				cout << "Sejur. " << i + 1 << endl << sejururi[i] << endl;
//			}
//		}
//	}
//};
//
//
//int main() {
//
//	Sejur sej1;
//
//	cout << "Constructor param" << endl;
//	Sejur sej2(1, 1, "Bahamas", "Iul 2025", 1, new float [1] {27.8}, false, Single);
//	cout << sej2 << endl;
//
//	cout << "Constructor copiere" << endl;
//	Sejur sej3(sej1);
//	cout << sej3 << endl;
//
//	cout << "Op=" << endl;
//	sej3 = sej2;
//	cout << sej3 << endl;
//
//	cout << "Get tip masa" << endl;
//	cout << sej3.getTipMasa() << endl;
//
//	cout << "Set tip masa" << endl;
//	sej3.setpretMese(3, new float [3] {34.5, 35.8, 72.4});
//	cout << sej3 << endl;
//
//	cout << "Get Destinatie sej3: ";
//	cout << sej3.getdestinatie() << endl;
//
//	cout << "Set Destinatie: " ;
//	sej3.setdestinatie("Porto Rico");
//	cout << sej3.getdestinatie() << endl;
//
//	cout << endl << "Dupa operator+: " << endl;
//	Sejur sej4 = sej1 + 10.0f;
//	cout << sej4 << endl;
//
//	cout << endl << "Operator[] fara eroare: ";
//	try {
//			cout<<sej4[2]<<endl;
//			}
//	catch (exception e) {
//			cout << endl << e.what();
//			}
//
//	cout << "Operator[] cu eroare: ";
//	try {
//			cout << sej3[5] << endl;
//			}
//	catch (exception e) {
//			cout << e.what() << endl;
//		}
//
//	cout << endl << "Introduceti datele pentru sejur:" << endl;
//
//	//cin >> sej4;
//	//cout << endl << "Afisati datele pentru sejur:" << endl;
//	//cout << sej4 << endl;
//
//	AgentieTurism agentie;
//	agentie.adaugaSejur(sej1);
//	agentie.adaugaSejur(sej2);
//	agentie.afiseazaSejururi();
//
//	SejurLux lux1;
//	cout << lux1 << endl;
//
//	return 0;
//}