#ifndef FAJLOK_KEZELESE_H_INCLUDED
#define FAJLOK_KEZELESE_H_INCLUDED

#include "adat_strukt/jatek.h"
#include "adat_strukt/karakter.h"
#include "adat_strukt/vevo.h"

/// Fajlok namespace --> összes fajlokkal kapcsolatos változók és függvények
namespace fajlok{

    /// Fájlok nevei
    const char* KARAKTER_FAJL_NEV = "adatok/karaker.txt";
    const char* JATEKOS_FAJL_NEV = "adatok/jatekos.txt";

    /// Beolvasás
    // Összes fájl beolvasása egyszerre, elmentése
    void beolvas(Jatek* jatek);
    // Karakter fájl beolvasása, elmentése
    void karakter_beolvas(Jatek* jatek);
    // Játékos adatai fájl beolvasása, elmentése
    void jatekos_beolvas(Jatek* jatek);

    /// Kiírás
    // Összes fájl kiírása egyszerre, elmentése
    void kiir(Jatek* jatek);
    // Játékos adatai fájl kiírása
    void jatekos_kiiras(Jatek* jatek);

}



#endif // FAJLOK_KEZELESE_H_INCLUDED
