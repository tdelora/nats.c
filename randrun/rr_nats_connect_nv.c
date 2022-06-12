#include "rr_nats_connect_nv.h"

int rr_select_execute_nats_conn_verb(void) {
    int returnValue = 0;
    char verbLine[NV_STR_BUFFER_SIZE];

    memset(verbLine,0,NV_STR_BUFFER_SIZE);
    sprintf(verbLine,"%s","EMPTY_LINE");

    rr_execute_nats_init_verb_line(verbLine);

    return(returnValue);
} /* rr_select_execute_nats_conn_verb */

int rr_execute_nats_conn_verb_line(char * verbLine) {
    int returnValue = 0;
    char nvLine[NV_STR_BUFFER_SIZE];

    memset(nvLine,0,NV_STR_BUFFER_SIZE);

    /* Write the noun and verb to the log then execute the verbLine */
    sprintf(nvLine,"%s %s",NOUN_NATS_CONN,verbLine);
    rr_writeWorkLine(nvLine);
    fprintf(stdout,"nc exec: %s\n",verbLine);

    return(returnValue);
} /* rr_execute_nats_conn_verb_line */
