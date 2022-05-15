#ifndef RR_NOUNS_VERBS_
#define RR_NOUNS_VERBS_

#include <stdio.h>
#include <strings.h>
#include "rr_logging.h"
#include "rr_random.h"

typedef enum { NATS_CONNECTION = 0, NATS_PUBLISHER, NATS_SUBSCRIBER } rr_nats_nouns;
#define RR_NATS_NOUN_COUNT 3        /* Fixme - autocalculate size */
#define ERROR_STR_BUFFER_SIZE 512


int rr_check_execute_nats_noun_verb_line(char * line);
int rr_execute_nats_noun_verb_line(char * line);
int rr_genex_random_nats_noun_verb(void);
rr_nats_nouns rr_get_random_nats_noun(void);

#endif /* RR_NOUNS_VERBS_ */
