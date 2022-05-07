#include "rr_logging.h"

void rr_null_buffer(void) {
    memset(rr_log_line_buffer,0,RR_LINE_BUFFER_SIZE);
}

int rr_writeWorkLine(char * line) {
    int returnValue =  0;

    rr_null_buffer();


    return(returnValue);
}

int rr_writeErrorLine(char * line) {
    int returnValue =  0;

    rr_null_buffer();

    return(returnValue);
}

int rr_writeOutputLine(char * line) {
    int returnValue =  0;

    rr_null_buffer();


    return(returnValue);
}
