#ifndef JATEK_H_INCLUDED
#define JATEK_H_INCLUDED

#include "vevo.h"
#include "karakter.h"
#include "raktar.h"

using namespace std;

/** Egy játék menetet leíró osztály **/
class Jatek{
    private:
        /*Raktar*/
        int hanyadik_raktar=0;
        Raktar akt_raktar;
        /*Vevo*/
        Vevo *kijon;
        Ember ember; // Mindig 1 ember lesz
        Robot robotok[3]; // Mindig 3 robot lesz
        /*Karakter*/
        Karakter* karakterek;
        int karakterek_szama = 0;
    public:
        /// Konstruktor -> Egy új játék indítása
        Jatek(){
            // Kijon beállítása (mindig az ember kezd)
            this->kijon = &(this->ember);
            // Robotok id beállítása
            for(int i; i<3;i++){
                this->robotok[i].set_id(i+1);
            }
        }

        /// GET parameters
        int get_hanyadik_raktar() const{return this->hanyadik_raktar;}
        int get_kijon_vevo_id() const{return this->kijon->get_id();}
        Ember get_ember() const{return this->ember;}

        /// SET parameters
        // Set hanyadik_raktar
        void set_hanyadik_raktar(int h){
            this->hanyadik_raktar = h;
        }
        // Set karakterek (+ karakterek_szama)
        void set_karakterek(Karakter* karakterek_tomb_pointer, int hossz){
            this->karakterek = karakterek_tomb_pointer;
            this->karakterek_szama = hossz;
        }
        // Set Ember vevo[0]
        void set_ember(Ember temp_ember){
            this->ember = temp_ember;
        }

        /// Kiírás
        // Karakterek kiírása
        void print_karakterek(){
            cout << "Karakterek:" << endl;
            for(int i=0; i<karakterek_szama; i++){
                karakterek[i].print();
            }
            cout << endl;
        }
        // Vevők kiírása
        void print_vevok(){
            cout << "Vevok:" << endl;
            this->ember.print();
            for(int i=0; i<3; i++){
                robotok[i].print();
            }
            cout << endl;
        }
        // Játék kiírása
        void print(){
            cout << endl << "------ JATEK ADATAI ------" << endl << endl;
            cout << "Eddigi raktarak szama: " << this->hanyadik_raktar << endl << endl;
            this->print_karakterek();
            this->print_vevok();
            cout << "Kovetkezo vevo ID: " << this->get_kijon_vevo_id() << endl;
            cout << "--------------------------" << endl << endl;
        }
};

#endif // JATEK_H_INCLUDED
