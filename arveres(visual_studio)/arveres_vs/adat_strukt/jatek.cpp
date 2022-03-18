
using namespace std;

#include "jatek.h"



/// Konstruktor -> Egy új játék indítása
Jatek::Jatek(){
    // Ready hamisra
    this->ready = false;
    // Kijon beállítása (mindig az ember kezd)
    this->kijon = &(this->ember);
    // Robotok id beállítása
    for(int i=0; i<3;i++){
        this->robotok[i].set_id(i+1);
    }
}


/// Destruktor
Jatek::~Jatek(){
    // Karakterek dinamikus tömb felszabadítása
    delete[] this->karakterek;
}


/// Fájlok beolvasás / kiírás
// Karakter fájl beolvasása, elmentése
void Jatek::karakter_fajl_beolvas(){

    // Fájl megnyitása
    ifstream fajl(this->KARAKTER_FAJL_NEV);
    if (!fajl.is_open()) throw 400; //Nem sikerült megnyitni

    // Első sor -> összsen hány sor lesz?
    fajl >> this->karakterek_szama;
    if(this->karakterek_szama<=0)throw 400; //Nem helyes sorok száma (0<)

    // Dinamikus karakterek tömb beállítása
    this->karakterek = new Karakter[this->karakterek_szama];

    // Sorok beovasása
    for(int i=0; i<this->karakterek_szama; i++) {
        char k;
        int ertek, gyakorisag;
        fajl >> k;
        fajl >> ertek;
        fajl >> gyakorisag;
        this->karakterek[i].set_all(k, ertek, gyakorisag);
    }

    // Fájl bezárása
    fajl.close();
}
// Játékos adatai fájl beolvasása, elmentése
void Jatek::jatekos_fajl_beolvas(){
    // Fájl megnyitása
    ifstream fajl(this->JATEKOS_FAJL_NEV);

    // Fájl már létezik és nem üres -> adatok beolvasása
    if (fajl.is_open()){
        // 1. sor -> Hanyadik raktár beolvasás, mentés játékba
        fajl >> this->hanyadik_raktar;
        // 2. sor -> Ember pénze
        int penz;
        fajl >> penz;
        // 3. sor -> Megvett raktárak száma
        int megvett_r_szama;
        fajl >> megvett_r_szama;

        // Ember mentése a játékba
        Ember temp_ember(penz, megvett_r_szama);
        this->ember = temp_ember;

        // Fájl bezárása
        fajl.close();
    }
    // Fájl még nem létezik -> alap kezdő adatok beállítása
    else {
        this->hanyadik_raktar = 0;
        // Új kezdő Ember mentése a játékba
        Ember temp_ember;
        this->ember = temp_ember;
    }
}
// Mind2 fájl beolvasás és hibák figyelése
void Jatek::beolvas_fajlokbol(){
    try{
        this->karakter_fajl_beolvas();
        this->jatekos_fajl_beolvas();
        this->ready = true;
    } catch(int){
        cerr << "ERROR: Nem sikerult az osszes fajlt beolvasni. Ellenorizd a megfelelnek-e a felteteleknek!" << endl;
        throw 400;
    }
}
// Játékos adatai fájl kiírása
void Jatek::kiiras_fajlba(){
    try{
        // Fájl megnyitása
        ofstream fajl(this->JATEKOS_FAJL_NEV);
        if (!fajl.is_open()) throw 400; //Nem sikerült megnyitni

        // 1. sor -> Hanyadik raktár
        fajl << this->hanyadik_raktar << endl;
        // 2. sor -> Ember pénze
        fajl << this->ember.get_penz() << endl;
        // 3. sor -> Megvett raktárak száma
        fajl << this->ember.get_megvett_raktarak_szama();

        // Fájl bezárása
        fajl.close();
    } catch(int){
        cerr << "ERROR: Hiba a fájl kiírásnál. Lehet nem sikerült elmenteni az adatokat." << endl;
        throw 400;
    }
}


/// Játék indítása
void Jatek::inditas(){

    char bemenet[2] = {'0', '\0'};
    while(bemenet[0] != 'q' && bemenet[0] != 'Q'){

        //console::Clear();

        cout << endl;
        cout << " ============== KARAKTER RAKTAR ARVERES ==============" << endl << endl;
        cout << " Egyenlegem = " << this->ember.get_penz() << " Ft" << endl << endl;


        cout << " s -> Jatek inditasa" << endl;
        cout << " p -> Jatek adatai kiirasa" << endl;
        cout << " q -> Kilepes, adatok mentese (ENELKUL AZ ADATOK ELVESZNEK!!!)" << endl;

        cout << " Valasztasom: ";
        cin >> bemenet;

        //console::Clear();
        switch(bemenet[0]) {
            case 'p':
                this->print();
                //console::PressAKeyToContinue();
                break;
            case 's':
                cout << "Jateeeek" << endl;
                //console::PressAKeyToContinue();
                break;
            case 'q':
                cout << "Viszlat!" << endl;
                break;
            default:
                cout << "Hibas bemenet" << endl;
                //console::PressAKeyToContinue();
        }


    }
}


/// Kiírás
// Karakterek kiírása
void Jatek::print_karakterek(){
    cout << "Karakterek:" << endl;
    for(int i=0; i<karakterek_szama; i++){
        karakterek[i].print();
    }
    cout << endl;
}
// Vevők kiírása
void Jatek::print_vevok(){
    cout << "Vevok:" << endl;
    this->ember.print();
    for(int i=0; i<3; i++){
        robotok[i].print();
    }
    cout << endl;
}
// Játék kiírása
void Jatek::print(){
    cout << endl << "------ JATEK ADATAI ------" << endl << endl;
    cout << "Eddigi raktarak szama: " << this->hanyadik_raktar << endl << endl;
    this->print_karakterek();
    this->print_vevok();
    cout << "Kovetkezo vevo ID: " << this->get_kijon_vevo_id() << endl;
    cout << "--------------------------" << endl << endl;
}


