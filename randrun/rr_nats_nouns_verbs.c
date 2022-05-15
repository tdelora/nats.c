#include "rr_nats_nouns_verbs.h"

int rr_check_execute_nats_noun_verb_line(char * line) {
    int returnValue = 0;

    fprintf(stdout,"check: %s\n",line);

    return(returnValue);
} /* rr_check_execute_nats_noun_verb_line */


int rr_execute_nats_noun_verb_line(char * line) {
    int returnValue = 0;

    fprintf(stdout,"%s\n",line);

    return(returnValue);
} /* rr_execute_nats_noun_verb_line */


int rr_genex_random_nats_noun_verb(void) {
    char errorString[ERROR_STR_BUFFER_SIZE], * natsNounString = (char *) NULL;
    rr_nats_nouns natsNoun = NATS_CONNECTION;
    int returnValue = 0;

    memset(errorString,0,ERROR_STR_BUFFER_SIZE);

    natsNoun = rr_get_random_nats_noun();

    switch (natsNoun) {
        case NATS_CONNECTION:
            natsNounString =  (char *)  "NATS_CONNECTION";
            break;
      
        case NATS_PUBLISHER:
            natsNounString = (char *) "NATS_PUBLISHER";
            break;

        case NATS_SUBSCRIBER:
            natsNounString = (char *) "NATS_SUBSCRIBER";
            break;
        
        default:
            sprintf(errorString,"Main received unexpected nats noun %d\n",natsNoun);
            rr_writeErrorLine(errorString);
            natsNounString = (char *) NULL;
            returnValue = 1;
            break;
    }

    if ( natsNounString ) {
        rr_writeWorkLine((char *) natsNounString);
        rr_execute_nats_noun_verb_line(natsNounString);
    }

    return(returnValue);
} /* rr_genex_random_nats_noun_verb */


rr_nats_nouns rr_get_random_nats_noun(void) {
    int nounRand = rr_rand_lim(RR_NATS_NOUN_COUNT); 
    rr_nats_nouns returnValue = (rr_nats_nouns) nounRand;

    return(returnValue);
} /* rr_get_random_nats_noun */
