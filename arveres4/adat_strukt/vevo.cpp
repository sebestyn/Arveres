#include "vevo.h"

//////////////////////////////////////////
/// Ember

// Licit�l�s emel�s k�rd�s
int Ember::emelsz(){
    cout << " Mennyivel emelsz? (0=kiszallok) ";
    int emelek_osszeg = console::int_input(true);
    cout << endl;
    return emelek_osszeg;
}

// Ki�r�s
void Ember::print() {
    cout << "   Ember:" << endl <<
            /*"    - id: "<< this->get_id() << endl <<*/
            "    - nev: "<< this->nev << endl <<
            "    - Penz egyenlege: "<< this->penz << endl <<
            "    - Megevett raktarak: "<< this->megvett_raktarak_szama << endl;
}

//////////////////////////////////////////
/// Robot

// Max licit ar beall�t�sa
void Robot::set_max_licit(int raktar_ertek){
    // T�l �rt�keli -> 20%
    bool tul_ertekeli = random::range(1,100) > 80;
    int csuszas = random::range(1, raktar_ertek);

    if(tul_ertekeli){
        this->max_licit = raktar_ertek+csuszas;
    } else {
        this->max_licit = raktar_ertek-csuszas;
    }
}

// Licit�l�s emel�s k�rd�s
int Robot::emelsz(int akt_ar){
    // Ha nem l�pte t�l a max licitet
    if(this->max_licit > akt_ar){
        int mennyivel_emeljek = random::range(1, this->max_licit-akt_ar);
        // 10es kerek�t�s
        mennyivel_emeljek=(((mennyivel_emeljek+10)/10)*10);
        return mennyivel_emeljek;
    }
    return 0;
}

// Ki�r�s
void Robot::print(){
    cout << "Robot:" << endl <<
            " - id: "<< this->get_id() << endl;
}
