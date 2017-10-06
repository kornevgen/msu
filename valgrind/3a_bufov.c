#include <stdlib.h>

int main(void) {
    char *buf = malloc(8);
    buf[8] = 8;
    free(buf);
}
