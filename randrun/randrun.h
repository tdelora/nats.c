#ifndef RAND_RUN_H_
#define RAND_RUN_H_

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include "rr_nats_nouns_verbs.h"
#include "rr_logging.h"
#include "rr_random.h"

int randomSeed;
int maxSteps;

#define FILE_READ_BUFFER_SIZE 4096
#define ERROR_STR_BUFFER_SIZE 512

void randrunInit(void);
int parseArgs(int argc, char ** argv);
void printUsageAndExit(char * progName, char * complain);

int readFromFile(void);
int generateRandomly(void);

#endif /* RAND_RUN_H_ */
