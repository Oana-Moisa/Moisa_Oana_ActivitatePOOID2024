#include "MyHeader.h"
#include <iostream>
using namespace std;

void modifica(int& x) {
    x = 20;
}

int functie(int a, int b) {
    return a + b;
}

int f(int x) {
    return 2 * x + 3;
}

void afisare(string mesaj) {
    cout << mesaj << endl;
}