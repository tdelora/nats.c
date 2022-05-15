#include "rr_logging.h"

void rr_null_buffer(void) {
    memset(rr_log_line_buffer,0,RR_LINE_BUFFER_SIZE);
} /* rr_null_buffer */

int rr_writeWorkLine(char * line) {
    int returnValue =  0, size = ( strlen(RR_LOG_WORK_PREPEND) + strlen(line) );

    RR_NULL_BUFFER;

    if ( size < RR_LINE_BUFFER_SIZE) {
        returnValue = sprintf(rr_log_line_buffer,"%s%s\n",RR_LOG_WORK_PREPEND,line);
        RR_WRITE_LINE(stdout,rr_log_line_buffer);
    }
    else {
        fprintf(stderr,"\nrr_writeWorkLine: Received too long log line - Rcvd: %d - Limit: %d\nLine omited\n",
        size,RR_LINE_BUFFER_SIZE);
    }

    return(returnValue);
} /* rr_writeWorkLine */

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
} /* rr_writeErrorLine */

int rr_writeOutputLine(char * line) {
    int returnValue =  0, size = strlen(line);

    RR_NULL_BUFFER;

    if ( size < RR_LINE_BUFFER_SIZE ) {
        returnValue = sprintf(rr_log_line_buffer,"%s",line);
        RR_WRITE_LINE(stderr,rr_log_line_buffer);
    }
    else {
        fprintf(stderr,"\nrr_writeOutputLine: Received too long log line - Rcvd: %d - Limit: %d\nLine omited\n",
        size,RR_LINE_BUFFER_SIZE);
    }

    return(returnValue);
} /* rr_writeOutputLine */


/* rr_logLineCheck checks if line starts with RR_LOG_WORK_PREPEND
   and if so return a char * to the exec part of the line */
char * rr_logLineCheck(char * line) {
    char * cr = strstr(line,RR_LOG_WORK_PREPEND);
    int prependLen = strlen(RR_LOG_WORK_PREPEND);

    if (cr) {
        cr = line + prependLen;
    }

    return(cr);
} /* rr_logLineCheck */
