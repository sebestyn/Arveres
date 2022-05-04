#ifndef LICITALAS_H_INCLUDED
#define LICITALAS_H_INCLUDED

#include <iostream>
#include <unistd.h>

/// Saj�t f�jlok
#include "raktar.h"
#include "vevo.h"

#ifndef CPORTA
    #include "memtrace.h"
#endif // CPORTA

/// Using namespaces
using std::cout;
using std::cin;
using std::endl;

/**
Egy rakt�r�rt foly� licit�l�st le�r� oszt�ly
 - k�rdezgeti az embert �s a robotokat, hogy mennyivel emelnek-e �s figyeli ki nyer
 - ha nyer az ember , "eladja" a rakt�rt �s megkapja a profitot
**/

class Licitalas{
    private:
        Raktar* raktar;
        Ember* ember; // Mindig 1 ember lesz
        Robot* robotok; // Mindig 3 robot lesz
        int akt_ar;
        static int KEZDO_AR;
    public:

        /// Konstruktor
        Licitalas(Raktar* r, Ember* e, Robot* ro_ok);

        /// Destruktor
        virtual ~Licitalas(){
            delete this->raktar;
            delete[] this->robotok;
        }

        /// GET parameters
        int get_akt_ar()     const {return this->akt_ar;}
        Raktar* get_raktar() const {return this->raktar;}

        /// Egy rakt�r licit�l�s futtat�sa
        void futtatas();

        /// Ki�r�sok
        void print_vevok();
        void print_akt_ar();
};

#endif // LICITALAS_H_INCLUDED
