#ifndef LICITALAS_H_INCLUDED
#define LICITALAS_H_INCLUDED

#include "../memtrace.h"

/// Using namespaces
using std::cout;
using std::cerr;
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
        Licitalas(Ember* ember_pointer) :ember(ember_pointer), akt_ar(this->KEZDO_AR) {
            // Robotok id beállítása
            for(int i=0; i<3;i++){
                this->robotok[i].set_id(i+1);
            }
        }

        void kezdes(){
            int robot_passzok_szama = 0; // ha ez 3 lesz -> az ember kapja a raktárat
            bool ember_kiszallt = false;

            // Ameddig az ember nem szallt ki és legalább egy robot sem
            while(!ember_kiszallt && robot_passzok_szama < 3){

                // Aktuális ár kiírása
                this->print_akt_ar();

                // Ember megkérdezése mennyivel emel
                int ember_emeles = ember->emelek();
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

            // Ember megnyerte (ha ember_kiszall még hamis és 3 robot passz volt)
            if(!ember_kiszallt && robot_passzok_szama>=3){
                cout << endl << "MEGNYERTED A RAKTART" << endl << endl;
                // Pénz egyenleg csökkentese
                this->ember->penz_csokkentese(this->akt_ar);
                // Megvett raktárak száma növelése
                this->ember->megvett_raktarak_szama_plus_1();
            }


        }

        // Vevők kiírása
        void print_vevok(){
            cout << "OSSZES VEVO" << endl << endl;
            this->ember->print();
            for(int i=0; i<3; i++){
                robotok[i].print();
            }
            cout << endl;
        }

        void print_akt_ar(){
            cout << "Aktualis raktar ar: " << this->akt_ar << " Ft " << endl << endl;
        }
};

#endif // LICITALAS_H_INCLUDED
