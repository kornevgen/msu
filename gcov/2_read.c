#include <stdlib.h>
#include <stdio.h>

enum {BUF_SIZE = 80};

void read(char (*buf)[]) {
    if (!*buf) {
        *buf = malloc(BUF_SIZE);
    }
    size_t i = 0;
    int c;
    while ((c = getchar()) != EOF && i < BUF_SIZE) {
        (*buf)[i++] = c;
    }
    (*buf)[i] = 0;
}
