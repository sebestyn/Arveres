#ifndef VEVO_H_INCLUDED
#define VEVO_H_INCLUDED

#include <iostream>
#include <unistd.h>

//#include "memtrace.h"

/// Saját fájlok
#include "console.h"
#include "random.h"

/// Using namespaces
using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
Vevők leíró osztály
 - lehet robot vagy ember
 - mindkettotol meg lehet majd kérdezni hogy mennyivel szeretne emelni
 - az embernel szamon van tartva mennyi penze van
**/

class Vevo{
    private:
        int id;
    public:
        /// Konstruktor
        Vevo(int i = 0):id(i){}

        /// Get parameters
        int get_id() const {
            return this->id;
        }

        /// Set parameters
        void set_id(int id=0){
            this->id = id;
        }

        /// Kiírás
        virtual void print() const {}
 };

class Ember : public Vevo {
    private:
        int penz;
        int megvett_raktarak_szama;
        string nev;
        static int KEZDO_PENZ;
    public:
        /// Konstruktor
        Ember(int p = KEZDO_PENZ, int m = 0, string n=""):penz(p), megvett_raktarak_szama(m), nev(n){this->set_id(0);}

        /// GET parameters
        string get_nev() const { return this->nev;}
        int get_penz()   const { return this->penz;}
        int get_megvett_raktarak_szama() const { return this->megvett_raktarak_szama;}

        /// SET parameters
        void set_all(int p, int m, string n){this->penz = penz; this->megvett_raktarak_szama = m; this->nev=n;}
        void set_nev(string nev){ this->nev = nev; }
        void megvett_raktarak_szama_plus_1(){this->megvett_raktarak_szama += 1;}
        void change_penz(int profit=0){this->penz = this->penz+profit;}
        void reset(){this->penz = this->KEZDO_PENZ; this->megvett_raktarak_szama = 0; this->nev = ""; }

        /// Licitálás emelés kérdés
        int emelsz();

        /// Kiírás
        void print();
};

class Robot : public Vevo {
    private:
        int max_licit = 0;

    public:

        /// Konstruktor
        Robot(int id=1){this->set_id(id);}

        /// SET
        void set_max_licit(int raktar_ertek);

        /// Licitálás emelés kérdés
        int emelsz(int akt_ar);

        /// Kiírás
        void print();
};


#endif // VEVO_H_INCLUDED
