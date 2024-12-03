#include "Clase.h"

int main() {
    Ochelari o1;
    Ochelari o2("Progresive", 101, "Metal");
    Ochelari o3 = o2;
    cout << o1 << endl << o2 << endl << o3 << endl;
    Ochelari::AfiseazaNumarOchelari();

    Lentile l1;
    Lentile l2("Hidrogel", 12.5, "Miopie", 202);
    Lentile l3 = l2;
    cout << l1 << endl << l2 << endl << l3 << endl;
    Lentile::AfiseazaNumarLentile();

    Aparat a1;
    Aparat a2("Avansat", "Laser", 303);
    Aparat a3 = a2;
    cout << a1 << endl << a2 << endl << a3 << endl;
    Aparat::AfiseazaNumarAparate();

    return 0;
}
