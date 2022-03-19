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
using std::exp;

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
            cout << " Mennyivel emelsz? (0=kiszallok) ";
            int emelek_osszeg = console::int_input(true);
            cout << endl;
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
        int max_licit = 0;
        static int MAX_EMELES_LICITNEL;

    public:

        /// Konstruktor
        Robot(int id=1){this->set_id(id);}


        /// SET
        void set_max_licit(int raktar_ertek){
            // Túl értékeli -> 20%
            bool tul_ertekeli = random::range(1,100) > 80;
            int csuszas = random::range(1, raktar_ertek);

            if(tul_ertekeli){
                this->max_licit = raktar_ertek+csuszas;
            } else {
                this->max_licit = raktar_ertek-csuszas;
            }
        }

        /// Licitálás emelés kérdés
        int emelsz(int akt_ar){
            // Ha nem lépte túl a max licitet
            if(this->max_licit > akt_ar){
                int mennyivel_emeljek = random::range(1, this->max_licit-akt_ar);
                // 10es kerekítés
                mennyivel_emeljek=(((mennyivel_emeljek+10)/10)*10);
                return mennyivel_emeljek;
            }
            return 0;
        }

        /// Kiírás
        void print(){
            cout << "Robot:" << endl <<
                    " - id: "<< this->get_id() << endl;
        }
};


#endif // VEVO_H_INCLUDED
