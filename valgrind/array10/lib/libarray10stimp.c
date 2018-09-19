/**
    IMPLEMENTATION OF ARRAY10 with array in structure.
 */

#include "array10.h"
#include <stdio.h>
#include <stdlib.h>

struct array10_Array {
    int size;
    int items[10];
};

int array10_read(struct array10_Array *a) {
    int n;
    for (;;) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        a->items[a->size++] = n;
    }
    return 0;
}

int array10_write(struct array10_Array *a) {
    for (int i = 0; i < a->size; ++i) {
        printf("%d ", a->items[i]);
    }
    printf("\n");
    return 0;
}

void array10_dealloc(struct array10_Array *a) {
    free(a);
}
