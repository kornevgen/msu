#include <stdio.h>

int *one(void) {
	int odin = 1;
	int *ret = &odin;
	return ret;
}

int main(void) {
	printf("%d\n", *one());
}
