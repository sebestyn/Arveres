#include "jatek.h"

/// Konstruktor -> Egy új játék indítása
Jatek::Jatek(){
    // Ready hamisra
    this->ready = false;
}


/// Destruktor
Jatek::~Jatek(){
    if(this->karakterek_szama > 0){
        // Karakterek dinamikus tömb felszabadítása
        delete[] this->karakterek;
    }
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

    // Fájl még nem létezik vagy üres -> alap kezdő adatok beállítása
    if(!fajl.is_open() || fajl.peek() == std::ifstream::traits_type::eof()) {
        this->hanyadik_raktar = 0;
        // Új kezdő Ember mentése a játékba
        Ember temp_ember;
        this->ember = temp_ember;
    }
    // Fájl már létezik és nem üres -> adatok beolvasása
    else {
        // 1. sor -> Hanyadik raktár beolvasás, mentés játékba
        fajl >> this->hanyadik_raktar;
        // 2. sor -> Ember pénze
        int penz;
        fajl >> penz;
        // 3. sor -> Megvett raktárak száma
        int megvett_r_szama;
        fajl >> megvett_r_szama;
        // 4. sor -> Ember neve
        string ember_nev;
        fajl >> ember_nev;

        // Ember mentése a játékba
        Ember temp_ember(penz, megvett_r_szama, ember_nev);
        this->ember = temp_ember;

        // Fájl bezárása
        fajl.close();
    }

}
// Mind2 fájl beolvasás és hibák figyelése
void Jatek::beolvas_fajlokbol(){
    try{
        this->karakter_fajl_beolvas();
        this->jatekos_fajl_beolvas();
        this->ready = true;
    } catch(int a){
        cerr << "ERROR: Nem sikerult az osszes fajlt beolvasni. Ellenorizd, hogy a fajlok megfelelnek-e a felteteleknek!" << endl;
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
        fajl << this->ember.get_megvett_raktarak_szama() << endl;
        // 4. sor -> Ember neve
        fajl << this->ember.get_nev() << endl;

        // Fájl bezárása
        fajl.close();
    } catch(int a){
        cerr << "ERROR: Hiba a fájl kiírásnál. Lehet nem sikerült elmenteni az adatokat." << endl;
        throw 400;
    }
}


/// Játék futtatás
// Játék főmenü megjelenítése
char Jatek::fomenu_print(){
    // Konzol törlése
    console::Clear();

    // Cím
    console::print_jatek_cim();

    // Státuszok
    cout << setfill('.');
    const int cim_length = 84;
    const int nev_length = this->ember.get_nev().length();
    const int penz_length = to_string(ember.get_penz()).length();
    cout << "|" << setw(cim_length/2+1) << " Nevem = "      << this->ember.get_nev()  << " "    << setw(cim_length/2-nev_length-2)  << "|" << endl;
    cout << "|" << setw(cim_length/2+1) << " Egyenlegem = " << this->ember.get_penz() << " Ft " << setw(cim_length/2-penz_length-5) << "|" << endl;
    cout << "=====================================================================================" << endl;

    // Menü
    cout << setfill(' ');
    cout << setw(cim_length/2-13) << "|| "     << "           MENU"       << setw(14) << "||" << endl;
    cout << setw(cim_length/2-9)  << "|| n ->" << " Uj jatek"             << setw(16) << "||" << endl;
    if(this->hanyadik_raktar > 0) {
        cout << setw(cim_length/2-9) << "|| c ->" <<" Jatek folytatasa"      << setw(8)  << "||" << endl;
    }
    cout << setw(cim_length/2-9)  << "|| i ->" << " Info"                 << setw(20)  << "||" << endl;
    cout << setw(cim_length/2-9)  << "|| q ->" << " Kilepes (mentes)"     << setw(8)  << "||" << endl;
    cout << setw(cim_length/2-15) << " " << "==============================" << endl;
    cout << setw(cim_length/2-12) << " " << " Adj meg egy karaktert: ";

    // Karakter bemenet
    return console::char_input();
}
// Játék főmenü indítása
void Jatek::fomenu_inditas(){
    char bemenet = '0';
    while(bemenet != 'q' && bemenet != 'Q'){

        // Menü megjelenítése
        bemenet = this->fomenu_print();

        // Konzol törlése
        console::Clear();

        // Bemenet futtatása
        switch(bemenet) {
            // Új játék
            case 'n':
                if(this->ready){
                    // Minden adat alapra állítása
                    this->reset();
                    // Játék leírása
                    this->print_leiras();
                    // Ember nevének bekérdezése
                    cout << setw(7) << "" << "Add meg a neved: ";
                    this->ember.set_nev(console::string_input());
                    // Licitek indítása ameddig ki nem lép
                    this->licitek_inditas();
                } else {
                    cerr << "ERROR: A program nem jatek kesz. Valami hiba tortent a program kezdetekor. Probald meg ujra futtatni." << endl;
                    throw 400;
                }
                break;
            // Játék állásának kiírása
            case 'i':
                // Leírása
                this->print_leiras();
                // Aktualis adatok
                this->print();
                // Készítette
                cout << endl << " Keszitette: Zsolt Sebestyen" << endl;
                console::PressAKeyToContinue();
                break;
            //  Kilépés
            case 'q':
                console::print_viszlat();
                break;
            // Játék folytatása (ha a raktarak szama nem 0)
            case 'c':
                if(this->hanyadik_raktar > 0){
                    if(this->ready){
                        // Licitek indítása ameddig ki nem lép
                        this->licitek_inditas();
                    } else {
                        cerr << "ERROR: A program nem jatek kesz. Valami hiba tortent a program kezdetekor. Probald meg ujra futtatni." << endl;
                        throw 400;
                    }
                    break;
                }
                // Ha meg nincs régi játék -> defaultba ugrik
            default:
                console::print_hibas_bemenet();
        }

    }
}
// Licitek indítása
void Jatek::licitek_inditas(){

    // Addig uj raktár licitálás ameddig azt nem mondja hogy nem
    char folytat = ' ';
    while(folytat != 'n'){
        // Új licitálás
        Licitalas akt_licitalas(&(this->ember), this->get_karakterek(), this->get_karakterek_szama());
        this->hanyadik_raktar += 1;

        // Licitálás futtatása
        akt_licitalas.futtatas();

        // Folytatja-e?
        cout << endl << " Szeretned folytatni a kovetkezo raktarral? (i vagy n)";
        folytat = console::char_input();

        // Addig kérdezgetem ameddig nem n vagy i a válasz
        while(folytat != 'i' && folytat != 'n'){
            cout << endl << " igen vagy nem? ";
            folytat = console::char_input();
        }
    }

    // Megnyerte?
    if(this->ember.get_penz() >= this->NYERO_EGYENLEG ){
        console::Clear();
        console::print_megnyerted();
        cout << endl << " Gratulalunk, elerted a nyereshez szukseges osszeget: " << this->NYERO_EGYENLEG << " Ft" << endl << endl;
        console::PressAKeyToContinue();
    }

}


/// Kiírás
// Karakterek kiírása
void Jatek::print_karakterek(){
    cout << "Karakterek:" << endl;
    for(int i=0; i<this->karakterek_szama; i++){
        this->karakterek[i].print();
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
    cout << R"(
     _        _         _          _
    / \    __| |  __ _ | |_  ___  | | __
   / _ \  / _` | / _` || __|/ _ \ | |/ /
  / ___ \| (_| || (_| || |_| (_) ||   <
 /_/   \_\\__,_| \__,_| \__|\___/ |_|\_\
)" << endl;

    cout << "   Jatek: " << endl;
    cout << "    - Eddigi raktarak szama: " << this->hanyadik_raktar << endl << endl;
    this->print_ember();
}
// Játék leírás
void Jatek::print_leiras(){
    cout << R"(
      _         _         _                     _             _
     | |  __ _ | |_  ___ | | __ ___  ____ __ _ | |__    __ _ | | _   _
  _  | | / _` || __|/ _ \| |/ // __||_  // _` || '_ \  / _` || || | | |
 | |_| || (_| || |_|  __/|   < \__ \ / /| (_| || |_) || (_| || || |_| |
  \___/  \__,_| \__|\___||_|\_\|___//___|\__,_||_.__/  \__,_||_| \__, |
                                                                 |___/
)" << endl;
    cout << setw(10) << "1. " << "A cel, hogy ossze gyujts " << this->NYERO_EGYENLEG << " Ft osszeget." << endl;
    cout << setw(10) << "2. " << "Raktarakra kell licitalnod robotok ellen." << endl;
    cout << setw(10) << "3. " << "Minden raktarban karakterek lesznek amiknek az ertekuk a jatek folyaman nem valtozik." << endl;
    cout << setw(10) << "4. " << "Ha sikerul megszerezned egy raktarat rogton megkapod a belole szerzett profitot." << endl;
    cout << setw(10) << "5. " << "Addig kapsz uj raktarakat ameddig vissza nem mesz a fomenube." << endl;
    cout << setw(10) << "6. " << "A raktarak szama vegtelen es ameddig nem kezdesz uj jatekot, ott tudod folytatni ahol abba hagytad." << endl;
    cout << endl;
}

