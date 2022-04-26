#include "rr_random.h"

/* seed the random number generator, protected so it can be called only once */
void rr_init_rand(void) {

    if (! rr_seed) {
        rr_seed = time(0);
        srand(rr_seed);
    }
}

/* Returns a random int between 0 and limit (not inclusive */
int rr_rand_lim(int limit) {
    int divisor = RAND_MAX/(limit);
    int retval;

    do {
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}
