#define TEST_MODE

// Saját fájlok
#include "test.cpp"

#include "memtrace.h"
#include "gtest_lite.h"

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

    //int *a = new int[2];
    //std::cout << a[0];

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

    #endif // TEST_MODE

    GTEND(std::cerr);       // Csak C(J)PORTA működéséhez kell
    return 0;
}
