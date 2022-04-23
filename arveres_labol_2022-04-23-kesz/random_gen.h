#ifndef RANDOM_GEN_H_INCLUDED
#define RANDOM_GEN_H_INCLUDED

#ifndef CPORTA
    #include "memtrace.h"
#endif // CPORTA

namespace random_gen{
    // Random it between range
    int range(int first, int last){
        return rand() % (last-first+1) + first;
    }
}

#endif // RANDOM_GEN_H_INCLUDED
