#include "rr_random.h"

/* seed the random number generator, protected so it can be called only once */
void rr_init_rand(int seed) {

    if (! rr_seed) {
        if (seed) {
            rr_seed = seed;
        }
        else {
            rr_seed = time(0);
        }
        
        srand(rr_seed);
    }
}

/* Returns a random int between 0 and upperlimit (not inclusive) */
int rr_rand_lim(int upperLimit) {
    int divisor = RAND_MAX/(upperLimit);
    int returnVal;

    do {
        returnVal = rand() / divisor;
    } while (returnVal > upperLimit);

    return returnVal;
}
