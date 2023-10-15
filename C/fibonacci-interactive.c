#include <stdio.h>

long long fibonacci(long long n) {
    long long int prev_prev = 0, prev = 1, current = 1;

    for (int i = 1; i < n; i++) {
        prev_prev = prev;
        prev = current;
        current = prev_prev + prev;
    }

    return current;
}

int main() {
    long long int n = 20;

    printf("fib(%lld) == %lld\n", n, fibonacci(n));

    return 0;
}