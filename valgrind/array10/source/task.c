#include "array10.h"

void task1(void);
void task2(void);
int main(void) {
    task1();
    task2();
}

void task1(void) {
    struct array10_Array *array;
    array10_read(array);
    array10_write(array);
    array10_dealloc(array);
}

void task2(void) {
    struct array10_Array *array;
    if (array10_read(array) == 0) {
        array10_write(array);
        array10_dealloc(array);
    }
}
