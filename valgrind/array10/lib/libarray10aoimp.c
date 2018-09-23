/**
    IMPLEMENTATION OF ARRAY10 with array only in structure.
 */

#include "array10.h"
#include <stdio.h>
#include <stdlib.h>

struct array10_Array {
    int items[10];
};

struct array10_Array *array10_alloc(void) {
    struct array10_Array *a = malloc(sizeof *a);
    a->items[0] = 0;
    return a;
}

int array10_read(struct array10_Array *a) {
    int n, i = 0;
    for (;;) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        if (i == 10) {
            return 1;
        }
        a->items[i++] = n;
    }
    if (i != 10) {
        a->items[i] = 0;
    }
    return 0;
}

int array10_write(struct array10_Array *a) {
    int i = 0;
    while (a->items[i] != 0 && i != 10) {
        printf("%d ", a->items[i++]);
    }
    printf("\n");
    return 0;
}

void array10_dealloc(struct array10_Array *a) {
    free(a);
}
