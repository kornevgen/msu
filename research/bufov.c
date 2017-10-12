#include <stdio.h>

enum {BUF_SIZE = 80};

void read_line(char *);
int main(void) {
    char *buf = malloc(BUF_SIZE);
    read_line(buf);
    puts(buf);
    free(buf);
    return 0;
}

/////////////////////

void read_line(char *buf) {
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
//!!! HOW TO FIND BUFFER OVERFLOW HERE?
        *buf++ = c;
    }
    *buf = 0;
}
