#include <stdio.h>
#include <stdlib.h>

// Insertion Sort!
int main() {

    // Get our array
    int array[10], i;
    fprintf(stderr, "Enter 10 integers.\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
    }

    // Sort each value sequentially using the temp value.
    int j, temp;
    for (i = 1; i < 10; i++) {
        temp = array[i];
        j = i - 1;

        // Shift the array left until we can insert our temp value.
        while ((temp < array[j]) && (j >= 0)) {
            array[j+1] = array[j];
            j--;
        }

        // Insert the temp value at the proper place.
        array[j+1] = temp;
    }
    
    // Print the sorted array.
    for (i = 0; i < 10; i++) {
        printf("%d ", array[i]);
        fprintf(stderr, "%d ", array[i]);
   }
}