#include <stddef.h>
#include <stdio.h>

int main() {
    int arr[] = {5, 2, 7, 6, 12, -2, 0, 99};
    int sum = 0;
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < 8; i++) {
        sum += arr[i];
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("%d\n", min);
    printf("%d\n", max);
    printf("%d\n", sum);
    printf("%f\n", (float)sum / 8);
    return 0;
}