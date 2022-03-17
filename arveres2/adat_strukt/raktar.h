#ifndef RAKTAR_H_INCLUDED
#define RAKTAR_H_INCLUDED

/// Saját fájlok
#include "../memtrace.h"
#include "vevo.h"
#include "karakter.h"

/// Using namespaces
using std::cout;
using std::endl;
using std::random_shuffle;


/**
Raktárakat leíró osztály
 - itt lesznek eltárolva egyszerre több karakter
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
        Raktar(){};
        Raktar(Karakter* el_kar, int el_kar_szama){

            // Véletlen karakterek száma generálás
            int max_es_elerheto_kar_szama = (el_kar_szama < MAX_KARAKTAREK_SZAMA) ? el_kar_szama : MAX_KARAKTAREK_SZAMA;
            int vel_kar_szama = rand() % (max_es_elerheto_kar_szama-MIN_KARAKTAREK_SZAMA+1) + MIN_KARAKTAREK_SZAMA;

            // Elérhető karakterek keverése
            random_shuffle(&el_kar[0], &el_kar[el_kar_szama]);

            // Karakterek beállítása
            this->karakterek = new Karakter[vel_kar_szama];
            this->kar_szama = vel_kar_szama;

            for(int i=0; i<this->kar_szama; i++){
                this->karakterek[i] = el_kar[i];
                this->ossz_ertek += el_kar[i].get_ertek();
            }

        }

        /// Karakterek tömb felszabadítása
        void karakterek_felszabaditasa(){
            delete[] this->karakterek;
        }

        /// GET parameters
        int get_kar_szam() const {return this->kar_szama;}
        Karakter* get_karakterek() const {return this->karakterek;}
        int get_ossz_ertek() const {return this->ossz_ertek;}


        /// Kiírása
        void print(){
            cout << "Raktar: " << endl;
            cout << "--------------------------" << endl;
            for(int i=0; i<this->kar_szama; i++){
                cout << " | " << this->karakterek[i].get_k();
            }
            cout << " | " << endl << "--------------------------" << endl;
            cout << "Ossz ertek: " << this->ossz_ertek << endl << endl;
        }

};


#endif // RAKTAR_H_INCLUDED
