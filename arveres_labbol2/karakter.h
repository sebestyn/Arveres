#ifndef KARAKTER_H_INCLUDED
#define KARAKTER_H_INCLUDED

#include <iostream>

#include "memtrace.h"

/// Using namespaces
using std::cout;
using std::endl;

/**
Karaktereket leíró osztály
 - van értéke és gyakorisága
**/

class Karakter{
    private:
        char k; // pl.: @
        int ertek; // a karakter értéke -> min 1 Ft
        int gyakorisag; // 1-100%
    public:
        /// Konstruktor
        Karakter(char k='-', int ertek=10, int gyakorisag=100) :k(k), ertek(ertek), gyakorisag(gyakorisag){}

        /// GET parameters
        char get_k()         const {return this->k;}
        int get_ertek()      const {return this->ertek;}
        int get_gyakorisag() const {return this->gyakorisag;}

        /// SET parameters
        void set_all(char k='-', int ertek=10, int gyakorisag=100){
            this->k = k;
            this->ertek = ertek;
            this->gyakorisag = gyakorisag;
        }

        /// Kiírás
        void print(){
            cout << " - " << k << ": " << ertek << "Ft (" << gyakorisag << "%)" << endl;
        }
};

std::ostream& operator<<(std::ostream& os, const Karakter& k){
    return os << " - " << k.get_k() << ": " << k.get_ertek() << "Ft (" << k.get_gyakorisag() << "%)" << endl;
}

#endif // KARAKTER_H_INCLUDED
