# Karakter raktár árverés

### PROGRAMOZÁS ALAPJAI 2. - NHF

#### ZSOLT SEBESTYÉN

## Rövid leírás

Egyszemélyes, parancssoros árverős játék. Cél minél nagyobb profithoz jutni. Az árverésen egymás után
raktárakért kell licitálni, amiben speciális karakterek vannak. Minden karakternek van egy egyedi értéke, amit a
játék során lehet kideríteni/megsejteni. Egy licitálás során 3 gép ellen játszol. Ha egy raktárért te ajánlasz a
legtöbbet megkapod a benne lévő karakterekkel együtt. Ezt rögtön el is adod és kiderül mennyit profitáltál vagy
buktál rajta. A játék akkor ér véget amikor elfogy a pénzed (vesztettél) vagy elérsz egy bizonyos összeget (nyertél).

## Fájlok, külső adatok

A speciális karakterek „karaker.dat” fájlból olvasható be. Ez a fájl a játék során nem változtatható, de kézzel
átírható. Egy sor tartalmazza egy karakter adatait szóközzel elválasztva: KARAKTER ÉRTÉK GYAKORISÁG. Ha ez a
fájl nem létezik a játék a legelején hibát dob. Ennek hiányát kézzel kell megírni.

A játékos adatait a “jatekos.dat” fájl tartalmazza. Ez a játék során is újra generálódik. Ez teszi lehetővé a program
bezárása után is onnan lehessen folytatni a játékot, ahol abba hagyta a játékos. Az adatok külön sorban vannak
elválasztva: JÁTSZOTT_RAKTARAK_SZAMA JÁTÉKOS_EGYENLEGE MEGVETT_RAKTARAK_SZAMA. Ha ez a fájl
nem létezik a játék nem dob hibát és a játék során a fájl létrejön.

## Játék menete

1. **Program indítása:** alapadatok beállítása (nem első játék esetén korábbi adatok betöltése)
2. **Menüből választás:** választhatod, hogy új játékot kezdesz vagy ha már játszottál, a régit folytatod
3. **Raktár licitálás:**
    a. kirajzolja a raktárt, benne található speciális karaktereket és kiírja a kezdőárat
    b. játékos és a 3 robot egymás után jőve licitál vagy kiszál
    c. aki utoljára bent marad megkapja a raktárt
4. **Profitálás** : ezután rögtön kiderül mennyit ér a raktár és mennyit profitáltál vagy vesztettél
5. **(Vége)** : ha elfogy a pénzed vagy eléred a maximális összeget vissza ugrik a 2. ponthoz máskülönben megy
    tovább
6. **Menüből választás:** választhatod, hogy abba hagyod a játékot vagy mész a következő raktárhoz (ugrás a
    3. ponthoz)

## Tesztelés

Tesztelés módban több fajta teszt futtatására van lehetőség, ami a program egészét teszteli hibás bemenetekre
is. Ezt a TEST_MODE makróval lehet beállítani, majd a parancssorból kiválasztani a futtatni szánt tesztfüggvény
sorszámát.


