#include <stdio.h>
#include <time.h>
#include "logger.h"

static void get_timestamp(char *buffer, int size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}

void print_timestamp(void) {
    char timestamp[32];

    get_timestamp(timestamp, sizeof(timestamp));
    printf("%s\n", timestamp);
}

void write_log(const char *message) {
    FILE *file = fopen("app.log", "a");

    if (file == NULL) {
        printf("Cannot open app.log\n");
        return;
    }

    char timestamp[32];
    get_timestamp(timestamp, sizeof(timestamp));

    fprintf(file, "[%s] %s\n", timestamp, message);

    fclose(file);
}

void write_error_log(const char *message) {
    FILE *file = fopen("app.log", "a");

    if (file == NULL) {
        printf("Cannot open app.log\n");
        return;
    }

    char timestamp[32];
    get_timestamp(timestamp, sizeof(timestamp));

    fprintf(file, "[%s] [ERROR] %s\n", timestamp, message);

    fclose(file);
}