#ifndef RAND_RUN_H_
#define RAND_RUN_H_

#include <stdio.h>
#include <stdlib.h>
#include "rr_nats_nouns_verbs.h"
#include "rr_random.h"

int randomSeed;
int maxSteps;

void randrunInit(void);
int parseArgs(int argc, char ** argv);

#endif /* RAND_RUN_H_ */
