#include <iostream>
#include <fstream>

#include "gtest_lite.h"
#include "memtrace.h"

#include "jatek.h"

using namespace std;

namespace test{

    // Fájlok
    void fajlok(){
        TEST(Fajlok, beolvas) {
            Jatek Fojatek;
            EXPECT_NO_THROW(Fojatek.beolvas_fajlokbol()) << "Sikeres fajl beolvasas." << endl;
        } ENDM

        TEST(Fajlok, kivetel) {
            Jatek Fojatek(new Ember);
            Fojatek.set_KARAKTER_FAJL_NEV((char*)"kldsfkasbg");
            Fojatek.set_JATEKOS_FAJL_NEV((char*)"kldsfkasbg");
            EXPECT_ANY_THROW(Fojatek.beolvas_fajlokbol()) << "Hibas fajl beolvasas nem dobott kivetelt." << endl;
        } ENDM
    }

    // Raktar class
    void raktar(){
        TEST(Raktar, karakterek_szama) {
            Karakter* kar = new Karakter[2];
            for(int i = 0; i<2; i++){
                kar[i].print();
            }
        } ENDM
    }

}
