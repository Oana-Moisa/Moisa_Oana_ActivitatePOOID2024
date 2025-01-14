#include "Clase.h"

int main() {
    Ochelari o1;
    Ochelari o2("Progresive", 101, "Metal");
    Ochelari o3 = o2;

    cout << o1 << endl << o2 << endl << o3 << endl;
    procesareOchelari(o1);
    cout << "Dupa procesare: " << o1 << endl;

    Ochelari o4;
    o4 = o2;
    cout << "Operator =: " << o4 << endl;

    Ochelari o5 = o1 + o2;
    cout << "Operator +: " << o5 << endl;

    if (o2 == o3) {
        cout << "Egal" << endl;
    }
    else {
        cout << "Diferit" << endl;
    }

    ++o1;
    cout << "Operator ++: " << o1 << endl;

    schimbaMaterial(o1, "Titan");
    cout << "Noul material este: " << o1 << endl;

    Ochelari::AfiseazaNumarOchelari();

    Lentile l1;
    Lentile l2("Sticla", 12.5, "Miopie", 202);
    Lentile l3 = l2;

    cout << l1 << endl << l2 << endl << l3 << endl;
    procesareLentile(l1);
    cout << "Dupa procesare: " << l1 << endl;

    Lentile l4;
    l4 = l2;
    cout << "Operator =: " << l4 << endl;

    Lentile l5 = l2 - 1.0f;
    cout << "Operator -: " << l5 << endl;

    if (l1 != l2) {
        cout << "Diferite" << endl;
    }
    else {
        cout << "Egale" << endl;
    }

    --l2;
    cout << "Operator --: " << l2 << endl;

    float pret = calculPret(l2);
    cout << "Noul pret al lentilelor este " << pret << " lei" << endl;

    Lentile::AfiseazaNumarLentile();

    Aparat a1;
    Aparat a2("Avansat", "Laser", 303, "Albastru", 1080.0f);
    Aparat a3 = a2;

    cout << a1 << endl << a2 << endl << a3 << endl;
    procesareAparat(a1);
    cout << "Dupa procesare: " << a1 << endl;

    Aparat a4;
    a4 = a2;
    cout << "Operator =: " << a4 << endl;

    Aparat a5 = a1 + a2;
    cout << "Operator +: " << a5 << endl;

    if (a2 == a3) {
        cout << "Egal" << endl;
    }
    else {
        cout << "Diferit" << endl;
    }

    ++a2;
    cout << "Operator ++: " << a2 << endl;

    Aparat a6 = !a2;
    cout << "Operator !: " << a6 << endl;

    actualizeazaRezolutie(a1, 5.0f);
    schimbaFiltru(a1, "Rosu");
    cout << "Noul filtru este: " << a1 << endl;

    Aparat::AfiseazaNumarAparate();

    return 0;
}
