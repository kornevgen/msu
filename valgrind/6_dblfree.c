#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int n = 10;
	char *s = malloc(n);
    if (n > 5) {
        strcpy(s, "AAA");
        puts(s);
        free(s);
    }
	free(s);
}
