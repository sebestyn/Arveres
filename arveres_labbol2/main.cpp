﻿//#define TEST_MODE

// Saját fájlok
#include "test.cpp"

#include "memtrace.h"

/// Using namespaces
using std::cout;
using std::cin;
using std::endl;

/// STATIKUS VÁLTOZÓK
int   Raktar    ::MAX_KARAKTAREK_SZAMA = 8;
int   Raktar    ::MIN_KARAKTAREK_SZAMA = 2;
int   Ember     ::KEZDO_PENZ           = 25000;
int   Licitalas ::KEZDO_AR             = 100;
char* Jatek     ::KARAKTER_FAJL_NEV    = (char*)"karaker.dat";
char* Jatek     ::JATEKOS_FAJL_NEV     = (char*)"jatekos.dat";
int   Jatek     ::NYERO_EGYENLEG       = 100000;


int main() {

    GTINIT(std::cin);       // Csak C(J)PORTA működéséhez kell

    // Random generátor seed véletlet(idő) beállítása
    srand(time(0));

    #ifdef TEST_MODE

    tesztek::random();
    tesztek::karakter();
    tesztek::raktar();
    tesztek::vevo();
    tesztek::licitalas();
    tesztek::jatek();

    #else

    cout << "Nem teszt" << endl;

    /// Fő játék változó
    Jatek Fojatek(new Ember);

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

    #endif // TEST_MODE

    GTEND(std::cerr);       // Csak C(J)PORTA működéséhez kell
    return 0;
}
