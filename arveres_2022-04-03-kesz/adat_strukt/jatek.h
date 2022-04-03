#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED

/// Saját fájlok
#include "../memtrace.h"
#include "../console.h"
#include "vevo.h"
#include "karakter.h"
#include "raktar.h"
#include "licitalas.h"

/// Using namespaces
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::setfill;
using std::to_string;

/**
Egy játék menetet leíró osztály
 - itt vannak egy játék menet adatai
 - ameddig valaki nem kezd új játékot itt lesznek elmentve a föbb adatok
 - ez indítja a főmenüt ahol lehet majd választani merre tovább
 - ez indítja a liciteket
**/

class Jatek{
    private:
        // Raktar
        int hanyadik_raktar=0;
        // Vevo játékos
        Ember ember;
        // Karakter
        Karakter* karakterek;
        int karakterek_szama = 0;
        // Egyéb
        bool ready = false; // ha a fájl beolvasás sikeres
        static char* KARAKTER_FAJL_NEV;
        static char* JATEKOS_FAJL_NEV;
        static int   NYERO_EGYENLEG;
    public:
        /// Konstruktor -> Egy új játék indítása
        Jatek();

        /// Destruktor
        ~Jatek();

        /// Reset -> minden adat alapra állítása
        void reset(){ this->hanyadik_raktar = 0; this->ember.reset(); }

        /// Fájlok beolvasás / kiírás
        void beolvas_fajlokbol();
        void kiiras_fajlba();
        void karakter_fajl_beolvas();
        void jatekos_fajl_beolvas();

        /// Játék főmenü megjelenítése / indítása
        char fomenu_print();
        void fomenu_inditas();

        /// Licitek indítása
        void licitek_inditas();

        /// GET parameters
        int get_hanyadik_raktar()  const { return this->hanyadik_raktar; }
        Karakter* get_karakterek() const { return this->karakterek; }
        int get_karakterek_szama() const { return this->karakterek_szama; }
        Ember get_ember()          const { return this->ember; }

        /// SET parameters
        void set_hanyadik_raktar(int h)             {this->hanyadik_raktar = h;}
        void set_karakterek(Karakter* kp, int hossz){this->karakterek = kp; this->karakterek_szama = hossz;}
        void set_ember(Ember temp_ember)            {this->ember = temp_ember;}
        void set_KARAKTER_FAJL_NEV(char* s)         {this->KARAKTER_FAJL_NEV = s;}
        void set_JATEKOS_FAJL_NEV(char* s)          {this->JATEKOS_FAJL_NEV = s;}

        /// Kiírás
        void print_karakterek();
        void print_ember();
        void print();
        void print_leiras();
};

#endif // JATEK_H_INCLUDED
