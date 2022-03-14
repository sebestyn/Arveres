
#include "fajlok_kezelese.h"


/// Beolvasás
// Összes fájl beolvasása egyszerre, elmentése
void fajlok::beolvas(Jatek* jatek){
    try{
        karakter_beolvas(jatek);
        jatekos_beolvas(jatek);
    } catch(int a){
        cerr << "ERROR: Nem sikerult az osszes fajlt beolvasni. Ellenorizd a megfelelnek-e a felteteleknek!" << endl;
        throw 400;
    }
}
// Karakter fájl beolvasása, elmentése
void fajlok::karakter_beolvas(Jatek* jatek){

    // Fájl megnyitása
    ifstream fajl(KARAKTER_FAJL_NEV);
    if (!fajl.is_open()) throw 400; //Nem sikerült megnyitni

    // Első sor -> összsen hány sor lesz?
    int hany_sor;
    fajl >> hany_sor;
    if(hany_sor<=0)throw 400; //Nem helyes sorok száma (0<)

    // Dinamikus karakterek tömb létrehozása
    Karakter* temp_karakterek = new Karakter[hany_sor];

    // Sorok beovasása
    for(int i=0; i<hany_sor; i++) {
        char k;
        int ertek, gyakorisag;
        fajl >> k;
        fajl >> ertek;
        fajl >> gyakorisag;
        temp_karakterek[i].set_all(k, ertek, gyakorisag);
    }

    // Játék obj -> karakterek tömb elmentése
    jatek->set_karakterek(temp_karakterek, hany_sor);

    // Fájl bezárása
    fajl.close();
}
// Játékos adatai fájl beolvasása, elmentése
void fajlok::jatekos_beolvas(Jatek* jatek){

    // Fájl megnyitása
    ifstream fajl(JATEKOS_FAJL_NEV);
    if (!fajl.is_open()) throw 400; //Nem sikerült megnyitni

    // 1. sor -> Hanyadik raktár beolvasás, mentés játékba
    int temp_h_raktar;
    fajl >> temp_h_raktar;
    jatek->set_hanyadik_raktar(temp_h_raktar);

    // 2. sor -> Ember pénze
    int penz;
    fajl >> penz;
    // 3. sor -> Megvett raktárak száma
    int megvett_r_szama;
    fajl >> megvett_r_szama;

    // Ember mentése a játékba
    Ember temp_ember(penz, megvett_r_szama);
    jatek->set_ember(temp_ember);

    // Fájl bezárása
    fajl.close();
}

/// Kiírás
// Összes fájl kiírása egyszerre, elmentése
void fajlok::kiir(Jatek* jatek){
    try{
        jatekos_kiiras(jatek);
    } catch(int a){
        cerr << "ERROR: Hiba a fájl kiírásnál. Lehet nem sikerült elmenteni az adatokat." << endl;
        throw 400;
    }
}
// Játékos adatai fájl kiírása
void fajlok::jatekos_kiiras(Jatek* jatek){

    // Fájl megnyitása
    ofstream fajl(JATEKOS_FAJL_NEV);
    if (!fajl.is_open()) throw 400; //Nem sikerült megnyitni

    // 1. sor -> Hanyadik raktár
    fajl << jatek->get_hanyadik_raktar() << endl;
    // 2. sor -> Ember pénze
    fajl << jatek->get_ember().get_penz() << endl;
    // 3. sor -> Megvett raktárak száma
    fajl << jatek->get_ember().get_megvett_raktarak_szama();

    // Fájl bezárása
    fajl.close();
}

