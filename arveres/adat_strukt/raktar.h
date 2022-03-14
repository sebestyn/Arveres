#ifndef RAKTAR_H_INCLUDED
#define RAKTAR_H_INCLUDED

/**
Raktárakat leíró osztály
 - itt lesznek eltárolva egyszerre több karakter
**/

class Raktar{
    private:
        bool szabad_e;
        Vevo *megvette_vevo;
        Karakter karakterek[10]; // Maximum 10 karakter fér egy raktárba !!
        int ossz_ertek; // ez kell vagy elég mindig a kerakterekből kiszámolni?
};


#endif // RAKTAR_H_INCLUDED
