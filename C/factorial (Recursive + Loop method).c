#include <stdio.h>

// For loop
int factorial(int n) {
    int sum = 1;

    for (int i = 1; i <= n; i++) {
        sum *= i;
    }
    return sum;
}

// Recursive
int factorial(int number) {
    if (number == 1) {
        return 1;
    }
    return number * factorial(number - 1);
}

int main(void) {
    printf("%d", factorial(5));
}