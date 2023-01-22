#include <stdbool.h>

int gcd(int a, int b) {
    return (b > a) ? gcd(b,a) : (a % b == 0) ? b : gcd(b, a % b);
}

int gcdExtended(int a, int b, int *x, int *y) {

    //base case
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of
    // recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;

}

bool isPrime(int numInQuestion) {
    for (int i = 2; i < numInQuestion; i++) {
        if (!(numInQuestion % i))
            return false;
    }

    return true;
}

int eulersTotient(int a, int b) {
    if (b > a)
        return eulersTotient(b, a);

    int largest = 1;

    for (int i = 2; i <= b; i++) {
        largest = (!(a % i) && !(b % i)) ? i : largest;
    }
    return largest;

}


void relativelyPrimeIntegers(int a, int b) {
    if (b > a) {
        relativelyPrimeIntegers(b,a);
        return;
    }

    for (int i = 1; i <= b; i++)
        if (!(a % i || b % i))
            printf("%d, ", i);

    printf("\n");
}
