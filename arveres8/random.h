#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED

#include <unistd.h>

#include "memtrace.h"

namespace random_gen{
    // Random it between range
    int range(int first, int last){
        return rand() % (last-first+1) + first;
    }
}

#endif // RANDOM_H_INCLUDED
