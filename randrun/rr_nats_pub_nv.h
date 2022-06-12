#ifndef RR_NATS_PUB_NV_H_
#define RR_NATS_PUB_NV_H_

#include <stdio.h>
#include <string.h>
#include "rr_nats_nouns_verbs.h"

#define NV_STR_BUFFER_SIZE 512

int rr_select_execute_nats_pub_verb(void);
int rr_execute_nats_pub_verb_line(char * verbLine);

#endif /* RR_NATS_PUB_NV_H_ */
