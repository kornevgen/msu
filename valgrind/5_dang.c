#include <stdlib.h>

int main(void) {
    char *buf = malloc(10);
    free(buf);
    buf[0] = 0;
}
