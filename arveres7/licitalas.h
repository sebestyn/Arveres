#ifndef LICITALAS_H_INCLUDED
#define LICITALAS_H_INCLUDED

#include <iostream>
#include <unistd.h>

#include "memtrace.h"

/// Saját fájlok
#include "raktar.h"
#include "vevo.h"

/// Using namespaces
using std::cout;
using std::cin;
using std::endl;

/**
Egy raktárért folyó licitálást leíró osztály
 - kérdezgeti az embert és a robotokat, hogy mennyivel emelnek-e és figyeli ki nyer
 - ha nyer az ember , "eladja" a raktárt és megkapja a profitot
**/

class Licitalas{
    private:
        Raktar raktar;
        Ember* ember; // Mindig 1 ember
        Robot robotok[3]; // Mindig 3 robot
        int akt_ar; // Raktár aktuális ára
        static int KEZDO_AR; // Raktár kezdő ára
    public:

        /// Konstruktor
        Licitalas(Ember* ember_pointer, Karakter* elerheto_karakterek, int el_kar_szama);

        /// Destruktor
        ~Licitalas(){}

        /// GET parameters
        Raktar get_raktar() const {return this->raktar;}

        /// Egy raktár licitálás futtatása
        void futtatas();

        /// Kiírások
        void print_vevok();
        void print_akt_ar();
};

#endif // LICITALAS_H_INCLUDED
