#include "randrun.h"

int main() {
   int count = 0, returnValue = 0;

   rr_nats_nouns natsNoun = NATS_CONNECTION;
   
   randrunInit();
   /* Initialize rand */
   rr_init_rand(randomSeed);

   while (count < maxSteps && !returnValue) {
      natsNoun = rr_get_randon_nats_noun();

      switch (natsNoun)
      {
      case NATS_CONNECTION:
         fprintf(stdout,"%s","NATS_CONNECTION");
         break;
      
      case NATS_PUBLISHER:
         fprintf(stdout,"%s","NATS_PUBLISHER");
         break;

      case NATS_SUBSCRIBER:
         fprintf(stdout,"%s","NATS_SUBSCRIBER");
         break;
      
      default:
         fprintf(stderr,"Main received unexpected nats noun %d\n",natsNoun);
         returnValue = 1;
         break;
      }

      fprintf(stdout,"\n");
      count++;
   }
   return(returnValue);  
} /* main() */

void randrunInit(void) {
   randomSeed = 0;
   maxSteps = 100;
} /* randrunInit() */

int parseArgs(int argc, char ** argv) {
   int returnValue = 0;

   return(returnValue);
} /* parseArgs() */
