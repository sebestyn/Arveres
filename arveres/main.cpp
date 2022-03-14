#include <iostream>
#include <fstream>

#include "memtrace.h"

#include "adat_strukt/karakter.h"
#include "adat_strukt/jatek.h"

#include "fajlok_kezelese.h"
#include "fajlok_kezelese.cpp"

using namespace std;


/// GLOB�LIS V�LTOZ�K
const int ROBOTOK_DB = 2;
const int JATEK_VEGE_PENZOSSZEG = 10000; // 10000-> nyert   0 -> vesztett

int main()
{
    Jatek Fojatek;

    // F�jlok beolvasasa (hiba eset�n kil�p)
    try{
        fajlok::beolvas(&Fojatek);
    } catch(int e){
        cerr << "ERROR: Olyan hiba tortent ami miatt a program nem tud tovabb futni." << endl;
        return -1;
    }

    Fojatek.print();

    // F�jlok ki�r�sa
    fajlok::kiir(&Fojatek);


    cout << endl << "====== Sikeres program futtatas tortent! ======" << endl;
    return 0;
}
