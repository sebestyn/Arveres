
#include "raktar.h"

/// Konstruktor
Raktar::Raktar(Karakter* el_kar, int el_kar_szama){

    // Karakterek számának beállítása
    this->kar_szama = random_gen::range(MIN_KARAKTAREK_SZAMA, MAX_KARAKTAREK_SZAMA);

    // Elérhető karakterek keverése
    random_shuffle(&el_kar[0], &el_kar[el_kar_szama]);

    // Karakterek tom lefoglalása
    this->karakterek = new Karakter[this->kar_szama];

    // Karakterek beállítása valószínűség alapján
    int hanyadik = 0;
    while(hanyadik < this->kar_szama){
        int percent = random_gen::range(1,100);
        int i = random_gen::range(0,el_kar_szama-1);
        if(el_kar[i].get_gyakorisag() >= percent){
            this->karakterek[hanyadik] = el_kar[i];
            this->ossz_ertek += el_kar[i].get_ertek();
            hanyadik++;
        }

    }

}

/// Kiírása
void Raktar::print(){

    // Raktar merete (x*x)
    int x = sqrt(this->kar_szama) + 1;
    if(x<3) x = 3;

    // Üres raktár helyek kitötlése ' ' karakterrel
    char karakterek_k[x*x];
    for(int j=0; j<kar_szama; j++){
        karakterek_k[j] = karakterek[j].get_k();
    }
    for(int j=kar_szama; j<(x*x); j++){
        karakterek_k[j] = ' ';
    }
    //std::random_shuffle(&karakterek_k[0], &karakterek_k[x*x]);

    // Kirajzolás
    int i = 0;
    for(int sor = 0; sor<x; sor++){
        cout << setw(18) << " +---+";
        for(int a=0; a<x-1; a++){cout << "---+";}
        cout << endl << setw(12) << "";
        for(int oszlop = 0; oszlop<x;oszlop++){
            cout << " | " << karakterek_k[i++];
        }
        cout << " |" << endl;
    }

    cout << setw(18) <<  " +---+";
    for(int a=0; a<x-1; a++){cout << "---+";}
    cout << endl << endl;
}

