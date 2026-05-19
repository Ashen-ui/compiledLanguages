#include <stdio.h>

void min_max(int array[], int n, int *min, int *max) {
    *min = array[0];
    *max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] < *min){
            *min = array[i];
        }
        if (array[i] > *max){
            *max = array[i];
        }
    }
}

double average(int array[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return (double)sum / n;
}

int main()
{
    int grade[6] = {12, 15, 8, 19, 14, 10};
    int min, max;
    double avg;
    
    min_max(grade, 6, &min, &max);
    avg = average(grade, 6);

    printf("%d\n", min);
    printf("%d\n", max);
    printf("%.2f\n", avg);
    return 0;
}