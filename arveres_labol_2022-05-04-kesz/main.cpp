#define TEST_MODE

// Saját fájlok
#include "karakter.h"
#include "raktar.h"
#include "vevo.h"
#include "licitalas.h"
#include "jatek.h"

#ifndef CPORTA
    #include "raktar.cpp"
    #include "vevo.cpp"
    #include "licitalas.cpp"
    #include "jatek.cpp"
#endif // CPORTA

#include "memtrace.h"
#include "gtest_lite.h"

/// Using namespaces
using std::cout;
using std::cin;
using std::endl;

/// STATIKUS VÁLTOZÓK
int   Raktar    ::MAX_KARAKTAREK_SZAMA = 8;
int   Raktar    ::MIN_KARAKTAREK_SZAMA = 2;
int   Ember     ::KEZDO_PENZ           = 25000;
int   Licitalas ::KEZDO_AR             = 100;
char* Jatek     ::KARAKTER_FAJL_NEV    = (char*)"karaker.dat";
char* Jatek     ::JATEKOS_FAJL_NEV     = (char*)"jatekos.dat";
int   Jatek     ::NYERO_EGYENLEG       = 100000;


namespace tesztek{

    // Karakter
    void karakter(){
        Karakter uj('-', 200, 30);
        TEST(Karakter, letrehozas) {
            EXPECT_EQ( '-', uj.get_k() ) << "Hibas." << endl;
            EXPECT_EQ( 200, uj.get_ertek() ) << "Hibas." << endl;
            EXPECT_EQ( 30, uj.get_gyakorisag() ) << "Hibas." << endl;
        } ENDM
        TEST(Karakter, valtoztatas) {
            uj.set_all('.', 10, 3);
            EXPECT_EQ( '.', uj.get_k() ) << "Hibas." << endl;
            EXPECT_EQ( 10, uj.get_ertek() ) << "Hibas." << endl;
            EXPECT_EQ( 3, uj.get_gyakorisag() ) << "Hibas." << endl;
        } ENDM
    }

    // Raktár
    void raktar(){
        Karakter *k_tomb = new Karakter[4];
        Raktar uj(k_tomb, 4);

        TEST(Raktar, letrehozas) {
            EXPECT_LE( uj.get_MIN_KARAKTAREK_SZAMA(), uj.get_kar_szam() ) << "kissebb." << endl;
            EXPECT_GE( uj.get_MAX_KARAKTAREK_SZAMA(), uj.get_kar_szam() ) << "nagyobb." << endl;
            EXPECT_EQ( uj.get_kar_szam()*10, uj.get_ossz_ertek() ) << "hibas." << endl;
        } ENDM

        delete[] k_tomb;

    }

    // Vevő
    void vevo(){
        // Ember
        Ember uj(12000, 1, "nevem");
        TEST(Ember, letrehozas) {
            EXPECT_EQ( uj.get_id(), 0 ) << "hibas." << endl;
            EXPECT_EQ( uj.get_penz(), 12000 ) << "hibas." << endl;
            EXPECT_EQ( uj.get_megvett_raktarak_szama(), 1 ) << "hibas." << endl;
            //EXPECT_EQ( uj.get_nev(), "nevem" ) << "hibas." << endl;
        } ENDM
        TEST(Ember, valtoztatas) {
            uj.set_all(11000, 2, "neve2");
            EXPECT_EQ( uj.get_penz(), 11000 ) << "hibas." << endl;
            EXPECT_EQ( uj.get_megvett_raktarak_szama(), 2 ) << "hibas." << endl;
            //EXPECT_EQ( uj.get_nev(), "neve2" ) << "hibas." << endl;
            uj.megvett_raktarak_szama_plus_1();
            EXPECT_EQ( uj.get_megvett_raktarak_szama(), 3 ) << "hibas." << endl;
            uj.change_penz(1);
            EXPECT_EQ( uj.get_penz(), 11001 ) << "hibas." << endl;
        } ENDM
        TEST(Ember, reset) {
            uj.reset();
            EXPECT_EQ( uj.get_penz(), 25000 ) << "hibas." << endl;
            EXPECT_EQ( uj.get_megvett_raktarak_szama(), 0 ) << "hibas." << endl;
            //EXPECT_EQ( uj.get_nev(), "" ) << "hibas." << endl;
        } ENDM

        // Robot
        Robot rob(2);
        TEST(Robot, letrehozas) {
            EXPECT_EQ( rob.get_id(), 2 ) << "hibas." << endl;
        } ENDM
        TEST(Robot, set_max_licit) {
            rob.set_max_licit(1000);
            EXPECT_LE( 0, rob.get_max_licit() ) << "kissebb." << endl;
            EXPECT_GE( 2000, rob.get_max_licit() ) << "nagyobb." << endl;
        } ENDM

    }

    // Licitálás
    void licitalas(){
        Karakter *k_tomb = new Karakter[4];
        Raktar* r = new Raktar(k_tomb, 4);
        Ember* e = new Ember(1000, 0, "nevem");
        Robot* ro = new Robot[3];
        Licitalas uj(r, e, ro);
        TEST(Licitalas, letrehozas) {
            EXPECT_EQ( uj.get_akt_ar(), 100 ) << "hibas." << endl;
        } ENDM
        delete[] k_tomb;
        delete e;
    }

    // Játék
    void jatek(){
        Jatek uj(new Ember(12000, 1, "nevem"));
        TEST(Jatek, letrehozas) {
            EXPECT_EQ( uj.get_hanyadik_raktar(), 0 ) << "hibas." << endl;
            EXPECT_EQ( uj.get_karakterek_szama(), 0 ) << "hibas." << endl;
        } ENDM
        TEST(Jatek, beolvas) {
            EXPECT_NO_THROW(uj.beolvas_fajlokbol());
            EXPECT_EQ( uj.get_hanyadik_raktar(), 1 ) << "hibas." << endl;
            EXPECT_EQ( uj.get_karakterek_szama(), 10 ) << "hibas." << endl;
        } ENDM
        TEST(Jatek, reset) {
            uj.reset();
            EXPECT_EQ( uj.get_hanyadik_raktar(), 0 ) << "hibas." << endl;
            EXPECT_EQ( uj.get_karakterek_szama(), 10 ) << "hibas." << endl;
        } ENDM

    }

    // Futtatás
    void futtatas(){
        karakter();
        raktar();
        vevo();
        licitalas();
        jatek();
    }
}


int main() {

    // Random generátor seed véletlet(idő) beállítása
    srand(time(0));

    #ifdef TEST_MODE

    tesztek::futtatas();

    #endif // TEST_MODE


    /// Fő játék változó
    Jatek Fojatek(new Ember);

    /// Előkészítés -> fájlok beolvasasa (hiba esetén kilép)
    try{
        Fojatek.beolvas_fajlokbol();
    } catch(int){
        cerr << "ERROR: Olyan hiba tortent ami miatt a program nem tud tovabb futni." << endl;
        return -1;
    }

    /// Menü futtatasa  (hiba esetén kilép)
    try{
        Fojatek.fomenu_inditas();
    } catch(int){
        cerr << "ERROR: Olyan hiba tortent ami miatt a program nem tud tovabb futni." << endl;
        return -1;
    }

    /// Fájlokba kiírás (hiba esetén kilép)
    cout << " Fajlok mentese: ";
    try{
        Fojatek.kiiras_fajlba();
        cout << "SIKERES" << endl;
    } catch(int){
        cout << "SIKERTELEN" << endl;
    }


    return 0;
}
