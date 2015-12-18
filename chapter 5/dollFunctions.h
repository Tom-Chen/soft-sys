typedef struct doll {
        int size;
        struct doll *contains;
        char name[9];
    } doll;

void openDoll(struct doll *d);

void nestDolls(struct doll *d1, struct doll *d2);

void printDolls(struct doll *d);