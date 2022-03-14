
#include "fajlok_kezelese.h"


void fajlok_beolvasasa(){

    ifstream karakterek_fajl(KARAKTEREK_FAJL_NEV);

    if (!karakterek_fajl.is_open()) throw "Fajl beolvasas sikertelen!";

    // Első sor -> összsen hány sor lesz?
    int hany_sor;
    karakterek_fajl >> hany_sor;
    Karakter karakterek[hany_sor];

    // Sorok beovasása
    for(int i=0; i<hany_sor; i++) {
        karakterek_fajl >> karakterek[i].k;
        karakterek_fajl >> karakterek[i].ertek;
        karakterek_fajl >> karakterek[i].gyakorisag;
        karakterek[i].kiir();
    }

    karakterek_fajl.close();


}
