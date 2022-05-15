#include "randrun.h"

int main(int argc, char ** argv) {
   int returnValue = 0;
   
   /* Initialize steps */
   /* Init global values */
   randrunInit();

   /* Read Command Line */
   returnValue = parseArgs(argc,argv);

   if ( returnValue == 0 ) {
      /* Initialize rand */
      rr_init_rand(randomSeed);

      if ( ! isatty(fileno(stdin)) ) {
         /* File read */
         returnValue = readFromFile();
      }
      else {
         returnValue = generateRandomly();
      }
   }

   return(returnValue);  
} /* main() */


void randrunInit(void) {
   randomSeed = 0;
   maxSteps = 100;
} /* randrunInit() */


int parseArgs(int argc, char ** argv) {
   int i = 0, returnValue = 0;

   for ( i = 1 ; i < argc ; i++ ) {
      if ( !strcasecmp(argv[i], "-maxSteps")  ) {
         if (i + 1 == argc) {
            printUsageAndExit(argv[0],NULL);
         }
         
         maxSteps = atoi(argv[++i]);
      }
      else if ( !strcasecmp(argv[i], "-randomSeed") ) {
         if (i + 1 == argc) {
            printUsageAndExit(argv[0],NULL);
         }
         
         randomSeed = atoi(argv[++i]);
      }
      else if ( !strcasecmp(argv[i], "-h") || !strcasecmp(argv[i], "-help") ) {
         printUsageAndExit(argv[0],NULL);
      }
      else {
         printUsageAndExit(argv[0],argv[i]);
      }
   }

   return(returnValue);
} /* parseArgs() */


void printUsageAndExit(char * progName, char * complain) {

   if ( complain!= NULL ) {
      fprintf(stdout,"\nUnknown argument: %s\n", complain);
   }

   fprintf(stdout,"\nUsage: %s [options]\n\n" \
   "options are:\n" \
   "-maxSteps <n>\tThe maximum number of steps to run.\n" \
   "-randomSeed <n>\tThe value to use for random seed.\n" \
   "-help (or -h)\tPrint Usage"
   "\n\n"
   ,progName);
   exit(1);
} /* printUsageAndExit */


int readFromFile(void) {
   int returnValue = 0, sizeRead = 0;
   char fileReadBuffer[FILE_READ_BUFFER_SIZE], * token = (char *) NULL;

   memset(fileReadBuffer,0,FILE_READ_BUFFER_SIZE);

   /* Read from stdin and break up the results */
   while ((sizeRead = read(fileno(stdin), fileReadBuffer, FILE_READ_BUFFER_SIZE)) > 0) {
      token = strtok(fileReadBuffer, "\n");
      while (token != NULL) {
        rr_check_execute_nats_noun_verb_line(token);
        token = strtok(NULL, "\n");
      }

      memset(fileReadBuffer,0,FILE_READ_BUFFER_SIZE);
   }

   return(returnValue);
}  /* readFromFile */


int generateRandomly(void) {
   int count = 0, returnValue = 0;

   while (count < maxSteps && !returnValue) {
      returnValue = rr_genex_random_nats_noun_verb();
      count++;
   }

   return(returnValue);
} /* generateRandomly */

