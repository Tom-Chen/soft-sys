#include <stdio.h>
#include <stdlib.h>
#include "dollFunctions.h"

void openDoll(doll *d) {
    d->contains = NULL;
}

void nestDolls(doll *d1, doll *d2) {
    if (d1->size > d2->size) {
        d1->contains = d2;
    }
    else {
        printf("The first doll, %s, must be larger than the second doll, %s.\n", d1->name, d2->name);
    }
}

void printDolls(doll *d) {
    if (d->contains != NULL) {
        printf("%s contains %s.\n",d->name, d->contains->name);
        printDolls(d->contains);
    }
    else {
        printf("%s doesn't contain anything.\n", d->name);
    }
}