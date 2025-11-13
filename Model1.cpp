//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//class Laptop {
//private:
//	char* model;
//	string procesor;
//	int garantie;
//	const string serieCarcasa;
//
//public:
//	Laptop() : serieCarcasa("f123") {
//		this->model = new char[strlen("ASUS") + 1];
//		strcpy(this->model, "ASUS");
//		this->procesor = "i7";
//		this->garantie = 12;
//	}
//
//	Laptop(const char* model, string procesor, int garantie, const string serieCarcasa) : serieCarcasa(serieCarcasa) {
//		this->model = new char[strlen(model) + 1];
//		strcpy(this->model, model);
//		this->procesor = procesor;
//		this->garantie = garantie;
//	}
//
//	Laptop(const Laptop& lpt) : serieCarcasa(lpt.serieCarcasa) {
//		this->model = new char[strlen(lpt.model) + 1];
//		strcpy(this->model, lpt.model);
//		this->procesor = lpt.procesor;
//		this->garantie = lpt.garantie;
//	}
//
//	~Laptop() {
//		delete[] model;
//	}
//
//	Laptop& operator=(const Laptop& lpt) {
//		delete[] model;
//		this->model = new char[strlen(lpt.model) + 1];
//		strcpy(this->model, lpt.model);
//		this->procesor = lpt.procesor;
//		this->garantie = lpt.garantie;
//		return *this;
//	}
//
//	int getgarantie() {
//		return garantie;
//	}
//
//	void setgarantie(int garantie) {
//		if (garantie > 0) {
//			this->garantie = garantie;
//		}
//		else {
//			this->garantie = 12;
//		}
//	}
//
//	friend ostream& operator << (ostream& out, const Laptop& lpt) {
//		out << lpt.model << endl;
//		out << lpt.procesor << endl;
//		out << lpt.garantie << endl;
//		out << lpt.serieCarcasa << endl;
//		return out;
//	}
//
//	// Operatori unari
//	// operator++
//	int operator++() {
//		this->garantie++;
//		return garantie;
//	}
//
//	int operator++(int) {
//		Laptop copie = *this; // apel costructor copiere cu garantie inainte de crestere
//		this->garantie++; // garantie dupa crestere 
//		return copie.garantie; // returnez garantia inainte de crestere
//	}
//
//	bool operator! () {
//		if (garantie >= 12)
//			return true;
//		else
//			return false;
//	}
//
//	// ==; !=
//	// Supraincarcare op == ; 2 obiecte sunt egale daca au toate atributele sau 2 dintre ele sunt egale
//	bool operator== (const Laptop& l) {
//		if (strcmp(this->model, l.model) == 0 && this->procesor == l.procesor && this->garantie == l.garantie)
//			return true;
//		else return false;
//	}
//
//	bool operator!= (const Laptop& l) {
//		if (strcmp(this->model, l.model) != 0 && this->procesor != l.procesor && this->garantie != l.garantie)
//			return true;
//		else return false;
//	}
//
//	// < ; > ; <= ; >= de compara dupa un singur atribut
//	bool operator< (const Laptop& l) {
//		if (this->garantie < l.garantie)
//			return true;
//		else false;
//	}
//
//	// cazuri exceptate op[]; op ()(); op cast; op~ 
//	char& operator[] (int index) {
//		if (index >= 0 && index < strlen(this->model)) {
//			return this->model[index];
//		}
//		else throw exception();
//	}
//
//};
//
//
//void main() {
//	Laptop l1;
//	cout << "Default: " << l1 << endl;
//
//	Laptop l2("DELL", "i5", 0, "f1234");
//	cout << "Parametrii: " << l2 << endl;
//
//	Laptop l3(l1);
//	cout << "Copiere: " << l3 << endl;
//
//	l3 = l2;
//	cout << "Egal: " << l3 << endl;
//
//	cout << "Getter: " << l1.getgarantie() << endl;
//
//	l1.setgarantie(20);
//	cout << "Setter dupa modificare: " << l1.getgarantie() << endl;
//
//	/*int x = 10;
//	cout << ++x << endl;
//	cout << x << endl;*/
//
//	cout << l1 << endl;
//
//	cout << ++l1 << endl;
//
//	cout << l1++ << endl;
//	cout << l1 << endl;
//
//	if (!l2) {
//		cout << "Garantie ok" << endl;
//	}
//	else
//		cout << "Garantie invalida" << endl;
//
//	if (l1 != l1) {
//		cout << "Sunt diferite" << endl;
//	}
//	else {
//		cout << "Sunt la fel" << endl;
//
//	}
//
//	if (l1 < l2) {
//		cout << "Garantie mai mica" << endl;
//	}
//	else cout << "Garantie mai mare" << endl;
//
//	try {
//		cout<<l1[9]<<endl;
//	}
//	catch (exception e) {
//		cout << e.what();
//	}
//}
//
//
