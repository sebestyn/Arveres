#ifndef RAKTAR_H_INCLUDED
#define RAKTAR_H_INCLUDED

#include "vevo.h"
#include "karakter.h"

/**
Raktárakat leíró osztály
 - itt lesznek eltárolva egyszerre több karakter
**/

class Raktar{
    private:
        Karakter karakterek[10]; // Maximum 10 karakter fér egy raktárba !!
        int ossz_ertek;
};


#endif // RAKTAR_H_INCLUDED
