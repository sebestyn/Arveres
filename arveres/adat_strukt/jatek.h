#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED

#include <conio.h> // PressAKeyToContinue függvényhez

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


/** Egy játék menetet leíró osztály **/
class Jatek{
    private:
        // Raktar
        int hanyadik_raktar=0;
        Raktar akt_raktar;
        // Vevo játékos
        Ember ember;
        // Karakter
        Karakter* karakterek;
        int karakterek_szama = 0;
        // Egyéb
        bool ready = false; // ha a fájl beolvasás sikeres
        static char* KARAKTER_FAJL_NEV;
        static char* JATEKOS_FAJL_NEV;
    public:
        /// Konstruktor -> Egy új játék indítása
        Jatek();

        /// Destruktor
        ~Jatek();

        /// Fájlok beolvasás / kiírás
        void beolvas_fajlokbol();
        void kiiras_fajlba();
        void karakter_fajl_beolvas();
        void jatekos_fajl_beolvas();

        /// Játék indítása
        void inditas();

        /// Licit indítása
        void licit_inditas();

        /// GET parameters
        int get_hanyadik_raktar() const{return this->hanyadik_raktar;}
        Ember get_ember() const{return this->ember;}

        /// SET parameters
        // Set hanyadik_raktar
        void set_hanyadik_raktar(int h){this->hanyadik_raktar = h;}
        // Set karakterek (+ karakterek_szama)
        void set_karakterek(Karakter* kp, int hossz){this->karakterek = kp; this->karakterek_szama = hossz;}
        // Set Ember vevo[0]
        void set_ember(Ember temp_ember){this->ember = temp_ember;}

        /// Kiírás
        // Karakterek kiírása
        void print_karakterek();
        // Ember kiírása
        void print_ember();
        // Játék kiírása
        void print();
};

#endif // JATEK_H_INCLUDED
