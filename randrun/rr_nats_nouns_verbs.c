#include "rr_nats_nouns_verbs.h"

int rr_genex_random_nats_noun_verb(void) {
    char errorString[ERROR_STR_BUFFER_SIZE];
    rr_nats_nouns natsNoun = NATS_CONNECTION;
    int returnValue = 0;

    memset(errorString,0,ERROR_STR_BUFFER_SIZE);

    natsNoun = rr_get_random_nats_noun();

    switch (natsNoun) {
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

    return(returnValue);
}

rr_nats_nouns rr_get_random_nats_noun(void) {
    int nounRand = rr_rand_lim(RR_NATS_NOUN_COUNT); 
    rr_nats_nouns returnValue = (rr_nats_nouns) nounRand;

    return(returnValue);
}
