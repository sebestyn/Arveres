#ifndef KARAKTER_H_INCLUDED
#define KARAKTER_H_INCLUDED

using namespace std;

/** Karaktereket leíró osztály **/
class Karakter{
    private:
        char k; // pl.: @
        int ertek; // a karakter értéke -> 1-10 000 Ft
        int gyakorisag; // 0-100%
    public:

        Karakter(char k=' ', int ertek=1, int gyakorisag=0) :k(k), ertek(ertek), gyakorisag(gyakorisag){}

        /// GET parameters
        char get_k() const {return this->k;}
        int get_ertek() const {return this->ertek;}
        int get_gyakorisag() const {return this->gyakorisag;}

        /// SET parameters
        void set_all(char k=' ', int ertek=0, int gyakorisag=0){
            this->k = k;
            this->ertek = ertek;
            this->gyakorisag = gyakorisag;
        }

        /// Kiírás
        void print(){
            cout << " - " << k << ": " << ertek << "Ft (" << gyakorisag << "%)" << endl;
        }

};

#endif // KARAKTER_H_INCLUDED
