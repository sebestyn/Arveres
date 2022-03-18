#ifndef LICITALAS_H_INCLUDED
#define LICITALAS_H_INCLUDED


/// Saját fájlok
#include "../memtrace.h"
#include "raktar.h"
#include "karakter.h"

/// Using namespaces
using std::cout;
using std::cin;
using std::endl;


class Licitalas{
    private:
        Raktar raktar;
        Ember* ember; // Mindig 1 ember lesz
        Robot robotok[3]; // Mindig 3 robot lesz
        int akt_ar;
        static int KEZDO_AR;
    public:

        /// Konstruktor
        Licitalas(){ cout << "Licitalas konstruktor() " <<  endl; }
        Licitalas(Ember* ember_pointer, Karakter* elerheto_karakterek, int el_kar_szama) :ember(ember_pointer), akt_ar(this->KEZDO_AR) {

            // Robotok id beállítása
            for(int i=0; i<3;i++){
                this->robotok[i].set_id(i+1);
            }
            // Új raktár generálása
            Raktar temp(elerheto_karakterek, el_kar_szama);
            this->raktar = temp;
        }

        /// Destruktor
        ~Licitalas(){}

        /// GET parameters
        Raktar get_raktar() const {return this->raktar;}

        /// Egy raktár licitálás futtatása
        void futtatas(){

            int robot_passzok_szama = 0; // ha ez 3 lesz -> az ember kapja a raktárat
            bool ember_kiszallt = false;

            // Raktár kirajzolása
            this->get_raktar().print();

            // Kérdezkedés -> ameddig az ember nem szallt ki és legalább egy robot nem passzol
            while(!ember_kiszallt && robot_passzok_szama < 3){

                // Aktuális ár kiírása
                this->print_akt_ar();

                // Ember megkérdezése mennyivel emel
                int ember_emeles = ember->emelsz();
                cout << "Ennyivel emeltel: " << ember_emeles << endl;
                // Ha az ember kiszáll
                if(ember_emeles == 0) {
                    ember_kiszallt = true;
                    cout << "Kiszalltal igy ezt a raktarat elvesztetted!" << endl;
                    break;
                }
                // Ha az ember emel
                else if(ember_emeles > 0){
                    // Van-e ennyi pénze?
                    if(ember->get_penz() >= akt_ar+ember_emeles){
                        this->akt_ar += ember_emeles;
                        this->print_akt_ar();
                    }
                    // Ha nincs ennyi pénze -> ember kiszáll
                    else {
                        ember_kiszallt = true;
                        cout << "Mivel mar nincs ennyi penzed ezt a raktart elvesztetted." << endl;
                        break;
                    }
                }

                // Robotok végig kérdezése mennyivel emel
                robot_passzok_szama = 0;
                for(int i=0; i<3; i++){
                    int robot_emeles = this->robotok[i].emelek();
                    // Ha a robot kiszall
                    if(robot_emeles == 0){
                        cout << robotok[i].get_id() << " robot passzol." << endl;
                        robot_passzok_szama += 1;
                    }
                    // Ha a robot emel
                    else if(robot_emeles > 0) {
                        cout << robotok[i].get_id() << " robot emel: " << robot_emeles << endl;
                        this->akt_ar += robot_emeles;
                        this->print_akt_ar();
                    }
                }

            }

            // Ember megnyerte-e? (ha ember nem szállt ki  és 3 robot passz volt)
            if(!ember_kiszallt && robot_passzok_szama>=3){
                cout << endl << "MEGNYERTED A RAKTART" << endl << endl;
                // Profit kiszámolása és kiítása
                int profit = this->raktar.get_ossz_ertek() - this->akt_ar;
                cout << "Ennyit fizettel: " << this->akt_ar << endl;
                cout << "Ennyi az erteke: " << this->raktar.get_ossz_ertek() << endl;
                cout << "Raktarbol szerzett profit: " << profit << endl;
                // Ember pénz egyenleg változtatása
                this->ember->change_penz(profit);
                // Megvett raktárak száma növelése
                this->ember->megvett_raktarak_szama_plus_1();
            }

            // Raktár dinamikus karakterei felszabadítása
            this->raktar.karakterek_felszabaditasa();
        }

        /// Kiírás
        // Vevők kiírása
        void print_vevok(){
            cout << "OSSZES VEVO" << endl;
            this->ember->print();
            for(int i=0; i<3; i++){
                robotok[i].print();
            }
            cout << endl;
        }
        // Aktuális raktár árának kiírása
        void print_akt_ar(){
            cout << "Aktualis raktar ar: " << this->akt_ar << " Ft " << endl << endl;
        }
};

#endif // LICITALAS_H_INCLUDED
