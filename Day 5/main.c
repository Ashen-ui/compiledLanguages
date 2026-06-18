#include <stdio.h>
static void menu(void)
{
    printf("\n===== Payment Manager =====\n");
    printf("1. Show all Payments\n");
    printf("2. Add a Payment\n");
    printf("3. Remove a Payment\n");
    printf("4. Filter by Category\n");
    printf("5. Total by Category\n");
    printf("6. Exit\n");
    printf("Choose an Option : ");
}

int main(void)
{
    int choice = 0;
    while (choice != 6) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                break;
            case 6:
                printf("Goodbye !\n");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}