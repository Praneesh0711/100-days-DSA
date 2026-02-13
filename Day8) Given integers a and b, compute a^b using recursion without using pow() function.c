#include <stdio.h>

// Recursive function to compute a^b
long long power(int a, int b) {
    if (b == 0) {
        return 1; // base case: a^0 = 1
    }
    return a * power(a, b - 1); // recursive step
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    long long result = power(a, b);
    printf("%lld\n", result);

    return 0;
}
