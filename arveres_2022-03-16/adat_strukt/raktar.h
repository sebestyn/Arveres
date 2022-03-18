#ifndef RAKTAR_H_INCLUDED
#define RAKTAR_H_INCLUDED


/// Saját fájlok
#include "../memtrace.h"
#include "vevo.h"
#include "karakter.h"

/// Using namespaces
using std::cout;
using std::endl;


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
        Raktar() :kar_szama(0), ossz_ertek(0){
            cout << "Raktar Konstruktor() " << endl;
        };


        Raktar(Karakter* el_kar, int el_kar_szama) :kar_szama(0), ossz_ertek(0){
            cout << "Raktar Konstruktor(Karakter*, int) " << endl;

            // Karakterek beállítása
            this->karakterek = new Karakter[3];
            this->kar_szama = 3;

            for(int i=0; i<this->kar_szama; i++){
                this->karakterek[i] = el_kar[i];
                this->ossz_ertek += el_kar[i].get_ertek();
            }

            this->print();
        }


        /// Destruktor -> karakterek dinamikus tömb felszabadítása
        ~Raktar(){
            cout << "Raktar kar szam: " << this->kar_szama << endl;
            cout << "Karakterek cim : " << this->karakterek << endl;

            this->print();

            if(this->kar_szama > 0){
                delete[] this->karakterek;
            }

        }

        /// GET parameters
        int get_kar_szam() const {return this->kar_szama;}
        Karakter* get_karakterek() const {return this->karakterek;}
        int get_ossz_ertek() const {return this->ossz_ertek;}

        /// = operator
        Raktar& operator=(const Raktar& r){
            this->kar_szama = r.get_kar_szam();
            this->ossz_ertek = r.get_ossz_ertek();
            this->karakterek =r.get_karakterek();
            return *this;
        }

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
