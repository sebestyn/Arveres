#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "adat_strukt/jatek.h"

/// Using namespaces
using std::cout;
using std::endl;

namespace menu{
    /// Men� futtat�sa
    void run(Jatek* jatek);

    /// Bemenetek f�ggv�nyek
    // p -> J�t�k adatainak ki�r�sa
    void p(Jatek* jatek);
}


#endif // MENU_H_INCLUDED
