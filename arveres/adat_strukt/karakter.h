#ifndef KARAKTER_H_INCLUDED
#define KARAKTER_H_INCLUDED

using namespace std;


/** Karaktereket le�r� oszt�ly **/

class Karakter{
    public:
        char k;
        int ertek; // a karakter �rt�ke -> 1-10 000 Ft
        int gyakorisag; // 0-100%

        Karakter(char k=' ', int ertek=1, int gyakorisag=0) :k(k), ertek(ertek), gyakorisag(gyakorisag){}
        void kiir(){
            cout << k << ": " << ertek << "Ft (" << gyakorisag << "%)" << endl;
        }

};

#endif // KARAKTER_H_INCLUDED
