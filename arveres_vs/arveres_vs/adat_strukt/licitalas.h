#ifndef LICITALAS_H_INCLUDED
#define LICITALAS_H_INCLUDED

/// Includes
#include <iostream>
#include "../memtrace.h"

/// Saját fájlok
#include "raktar.h"
#include "vevo.h"


/// Using namespaces
using std::cout;
using std::cin;
using std::endl;


class Licitalas{
    private:
        Raktar raktar;
        Vevo* vevok;
};

#endif // LICITALAS_H_INCLUDED
