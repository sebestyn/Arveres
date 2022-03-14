#include <iostream>
#include <fstream>
#include "memtrace.h"

/// Saját fájlok
#include "adat_strukt/karakter.h"
#include "adat_strukt/jatek.h"
#include "fajlok_kezelese.h"
#include "fajlok_kezelese.cpp"
#include "menu.h"
#include "menu.cpp"

/// Using namespaces
using std::cout;
using std::endl;

/// Defines
//#define TEST_MODE

/// Fontos infók
/*
 - 3 robot, 1 ember
 - Nyer: elér 10 000Ft-ot, Veszít: 0 Ft alá megy
*/

/// GLOBÁLIS VÁLTOZÓK


/// MAIN
int main(){

#ifdef TEST_MODE

    cout << "-------" TEST MODE ACTIVE -------" << endl << endl;

#else


    /// Fő játék változó
    Jatek Fojatek;

    /// Fájlok beolvasasa (hiba esetén kilép)
    try{
        fajlok::beolvas(&Fojatek);
    } catch(int e){
        cerr << "ERROR: Olyan hiba tortent ami miatt a program nem tud tovabb futni." << endl;
        return -1;
    }

    /// Menü futtatasa
    menu::run(&Fojatek);

    /// Fájlok kiírása (adatok mentése)
    fajlok::kiir(&Fojatek);


    cout << endl << "====== Sikeres program futtatas tortent! ======" << endl;
    return 0;

#endif // TEST_MODE
}
