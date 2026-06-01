#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int main(void) {
    int n = 0;
    printf("how many integers do you want to stock ?: ");
    scanf("\n%d", &n);
    
    int *table = (int *) malloc(n * sizeof(int));
    if (table == NULL) {
        printf("error");
        return 1;
    }
    printf("you're going to choose each integer one by one\n");
    int n1 = 0;
    int sum = 0;
    int average = 0;
    int counter = 0;
    for (int i = 0; i < n; i++){
        printf("choose an integer: \n");
        scanf("\n%d", &n1);
        printf("Place %d : %d\n", i, n1);
        table[i] += n1;
        sum += table[i];
        average += table[i];
        counter += 1;
        printf("Integer Registered!\n");
    }

    printf("The sum is : %d\n", sum);
    printf("The average is : %d\n", average/counter);

    free(table);
    return 0;
}