#include <stdio.h>

long long fibonacci(long long n) {
    if (n < 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    long long int n = 20;

    printf("fib(%lld) == %lld\n", n, fibonacci(n));

    return 0;
}