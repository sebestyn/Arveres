#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED


namespace random{

    // Random it between range
    int range(int first, int last){
        return rand() % (last-first+1) + first;
    }
}


#endif // RANDOM_H_INCLUDED
