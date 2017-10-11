#include <stdlib.h>

int main(void) {
    char *p = malloc(50);
    p[0] = 'A';
    free(p);
    return 0;
}
