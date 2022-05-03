#include "rr_nouns_verbs.h"

rr_nats_nouns rr_get_randon_nats_noun(void) {
    int nounRand = rr_rand_lim(RR_NATS_NOUN_COUNT); 
    rr_nats_nouns returnValue = (rr_nats_nouns) nounRand;

    return(returnValue);
}
