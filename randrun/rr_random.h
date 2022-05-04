#ifndef RR_RANDOM_
#define RR_RANDOM_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int rr_seed;

void rr_init_rand(int seed);
int rr_rand_lim(int limit);


#endif /* RR_RANDOM_ */
