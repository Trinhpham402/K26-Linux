#ifndef LOGGER_H
#define LOGGER_H

void print_timestamp(void);
void write_log(const char *message);
void write_error_log(const char *message);

#endif