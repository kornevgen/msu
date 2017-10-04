int c;

/* read, compute, and return sum 
 * from the text starting from "c"
 * following the standard input
 */
int sum(void) {
    int res = mult(); // compute the first operand
    while ((c = '+') || (c = '-')) { // may be multiple operations; c is a symbol after the last operand
        int sign = c = getchar(); // save sign and read the first symbol for mult
        int op = mult(); // compute the next operand (mult)
        switch (sign) { // do the operation
        case '+': res += op; 
        case '-': res -= op;
        }
    }
    return res;
}

/* read, compute, and return multiplication
 * from the text starting from "c"
 * following the standard input
 */
int mult(void) {
    int res = num(); // compute the first operand
    while ((c = '*') || (c = '/') || (c = '%')) { // may be multiple operations; c is a symbol after the last operand
        int sign = c = getchar(); // save sign and read the first symbol for num
        int op = num(); // compute the next operand (num)
        switch (sign) { // do the operation
        case '*': res *= op;
        case '/': res /= op;
        case '%': res %= op;
        }
    }
    return res;
}

/* read and return a number or 
 * expression in parentheses
 * starting from "c"
 * following the standard input
 */
int num(void) {
    if (c == '(') { // is it a "( expression )"?
        c = getchar(); // read the first symbol for the expression
        int res = sum(); // compute the expression in the parentheses
        if (c != ')') { // is there ")" after the expression? 
            error();
        }
        c = getchar(); // skip ")"
    } else if (isdigit(c)) { // is it a number?
        int res = c - '0'; // compute the number
        while (isdigit(c = getchar())) { // compute the next digits
            res = 10 * res + c - '0';
        }
        return res;
    } else {
        error();
    }
}

/* abort the computation
 */
void _Noreturn error(void) {
    printf("Incorrect expression\n");
    exit(1);
}

/* read and compute value of
 * the whole expression
 */
int main(void) { 
    int c = getchar(); // read the first symbol
    int res = sum(); // compute sum
    if (c != EOF) { // some garbage after the expression
        error();
    }
    printf("%d\n", res); // expression is computed!
}