#include <stdio.h>

// Question - https://www.geeksforgeeks.org/sort-even-numbers-ascending-order-sort-odd-numbers-descending-order/?ref=rp


int main (void) {
    int array[] = {1, 2, 3, 5, 4, 7, 10};
    int arraySize = sizeof(array)/sizeof(int);

    // Determine how many odd and even elements in array
    int oddArraySize = 0;
    int evenArraySize = 0;

    for (int i = 0; i < arraySize; i++) {
        if (array[i] % 2 == 0) {
            evenArraySize++;
        } else {
            oddArraySize++;
        }
    }

    // Appending odd and even elements to their respective arrays
    int oddArray[oddArraySize];
    int oddIndex = 0;
    int evenArray[evenArraySize];
    int evenIndex = 0;

    for (int i = 0; i < arraySize; i++) {
        if (array[i] % 2 == 0) {
            evenArray[evenIndex] = array[i];
            evenIndex++;
        } else {
            oddArray[oddIndex] = array[i];
            oddIndex++;
        }
    }

    // Sort even in ascending order using bubble sort
    for (int i = 0; i < evenIndex; i++) {
        for (int j = i + 1; j < evenIndex; j++) {
            if (evenArray[j] < evenArray[i]) {
                int temp = evenArray[j];
                evenArray[j] = evenArray[i];
                evenArray[i] = temp;
            }
        }
    }

    // Sort odd in descending order using bubble sort
    for (int i = 0; i < oddIndex; i++) {
        for (int j = i + 1; j < oddIndex; j++) {
            if (oddArray[j] > oddArray[i]) {
                int temp = oddArray[i];
                oddArray[i] = oddArray[j];
                oddArray[j] = temp;
            }
        }
    }

    // Append array
    int updatedArray[arraySize];
    int tempIndex = 0;

    for (int i = 0; i < arraySize; i++) {
        if (i <= evenIndex - 1) {
            updatedArray[i] = evenArray[i];
        } else {
            updatedArray[i] = oddArray[tempIndex];
            tempIndex++;
        }
    }

    for (int i = 0; i < arraySize; i++) {
        printf("%d\n", updatedArray[i]);
    }
}