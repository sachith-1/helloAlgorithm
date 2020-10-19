#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main (void) {
    int array[5] = {99, 34, 12, 73, 84};
    int counter = 5; // Size of array

    for (int i = 0; i < counter - 1; i++) {
        for (int j = 0; j < counter - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }

    for (int i = 0; i < counter; i++) {
        printf("%d\n", array[i]);
    }
}