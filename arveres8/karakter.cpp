
#include "karakter.h"

/// SET all parameters
void Karakter::set_all(char k, int ertek, int gyakorisag){
    this->k = k;
    this->ertek = ertek;
    this->gyakorisag = gyakorisag;
}

/// Kiírás
void Karakter::print(){
    cout << " - " << k << ": " << ertek << "Ft (" << gyakorisag << "%)" << endl;
}
