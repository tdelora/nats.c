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
   char fileReadBuffer[FILE_READ_BUFFER_SIZE];

   memset(fileReadBuffer,0,FILE_READ_BUFFER_SIZE);

   /* Read from stdin and break up the results */
   while ((sizeRead = read(fileno(stdin), fileReadBuffer, FILE_READ_BUFFER_SIZE)) > 0) {

      char* token = strtok(fileReadBuffer, "\n");
      while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, "\n");
    }

      /* rr_writeWorkLine(fileReadBuffer); */

      memset(fileReadBuffer,0,FILE_READ_BUFFER_SIZE);
   }

   return(returnValue);
}  /* readFromFile */


int generateRandomly(void) {
   int count = 0, returnValue = 0;
   char errorString[ERROR_STR_BUFFER_SIZE];
   rr_nats_nouns natsNoun = NATS_CONNECTION;

   memset(errorString,0,ERROR_STR_BUFFER_SIZE);

   while (count < maxSteps && !returnValue) {

      natsNoun = rr_get_randon_nats_noun();

      switch (natsNoun)
      {
         case NATS_CONNECTION:
            rr_writeWorkLine((char *) "NATS_CONNECTION");
            break;
      
         case NATS_PUBLISHER:
            rr_writeWorkLine((char *) "NATS_PUBLISHER");
            break;

         case NATS_SUBSCRIBER:
            rr_writeWorkLine((char *) "NATS_SUBSCRIBER");
            break;
      
         default:
            sprintf(errorString,"Main received unexpected nats noun %d\n",natsNoun);
            rr_writeErrorLine(errorString);
            returnValue = 1;
            break;
      }

      fprintf(stdout,"\n");
      count++;
   }

   return(returnValue);
} /* generateRandomly */

