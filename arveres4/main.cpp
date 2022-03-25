/// Defines
//#define TEST_MODE

/// Includes
#include <iostream>
#include <string>
#include <cmath>
#include <conio.h> // PressAKeyToContinue függvényhez
#include <algorithm>
#include <time.h> // Random szám generálás (srand)
#include <unistd.h> // sleep()
#include "memtrace.h"


/// Saját fájlok
#include "console.h"
#include "console.cpp"
#include "random.h"
#include "adat_strukt/karakter.h"
#include "adat_strukt/karakter.cpp"
#include "adat_strukt/jatek.h"
#include "adat_strukt/jatek.cpp"
#include "adat_strukt/licitalas.h"
#include "adat_strukt/licitalas.cpp"
#include "adat_strukt/raktar.h"
#include "adat_strukt/raktar.cpp"
#include "adat_strukt/vevo.h"
#include "adat_strukt/vevo.cpp"
#include "_test_.cpp"


/// Using namespaces
using std::cout;
using std::cin;
using std::endl;


/// STATIKUS VÁLTOZÓK
char* Jatek     ::KARAKTER_FAJL_NEV    = (char*)"data/karaker.dat";
char* Jatek     ::JATEKOS_FAJL_NEV     = (char*)"data/jatekos.dat";
int   Jatek     ::NYERO_EGYENLEG       = 100000;
int   Ember     ::KEZDO_PENZ           = 25000;
int   Robot     ::MAX_EMELES_LICITNEL  = 100;
int   Licitalas ::KEZDO_AR             = 100;
int   Raktar    ::MAX_KARAKTAREK_SZAMA = 8;
int   Raktar    ::MIN_KARAKTAREK_SZAMA = 2;


/// MAIN
int main(){

#ifdef TEST_MODE
    cout << "==== TEST MODE ====" << endl << endl;
    char bemenet = '0';
    while(bemenet != 'q'){
        cout << endl;
        cout << "1 -> fajlok" << endl;
        cout << "2 -> Raktar" << endl;
        cout << "q -> kilepes" << endl;
        cout << endl << "Valassz tesztet: ";
        cin >> bemenet;

        switch(bemenet){
            case '1':
                test::fajlok();
                break;
            case '2':
                test::raktar();
                break;

        }
    }

#else

    // Random generátor seed véletlet(idő) beállítása
    srand(time(0));

    /// Fő játék változó
    Jatek Fojatek;

    /// Előkészítés -> fájlok beolvasasa (hiba esetén kilép)
    try{
        Fojatek.beolvas_fajlokbol();
    } catch(int){
        cerr << "ERROR: Olyan hiba tortent ami miatt a program nem tud tovabb futni." << endl;
        return -1;
    }

    /// Menü futtatasa  (hiba esetén kilép)
    try{
        Fojatek.fomenu_inditas();
    } catch(int){
        cerr << "ERROR: Olyan hiba tortent ami miatt a program nem tud tovabb futni." << endl;
        return -1;
    }

    /// Fájlokba kiírás (hiba esetén kilép)
    cout << " Fajlok mentese: ";
    try{
        Fojatek.kiiras_fajlba();
        cout << "SIKERES" << endl;
    } catch(int){
        cout << "SIKERTELEN" << endl;
    }

    return 0;

#endif // TEST_MODE
}



