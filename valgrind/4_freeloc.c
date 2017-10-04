#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char buf[1024];

char *get(void) {
	char *ret = buf;
	strcpy(ret, "Hello world!\n");
	return buf;
}

int main(void) {
	char *s = get();
	puts(s);
	free(s);
}
