
#include "licitalas.h"


/// Konstruktor
//Licitalas(){ cout << "Licitalas konstruktor() " <<  endl; }
Licitalas::Licitalas(Raktar* r, Ember* e, Robot* ro_ok) :raktar(r), ember(e), robotok(ro_ok), akt_ar(this->KEZDO_AR) {
    // Robotok
    for(int i=0; i<3;i++){
        // Id beállítás
        this->robotok[i].set_id(i+1);
        // Licit max licit ár beállítás
        this->robotok[i].set_max_licit(this->raktar->get_ossz_ertek());
    }
}


/// Egy raktár licitálás futtatása
void Licitalas::futtatas(){

    int robot_passzok_szama = 0; // ha ez 3 lesz -> az ember nyeri a raktárat
    bool ember_kiszallt = false;

    // Kérdezkedés -> ameddig az ember nem szallt ki és legalább egy robot nem passzol
    while(!ember_kiszallt && robot_passzok_szama < 3){

        // Adatok kiírása
        console::Clear();
        console::print_raktar_cim();
        cout << setw(10) << "" << "Egyenlegem: " << this->ember->get_penz() << "Ft" << endl << endl;
        this->raktar->print();
        this->print_akt_ar();
        cout << "===========================================" << endl << endl;

        // Ember megkérdezése mennyivel emel
        int ember_emeles = ember->emelsz();
        // Ha az ember kiszáll
        if(ember_emeles == 0) {
            ember_kiszallt = true;
            cout << " Kiszalltal igy ezt a raktarat elvesztetted!" << endl;
            break;
        }
        // Ha az ember emel
        else if(ember_emeles > 0){
            // Van-e ennyi pénze?
            if(ember->get_penz() >= akt_ar+ember_emeles){
                this->akt_ar += ember_emeles;
            }
            // Ha nincs ennyi pénze -> ember kiszáll
            else {
                ember_kiszallt = true;
                cout << " Mivel mar nincs ennyi penzed ezt a raktart elvesztetted." << endl;
                break;
            }
            #ifndef CPORTA
            usleep(1);
            #endif
        }

        // Robotok végig kérdezése mennyivel emel vagy passzol
        robot_passzok_szama = 0;
        for(int i=0; i<3; i++){
            int robot_emeles = this->robotok[i].emelsz(this->akt_ar);
            cout << " " << robotok[i].get_id() << " robot ";
            // Ha a robot kiszall
            if(robot_emeles == 0){
                cout << "passzol." << endl;
                robot_passzok_szama += 1;
            }
            // Ha a robot emel
            else if(robot_emeles > 0) {
                this->akt_ar += robot_emeles;
                cout << "emel: " << robot_emeles << " Ft-tal" << endl;
            }
            sleep(1);
        }

    }

    // Ember megnyerte-e? (ha ember nem szállt ki  és 3 robot passz volt)
    if(!ember_kiszallt && robot_passzok_szama>=3){

        // Adatok kiírása
        console::Clear();
        console::print_raktar_cim();
        cout << setw(10) << "" << "Egyenlegem: " << this->ember->get_penz() << "Ft" << endl << endl;
        this->raktar->print();
        this->print_akt_ar();
        cout << "===========================================" << endl << endl;

        // Profit kiszámolása és kiírása
        int profit = this->raktar->get_ossz_ertek() - this->akt_ar;

        // Eredmény kiírása
        cout << endl << " MEGNYERTED A RAKTART!" << endl << endl;
        cout << " Raktar erteke: " << this->raktar->get_ossz_ertek() << " Ft" << endl;
        cout << " Profit: " << profit << " Ft" << endl;
        cout << " Uj egyenlegem: " << this->ember->get_penz() + profit << " Ft" << endl;

        // Ember pénz egyenleg változtatása
        this->ember->change_penz(profit);
        // Megvett raktárak száma növelése
        this->ember->megvett_raktarak_szama_plus_1();

    }

}

/// Kiírás
// Vevők kiírása
void Licitalas::print_vevok(){
    cout << "OSSZES VEVO" << endl;
    this->ember->print();
    for(int i=0; i<3; i++){
        robotok[i].print();
    }
    cout << endl;
}
// Aktuális raktár árának kiírása
void Licitalas::print_akt_ar(){
    cout << setw(10) << "" << "Jelenlegi ar: " << this->akt_ar << " Ft " << endl;
}


