#include <stdlib.h>

int main(void) {
	char *buf = malloc(8);
	buf[7] = buf[8];
	free(buf);
}
