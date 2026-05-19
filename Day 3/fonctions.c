#include <stdio.h>
#include <stdlib.h>

int minimum(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int maximum(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int absolute_value(int x) {
    return abs(x);
}

int is_pair(int x) {
    if (x % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

long int factorielle(int n) {
    int fact = 1, i;
    for (i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}



int main(void) {
    printf("%d\n", minimum(2,5));
    printf("%d\n", maximum(2,5));
    printf("%d %d\n", is_pair(21), is_pair(22));
    printf("%ld\n", factorielle(5));
}
