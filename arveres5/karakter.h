#ifndef KARAKTER_H_INCLUDED
#define KARAKTER_H_INCLUDED

/// Saj�t f�jlok
#include <iostream>

/// Using namespaces
using std::cout;
using std::endl;

/**
Karaktereket le�r� oszt�ly
 - van �rt�ke �s gyakoris�ga
**/

class Karakter{
    private:
        char k; // pl.: @
        int ertek; // a karakter �rt�ke -> min 1 Ft
        int gyakorisag; // 0-100%
    public:
        /// Konstruktor
        Karakter(char k=' ', int ertek=1, int gyakorisag=0) :k(k), ertek(ertek), gyakorisag(gyakorisag){}

        /// GET parameters
        char get_k()         const {return this->k;}
        int get_ertek()      const {return this->ertek;}
        int get_gyakorisag() const {return this->gyakorisag;}

        /// SET parameters
        void set_all(char k=' ', int ertek=0, int gyakorisag=0);

        /// Ki�r�s
        void print();
};

#endif // KARAKTER_H_INCLUDED
