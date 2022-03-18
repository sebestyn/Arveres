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

            // Karakterek számának beállítása
            this->kar_szama = random::range(MIN_KARAKTAREK_SZAMA, MAX_KARAKTAREK_SZAMA);

            // Elérhető karakterek keverése
            random_shuffle(&el_kar[0], &el_kar[el_kar_szama]);

            // Karakterek tom lefoglalása
            this->karakterek = new Karakter[this->kar_szama];

            // Karakterek beállítása valószínűség alapján
            int hanyadik = 0;
            while(hanyadik < this->kar_szama){
                int percent = random::range(1,100);
                int i = random::range(0,el_kar_szama-1);
                if(el_kar[i].get_gyakorisag() >= percent){
                    this->karakterek[hanyadik] = el_kar[i];
                    this->ossz_ertek += el_kar[i].get_ertek();
                    hanyadik++;
                }

            }

        }

        /// Karakterek tömb felszabadítása
        void karakterek_felszabaditasa(){
            delete[] this->karakterek;
        }

        /// GET parameters
        int get_kar_szam()             const {return this->kar_szama;}
        Karakter* get_karakterek()     const {return this->karakterek;}
        int get_ossz_ertek()           const {return this->ossz_ertek;}
        int get_MIN_KARAKTAREK_SZAMA() const {return this->MIN_KARAKTAREK_SZAMA;}
        int get_MAX_KARAKTAREK_SZAMA() const {return this->MAX_KARAKTAREK_SZAMA;}


        /// Kiírása
        void print(){

            // Raktar merete (x*x)
            int x = sqrt(this->kar_szama) + 1;
            if(x<3) x = 3;

            // Üres raktár helyek kitötlése ' ' karakterrel
            char karakterek_k[x*x];
            for(int j=0; j<kar_szama; j++){
                karakterek_k[j] = karakterek[j].get_k();
            }
            for(int j=kar_szama; j<(x*x); j++){
                karakterek_k[j] = ' ';
            }
            //std::random_shuffle(&karakterek_k[0], &karakterek_k[x*x]);

            // Kirajzolás
            int i = 0;
            for(int sor = 0; sor<x; sor++){
                cout << setw(18) << " +---+";
                for(int a=0; a<x-1; a++){cout << "---+";}
                cout << endl << setw(12) << "";
                for(int oszlop = 0; oszlop<x;oszlop++){
                    cout << " | " << karakterek_k[i++];
                }
                cout << " |" << endl;
            }

            cout << setw(18) <<  " +---+";
            for(int a=0; a<x-1; a++){cout << "---+";}
            cout << endl << endl;
        }

};


#endif // RAKTAR_H_INCLUDED
