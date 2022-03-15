#ifndef VEVO_H_INCLUDED
#define VEVO_H_INCLUDED

#include "../memtrace.h"

#include "raktar.h"

using namespace std;


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
        int get_id(){
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
        static int KEZDO_PENZ;
    public:

        /// Konstruktor
        Ember(int p = KEZDO_PENZ, int m = 0):penz(p), megvett_raktarak_szama(m){this->set_id(0);}

        /// GET parameters
        int get_penz(){return this->penz;}
        int get_megvett_raktarak_szama(){return this->megvett_raktarak_szama;}

        /// SET parameters
        void megvett_raktarak_szama_plus_1(){
            this->megvett_raktarak_szama += 1;
        }

        /// Licitálás emelés kérdés
        int emelek(){
            cout << "Mennyivel emelek vagy kiszallok(0)?" << endl;
            int emelek_osszeg;
            cin >> emelek_osszeg;
            return emelek_osszeg;
        }

        /// Pénz csökkentése
        void penz_csokkentese(int mennyivel=0){
            this->penz = this->penz-mennyivel;
        }

        /// Kiírás
        void print() {
            cout << "Ember:" << endl <<
                    " - id: "<< this->get_id() << endl <<
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
        int emelek(){ return 0; return this->ALAP_EMELES_LICITNEL; }

        /// Kiírás
        void print(){
            cout << "Robot:" << endl <<
                    " - id: "<< this->get_id() << endl;
        }
};


#endif // VEVO_H_INCLUDED
