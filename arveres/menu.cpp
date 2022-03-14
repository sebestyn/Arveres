
#include "menu.h"



/// Men� futtat�sa
void menu::run(Jatek* jatek){

    char bemenet = '0';
    while(bemenet != 'q' && bemenet != 'Q'){

        cout << "Valassz a menu kozul: " << endl;
        cout << "   q -> Kilepes, adatok mentese (ENELKUL AZ ADATOK ELVESZNEK!!!)" << endl
             << "   p -> Jatek adatai kiirasa" << endl;
        cout << "Valasztasom: ";
        cin >> bemenet;

        if(bemenet == 'p'){
            p(jatek);
        }
    }

}

/// Bemenetek f�ggv�nyek
// p -> J�t�k adatainak ki�r�sa
void menu::p(Jatek* jatek){
    jatek->print();
}
