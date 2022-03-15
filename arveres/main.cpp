/// Defines
//#define TEST_MODE

/// Includes
#include <iostream>
#include "memtrace.h"

/// Saját fájlok
#include "adat_strukt/karakter.h"
#include "adat_strukt/karakter.cpp"
#include "adat_strukt/jatek.h"
#include "adat_strukt/jatek.cpp"
#include "adat_strukt/vevo.h"
#include "adat_strukt/vevo.cpp"


/// Using namespaces
using std::cout;
using std::cin;
using std::endl;

/// Fontos infók
/*
 - 3 robot, 1 ember
 - Nyer: elér 10 000Ft-ot, Veszít: 0 Ft alá megy
*/

/// GLOBÁLIS VÁLTOZÓK


/// STATIKUS VÁLTOZÓK
char* Jatek::KARAKTER_FAJL_NEV = (char*)"adatok/karaker.dat";
char* Jatek::JATEKOS_FAJL_NEV  = (char*)"adatok/jatekos.dat";
int Ember::KEZDO_PENZ = 2500;

/// MAIN
int main(){

#ifdef TEST_MODE

    cout << "------- TEST MODE ACTIVE -------" << endl << endl;

#else

    /// Fő játék változó
    Jatek Fojatek;


    /// Előkészítés -> fájlok beolvasasa (hiba esetén kilép)
    try{
        Fojatek.beolvas_fajlokbol();
    } catch(int e){
        cerr << "ERROR: Olyan hiba tortent ami miatt a program nem tud tovabb futni." << endl;
        return -1;
    }


    /// Menü futtatasa
    Fojatek.inditas();


    /// Fájlokba kiírás (hiba esetén kilép)
    try{
        cout << "Fajlok mentese... ";
        Fojatek.kiiras_fajlba();
        cout << "SIKERES" << endl;
    } catch(int e){
        cerr << "ERROR: Olyan hiba tortent ami miatt a program nem tud tovabb futni." << endl;
        return -1;
    }


    cout << endl << "====== Sikeres program futtatas tortent! ======" << endl;
    return 0;

#endif // TEST_MODE
}
