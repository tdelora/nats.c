#ifndef RR_LOGGING_
#define RR_LOGGING_

#include <stdio.h>
#include <string.h>

#define RR_LOG_WORK_PREPEND "### RR_WORK "
#define RR_LINE_BUFFER_SIZE 2048

char rr_log_line_buffer[RR_LINE_BUFFER_SIZE];

#define RR_NULL_BUFFER memset(rr_log_line_buffer,0,RR_LINE_BUFFER_SIZE)
#define RR_WRITE_LINE(STREAM,LINE)  fprintf(STREAM,"%s",LINE)

int rr_writeWorkLine(char * line);
int rr_writeErrorLine(char * line);
int rr_writeOutputLine(char * line);
char * rr_logLineCheck(char * line);

#endif /* RR_LOGGING_ */
