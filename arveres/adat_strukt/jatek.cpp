
#include "jatek.h"



/// Konstruktor -> Egy új játék indítása
Jatek::Jatek(){
    // Ready hamisra
    this->ready = false;
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
    } catch(int a){
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
    } catch(int a){
        cerr << "ERROR: Hiba a fájl kiírásnál. Lehet nem sikerült elmenteni az adatokat." << endl;
        throw 400;
    }
}


/// Játék indítása
void Jatek::inditas(){

    char bemenet[1] = {'0'};
    while(bemenet[0] != 'q' && bemenet[0] != 'Q'){

        console::Clear();

        cout << endl;
        cout << " ============== KARAKTER RAKTAR ARVERES ==============" << endl << endl;
        cout << " Egyenlegem = " << this->ember.get_penz() << " Ft" << endl << endl;


        cout << " s -> Jatek inditasa" << endl;
        cout << " p -> Jatek adatai kiirasa" << endl;
        cout << " q -> Kilepes, adatok mentese (ENELKUL AZ ADATOK ELVESZNEK!!!)" << endl;
        cout << " Valasztasom: ";
        cin >> bemenet;

        console::Clear();
        switch(bemenet[0]) {
            case 'p':
                this->print();
                console::PressAKeyToContinue();
                break;
            case 's':
                if(this->ready){
                    cout << "Jateeeek" << endl;
                    this->licit_inditas();
                } else {
                    cerr << "ERROR: A program nem jatek kesz. Valami hiba tortent a program kezdetekor. Probald meg ujra futtatni." << endl;
                    throw 400;
                }
                break;
            case 'q':
                cout << "Viszlat!" << endl;
                break;
            default:
                cout << "Hibas bemenet" << endl;
                console::PressAKeyToContinue();
        }


    }

}


/// Licit indítása
void Jatek::licit_inditas(){

    // Addig uj raktár licitálás ameddig azt nem mondja hogy nem
    char folytat = 'i';
    while(folytat != 'n'){
        // Új licitálás
        this->hanyadik_raktar += 1;
        Licitalas licitalas(&(this->ember));
        licitalas.print_vevok();
        cout << endl << endl;
        licitalas.kezdes();
        cout << endl << "Szeretned folytatni a kovetkezo raktarral? (i=igen, n=nem)" << endl;
        cin >> folytat;
    }

    // Vissza a főmenübe
    cout << endl << "Most vissza mesz a fomenube" << endl;
    console::PressAKeyToContinue();
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
// Ember kiírása
void Jatek::print_ember(){
    this->ember.print();
    cout << endl;
}
// Játék kiírása
void Jatek::print(){
    cout << endl << "------ JATEK ADATAI ------" << endl << endl;
    cout << "Jatek: " << endl;
    cout << " - Eddigi raktarak szama: " << this->hanyadik_raktar << endl << endl;
    this->print_karakterek();
    this->print_ember();
    cout << "--------------------------" << endl << endl;
}


