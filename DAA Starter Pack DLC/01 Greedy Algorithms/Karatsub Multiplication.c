#include <stdio.h>
#include <math.h>

// WORKING VERSION

int getLength(long long value) {
    int counter = 0;
    while (value != 0) {
        counter++;
        value /= 10;
    }
    return counter;
}

long long multiply(long long x, long long y) {
    int xLength = getLength(x);
    int yLength = getLength(y);
    int N = (int)(fmax(xLength, yLength));
    if (N < 10)
        return x * y;
    N = (N / 2) + (N % 2);

    long long multiplier = (long long)pow(10, N);

    long long b = x / multiplier;
    long long a = x - (b * multiplier);
    long long d = y / multiplier;
    long long c = y - (d * multiplier);

    long long z0 = multiply(a, c);
    long long z1 = multiply(a + b, c + d);
    long long z2 = multiply(b, d);

    return z0 + ((z1 - z0 - z2) * multiplier) + (z2 * (long long)(pow(10, 2 * N)));
}

int main() {
    long long a = 6789;
    long long b = 6969;
    // result should be 7006652

    printf("\n\nResult of %lld x %lld = %lld\n\n", a,b,multiply(a, b));

    return 0;
}
