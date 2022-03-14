#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "adat_strukt/jatek.h"

/// Using namespaces
using std::cout;
using std::endl;

namespace menu{
    /// Menü futtatása
    void run(Jatek* jatek);

    /// Bemenetek függvények
    // p -> Játék adatainak kiírása
    void p(Jatek* jatek);
}


#endif // MENU_H_INCLUDED
