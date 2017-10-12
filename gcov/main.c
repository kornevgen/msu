#include <stdio.h>
#include <stdlib.h>

enum {BUF_SIZE = 80};
void read(char *);
int main(void) {
    char *buf = malloc(BUF_SIZE);
    read(buf);
    puts(buf);
    free(buf);
    return 0;
}
