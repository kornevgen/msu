#include <stdio.h>

int main(void) {
    int n;
//!!! HOW TO COVER ALL THE FOLLOWING CASES:
//      scanf() returns 1,
//      scanf() returns 0,
//      scanf() returns -1 ... ? <-- THIS IS THE CASE WHEN AN ERROR WILL BE OCCURRED
    if (scanf("%d", &n)) {
        printf("%d\n", n); // BUG
    }
}
