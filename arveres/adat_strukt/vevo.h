#ifndef VEVO_H_INCLUDED
#define VEVO_H_INCLUDED

/**
Itt lesznek a vevők
 - lehet robot vagy ember
**/

 class Vevo{
     private:
         char* nev;
         int megvett_raktarak_szama;
     public:
        int id;
        int penz;

 };

class Ember : public Vevo {
    private:

    public:

};

class Robot : public Vevo {
    private:

    public:

};

#endif // VEVO_H_INCLUDED
