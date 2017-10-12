#include <stdio.h>
#include <stdlib.h>

void read(char *);
int main(void) {
    char *buf = 0;
    read(&buf);
    puts(buf);
    free(buf);
    return 0;
}
