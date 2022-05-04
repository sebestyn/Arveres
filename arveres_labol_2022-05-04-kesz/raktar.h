#ifndef RAKTAR_H_INCLUDED
#define RAKTAR_H_INCLUDED

#include <iomanip>
#include <math.h>
#include <algorithm>
#include <unistd.h>

/// Saj�t f�jlok
#include "karakter.h"
//#include "random_gen.h"

#ifndef CPORTA
    #include "memtrace.h"
#endif // CPORTA

/// Using namespaces
using std::cout;
using std::endl;
using std::random_shuffle;
using std::setw;

/**
Rakt�rakat le�r� oszt�ly
 - itt gener�l�dik le (random) a karakterek
 - kisz�molja a rakt�r �ssz �rt�k�t
**/

class Raktar{
    private:
        Karakter* karakterek;
        int kar_szama = 0;
        int ossz_ertek = 0;
        static int MIN_KARAKTAREK_SZAMA;
        static int MAX_KARAKTAREK_SZAMA;
    public:
        /// Konstruktor
        Raktar(Karakter* el_kar, int el_kar_szama);

        /// Destruktor
        virtual ~Raktar(){delete[] karakterek;}

        /// GET parameters
        int get_kar_szam()             const {return this->kar_szama;}
        Karakter* get_karakterek()     const {return this->karakterek;}
        int get_ossz_ertek()           const {return this->ossz_ertek;}
        int get_MIN_KARAKTAREK_SZAMA() const {return this->MIN_KARAKTAREK_SZAMA;}
        int get_MAX_KARAKTAREK_SZAMA() const {return this->MAX_KARAKTAREK_SZAMA;}

        /// Ki�r�sa
        void print();
};

#endif // RAKTAR_H_INCLUDED
