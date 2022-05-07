#include "rr_logging.h"

void rr_null_buffer(void) {
    memset(rr_log_line_buffer,0,RR_LINE_BUFFER_SIZE);
}

int rr_writeWorkLine(char * line) {
    int returnValue =  0, size = ( strlen(RR_LOG_WORK_PREPEND) + strlen(line) );

    RR_NULL_BUFFER;

    if ( size < RR_LINE_BUFFER_SIZE) {
        returnValue = sprintf(rr_log_line_buffer,"%s%s",RR_LOG_WORK_PREPEND,line);
        RR_WRITE_LINE(stdout,rr_log_line_buffer);
    }
    else {
        fprintf(stderr,"\nrr_writeWorkLine: Received too long log line - Rcvd: %d - Limit: %d\nLine omited\n",
        size,RR_LINE_BUFFER_SIZE);
    }

    return(returnValue);
}

int rr_writeErrorLine(char * line) {
    int returnValue =  0, size = strlen(line);

    RR_NULL_BUFFER;

    if ( size < RR_LINE_BUFFER_SIZE ) {
        returnValue = sprintf(rr_log_line_buffer,"%s",line);
        RR_WRITE_LINE(stderr,rr_log_line_buffer);
    }
    else {
        fprintf(stderr,"\nrr_writeErrorLine: Received too long log line - Rcvd: %d - Limit: %d\nLine omited\n",
        size,RR_LINE_BUFFER_SIZE);
    }

    return(returnValue);
}

int rr_writeOutputLine(char * line) {
    int returnValue =  0;

    RR_NULL_BUFFER;


    return(returnValue);
}
