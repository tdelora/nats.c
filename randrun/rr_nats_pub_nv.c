#include "rr_nats_pub_nv.h"

int rr_select_execute_nats_pub_verb(void) {
    int returnValue = 0;
    char * verbLine = "EMPTY_LINE";

    rr_execute_nats_init_verb_line(verbLine);

    return(returnValue);
} /* rr_select_execute_nats_pub_verb */

int rr_execute_nats_pub_verb_line(char * verbLine) {
    int returnValue = 0;
    char nvLine[NV_STR_BUFFER_SIZE];

    /* Write the noun and verb to the log then execute the verbLine */
    sprintf(nvLine,"%s %s",NOUN_NATS_PUB,verbLine);
    rr_writeWorkLine(nvLine);
    fprintf(stdout,"exec: %s\n",verbLine);

    return(returnValue);
} /* rr_execute_nats_pub_verb_line */