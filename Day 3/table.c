#include <stdio.h>

int main(void) {
    int n;
    do {
        printf("choose a number n: ");
        scanf("%d", &n);
    } while (n == 0);

    do {
        printf("Please choose a positive number: ");
        scanf("%d", &n);
    } while (n < 0);

    int result[11];
    for (int i = 0; i < 11; i++) {
            result[i] = n * i;
            printf("%d * %d = %d\n", n, i, result[i]);
    }
}