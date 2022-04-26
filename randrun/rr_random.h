#ifndef RR_RANDOM_
#define RR_RANDOM_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int rr_seed = 0;

void rr_init_rand(void);
int rr_rand_lim(int limit);


#endif /* RR_RANDOM_ */
