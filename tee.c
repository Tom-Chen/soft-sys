#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {

    int fileAppend = 0;
    char ch;
    FILE *teeFiles[128];
    
    while ((ch = getopt(argc, argv, "ai")) != EOF) // get our options
        switch(ch) {
            case 'a':
                fileAppend = 1;
            default:
                fprintf(stderr, "Unknown option: %s\n", optarg);
        }

    argc -= optind;
    argv += optind;

    if (argc < 2) {
        printf("Need an input file and an output file.");
        exit(0);
    }

    int i, j; // variables for counting the file arguments 
    for (i = 1; argv[i] != NULL && i < argc; i++) {
        if (fileAppend == 1) {
            teeFiles[i] = fopen(argv[i], "a");
        }
        else {
            teeFiles[i] = fopen(argv[i], "w");
        }
    }
    i--; // Put the value of i back under argc.

    char inputLine[4096];
    while (fscanf(stdin, "%s", &inputLine)) {
        fprintf(stdout, "%s\n", inputLine);
        for (j = 1; j < i; j++) {
            fprintf(teeFiles[j], "%s\n", inputLine);
        }
    }

    return 0;
}