#include <iostream> // Pentru input si output standard (`cin`, `cout`, `cerr`, `clog`)
#include <fstream>  // Pentru lucrul cu fisiere
using namespace std; // Permite utilizarea simbolurilor din namespace-ul std fara prefixul `std::`

// Functie pentru a modifica o variabila transmisa prin referinta
void modifica(int& x) {
    x = 20;
}

int main() {
    // Pointeri
    int* ptr = nullptr; // Initializarea pointerului cu nullptr

    // Obtinerea adresei unei variabile
    int var = 10;
    ptr = &var; // ptr stocheaza adresa lui var

    // Crearea unei referinte (alias pentru o variabila)
    int& ref = var; // ref este o referinta la var
    ref = 20;       // Modifica valoarea lui var

    // Transmiterea parametrilor prin referinta
    cout << "Valoarea lui var inainte de functie: " << var << endl;
    modifica(var); // Modifica var prin referinta
    cout << "Valoarea lui var dupa functie: " << var << endl;

    // Operator "bitwise AND"
    int a = 5;  // 0101 in binar
    int b = 3;  // 0011 in binar
    int c = a & b; // 0001 (1 in zecimal)

    cout << "Rezultatul lui a & b: " << c << endl;

    // Afisarea pointerului
    cout << "Adresa stocata in ptr: " << ptr << endl;    // Adresa variabilei `var`
    cout << "Valoarea de la adresa stocata in ptr: " << *ptr << endl; // Valoarea lui `var` (10 sau modificata)

    return 0;
}