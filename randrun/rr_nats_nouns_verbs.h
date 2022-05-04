#ifndef RR_NOUNS_VERBS_
#define RR_NOUNS_VERBS_

#include "rr_random.h"

typedef enum { NATS_CONNECTION = 0, NATS_PUBLISHER, NATS_SUBSCRIBER } rr_nats_nouns;
#define RR_NATS_NOUN_COUNT 3 /* Fixme - autocalculate size */

rr_nats_nouns rr_get_randon_nats_noun(void);

#endif /* RR_NOUNS_VERBS_ */