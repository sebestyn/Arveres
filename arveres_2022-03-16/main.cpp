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
#include "adat_strukt/licitalas.h"
#include "adat_strukt/licitalas.cpp"
#include "adat_strukt/raktar.h"
#include "adat_strukt/raktar.cpp"
#include "console.h"


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
int Robot::ALAP_EMELES_LICITNEL = 200;
int Licitalas::KEZDO_AR = 100;
int Raktar::MAX_KARAKTAREK_SZAMA = 10;
int Raktar::MIN_KARAKTAREK_SZAMA = 3;

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
    try{
        Fojatek.fomenu_inditas();
    } catch(int e){
        cerr << "ERROR: Olyan hiba tortent ami miatt a program nem tud tovabb futni." << endl;
        return -1;
    }


    /// Fájlokba kiírás (hiba esetén kilép)
    try{
        cout << "Fajlok mentese... ";
        Fojatek.kiiras_fajlba();
        cout << "SIKERES" << endl;
    } catch(int e){
        cerr << "ERROR: Olyan hiba tortent ami miatt a program nem tud tovabb futni." << endl;
        return -1;
    }


    // Ha minden sikeresen lefut
    cout << endl << "====== Minden sikeresen lefutott! ======" << endl;
    return 0;

#endif // TEST_MODE
}
