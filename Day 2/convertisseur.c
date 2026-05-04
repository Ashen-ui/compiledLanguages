#include <stdio.h>

int main(void)
{
    int choice;
    double value;
    double result;

    printf("=== Universal Converter ===\n");
    printf("1. Km -> Mile\n");
    printf("2. Kg -> Pound\n");
    printf("3. C -> F\n");
    printf("4. Quit\n");
    printf("Your Choice: ");
    scanf("%d", &choice);

    if (choice == 4)
    {
        printf("Buh Bye\n");
        return 0;
    }

    if (choice == 1 || choice == 2 || choice == 3)
    {
        printf("Value to Convert: ");
        scanf("%lf", &value);

        if (choice == 1)
            result = value * 0.621371;
        else if (choice == 2)
            result = value * 2.20462;
        else
            result = value * 9.0 / 5.0 + 32.0;

        printf("Result: %.2f\n", result);
    }
    else
    {
        printf("Choose a correct value ya Nonce\n");
        return 1;
    }

    return 0;
}
