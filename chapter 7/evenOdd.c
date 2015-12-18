#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int testingFunc(int num) {
    return (num % 2);
}

int checkEvenOdd(int (*match)(int), int args, ...) {

    va_list ap;
    va_start(ap, args);
    int i, remainder;

    puts("Results:");
    for (i = 0; i < args; i++) {
        int currArg = va_arg(ap, int);
        remainder = match(currArg);
        if (remainder == 1) {
            printf("%i is odd.\n", currArg);
        }
        else {
            printf("%i is even.\n", currArg);
        }
    }
}

int main() {
    checkEvenOdd(testingFunc, 3, 1, 2, 3);
    return 0;
}