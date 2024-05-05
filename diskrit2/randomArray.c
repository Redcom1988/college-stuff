#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int len, tempVal = 0;
    printf("insert length: ");
    scanf("%d", &len);
    int numArray[len];

    srand(time(NULL));

    // Generate random numbers and calculate sum
    for (int i = 0; i < len; i++) {
        numArray[i] = (rand() % 10) + 1;
        tempVal += numArray[i];
    }

    // Sort the array using bubble sort
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (numArray[j] > numArray[j + 1]) {
                swap(&numArray[j], &numArray[j + 1]);
            }
        }
    }

    // Print sorted numbers
    printf("Sorted numbers: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", numArray[i]);
    }

    // Calculate and print the average
    int avg = tempVal / len;
    printf("\nAverage: %d\n", avg);
    
    return 0;
}
