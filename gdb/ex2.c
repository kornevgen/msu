int digits(int n) {
    int k = 0;
    while (n != 0) {
        n = n << 1;
        k++;
    }
    return k;
}

int magic(int n) {
    int k = digits(n);
    unsigned y = 0;
    while (k != 0) {
        k = k - 2;
        y = y << 2;
        y++;
    }    
    n = n | y;
    return n;
}

#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", magic(n));
}