#ifndef RR_LOGGING_
#define RR_LOGGING_

#include <stdio.h>
#include <string.h>

#define RR_LOG_WORK_PREPEND "## RR WORK "
#define RR_LINE_BUFFER_SIZE 2048

char rr_log_line_buffer[RR_LINE_BUFFER_SIZE];

void rr_null_buffer(void);
int rr_writeWorkLine(char * line);
int rr_writeErrorLine(char * line);
int rr_writeOutputLine(char * line);

#endif /* RR_LOGGING_ */
