#include "randrun.h"

int main() {
   int randomSeed = 0, count = 100, returnValue = 0;

   rr_nats_nouns natsNoun = NATS_CONNECTION;
   
   /* Initialize rand */
   rr_init_rand(randomSeed);

   while (count && !returnValue) {
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
      count--;
   }
   return(returnValue);  
}
