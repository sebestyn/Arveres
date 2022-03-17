#ifndef VEVO_H_INCLUDED
#define VEVO_H_INCLUDED


/// Saját fájlok
#include "../memtrace.h"
#include "raktar.h"

/// Using namespaces
using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
Vevők leíró osztályy
 - lehet robot vagy ember
**/

 class Vevo{
    private:
        int id;
    public:

        /// Konstruktor
        Vevo(){}

        /// Get parameters
        int get_id() const {
            return this->id;
        }

        /// Set parameters
        void set_id(int id=0){
            this->id = id;
        }

        /// Kiírás
        void print(){}
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
        void set_nev(string nev){
            this->nev = nev;
        }
        void megvett_raktarak_szama_plus_1(){
            this->megvett_raktarak_szama += 1;
        }

        /// Reset -> minden adat alpra állítása
        void reset(){
            this->penz = this->KEZDO_PENZ;
            this->megvett_raktarak_szama = 0;
        }

        /// Licitálás emelés kérdés
        int emelsz(){
            cout << "Mennyivel emelsz? (ha kiszallsz 0-t irj)" << endl;
            int emelek_osszeg = console::int_input(true);
            return emelek_osszeg;
        }

        /// Pénz változtatása
        void change_penz(int profit=0){
            this->penz = this->penz+profit;
        }

        /// Kiírás
        void print() {
            cout << "Ember:" << endl <<
                    " - id: "<< this->get_id() << endl <<
                    " - nev: "<< this->nev << endl <<
                    " - Penz egyenlege: "<< this->penz << endl <<
                    " - Megevett raktarak: "<< this->megvett_raktarak_szama << endl;
        }
};

class Robot : public Vevo {
    private:
        static int ALAP_EMELES_LICITNEL;

    public:

        /// Konstruktor
        Robot(int id=1){this->set_id(id);}

        /// Licitálás emelés kérdés
        int emelek(){ return 0; /*return this->ALAP_EMELES_LICITNEL;*/ }

        /// Kiírás
        void print(){
            cout << "Robot:" << endl <<
                    " - id: "<< this->get_id() << endl;
        }
};


#endif // VEVO_H_INCLUDED
