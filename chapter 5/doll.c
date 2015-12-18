#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dollFunctions.h"

int main() {
    
    doll *matron = malloc(sizeof(doll));
    doll *mother = malloc(sizeof(doll));
    doll *daughter = malloc(sizeof(doll));
    doll *baby = malloc(sizeof(doll));
    
    matron->size = 4;
    mother->size = 3;
    daughter->size = 2;
    baby->size = 1;

    strcpy(matron->name, "matron");
    strcpy(mother->name, "mother");
    strcpy(daughter->name, "daughter");
    strcpy(baby->name, "baby");

    baby->contains = NULL;
    
    nestDolls(daughter, baby);
    nestDolls(mother, daughter);
    nestDolls(matron, mother);

    printDolls(matron);
    openDoll(matron);
    printDolls(matron);
    printDolls(mother);

    return 0;
}