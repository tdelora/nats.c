#ifndef RR_NOUNS_VERBS_
#define RR_NOUNS_VERBS_

#include <stdio.h>
#include <strings.h>
#include "rr_logging.h"
#include "rr_random.h"
#include "rr_nats_init_nv.h"
#include "rr_nats_connect_nv.h"
#include "rr_nats_pub_nv.h"
#include "rr_nats_sub_nv.h"

#define ERROR_STR_BUFFER_SIZE 512

/* NATS Nouns & Verbs */
typedef enum { NATS_INIT = 0, NATS_CONNECTION, NATS_PUBLISHER, NATS_SUBSCRIBER } rr_nats_nouns;
#define NOUN_NATS_INIT "NATS_INIT"
#define NOUN_NATS_CONN "NATS_CONNECTION"
#define NOUN_NATS_PUB "NATS_PUBLISHER"
#define NOUN_NATS_SUB "NATS_SUBSCRIBER"
#define RR_NATS_NOUN_COUNT 4        /* Fixme - autocalculate size */


int rr_check_execute_nats_noun_verb_line(char * line);
int rr_execute_nats_noun_verb_line(char * line);
int rr_genex_random_nats_noun_verb(void);
rr_nats_nouns rr_get_random_nats_noun(void);

#endif /* RR_NOUNS_VERBS_ */
