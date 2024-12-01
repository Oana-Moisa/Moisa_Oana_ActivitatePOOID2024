#include <iostream>
#include "MyHeader.h"
using namespace std;

int main() {
    int var = 10;
    cout << "Valoarea initiala a lui var: " << var << endl;
    modifica(var);
    cout << "Valoarea lui var dupa modificare: " << var << endl;

    cout << "Rezultatul functiei f(2): " << f(2) << endl;

    int a = 17;
    int* ptr = &a;
    cout << "Adresa lui a: " << ptr << endl;
    cout << "Valoarea lui a prin dereferentiere: " << *ptr << endl;

    float vectorStatic[6] = { 10, 10, 10, 10, 10, 10 };
    vectorStatic[3] = 13.9;
    for (int i = 0; i < 6; i++) {
        cout << vectorStatic[i] << " ";
    }
    cout << endl;

    int dim = 6;
    float* vectorDinamic = new float[dim];
    for (int i = 0; i < dim; i++) {
        vectorDinamic[i] = vectorStatic[i];
    }
    for (int i = 0; i < dim; i++) {
        cout << vectorDinamic[i] << " ";
    }
    cout << endl;

    delete[] vectorDinamic;
    dim = 5;
    vectorDinamic = new float[dim];
    for (int i = 0; i < dim; i++) {
        vectorDinamic[i] = 2.5;
    }
    for (int i = 0; i < dim; i++) {
        cout << vectorDinamic[i] << " ";
    }
    cout << endl;

    delete[] vectorDinamic;

    return 0;
}
