#include <iostream>
#include <fstream>

#include "gtest_lite.h"
#include "memtrace.h"

/// Saját fájlok
#include "console.h"
#include "console.cpp"
#include "random.h"
#include "karakter.h"
#include "karakter.cpp"
#include "jatek.h"
#include "jatek.cpp"
#include "licitalas.h"
#include "licitalas.cpp"
#include "raktar.h"
#include "raktar.cpp"
#include "vevo.h"
#include "vevo.cpp"

using namespace std;

namespace test{

    // Fájlok
    void fajlok(){
        TEST(Fajlok, beolvas) {
            Jatek Fojatek;
            EXPECT_NO_THROW(Fojatek.beolvas_fajlokbol()) << "Sikeres fajl beolvasas." << endl;
        } ENDM

        TEST(Fajlok, kivetel) {
            Jatek Fojatek;
            Fojatek.set_KARAKTER_FAJL_NEV((char*)"kldsfkasbg");
            Fojatek.set_JATEKOS_FAJL_NEV((char*)"kldsfkasbg");
            EXPECT_ANY_THROW(Fojatek.beolvas_fajlokbol()) << "Hibas fajl beolvasas nem dobott kivetelt." << endl;
        } ENDM
    }

    // Raktar class
    void raktar(){
        TEST(Raktar, karakterek_szama) {
            Karakter* kar = new Karakter[6];
            Raktar foraktar(kar, 6);
            EXPECT_GE(foraktar.get_MAX_KARAKTAREK_SZAMA(), foraktar.get_kar_szam()) << "Raktarban tobb karakter mint megengedett." << endl;
            EXPECT_LE(foraktar.get_MIN_KARAKTAREK_SZAMA(), foraktar.get_kar_szam()) << "Raktarban kevesebb karakter mint megengedett." << endl;
            foraktar.karakterek_felszabaditasa();
            delete[] kar;
        } ENDM


    }

}
