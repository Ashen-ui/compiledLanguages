#include "payment.h"
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

static void addPayment(paymentList *list) {
    paymentInfo info;

    printf("Description : ");
    scanf(" %[^\n]s", info.description);

    printf("Amount      : ");
    scanf("%lf", &info.amount);

    printf("Category    : ");
    scanf("%s", info.category);

    printf("Date (DD/MM/YYYY) : ");
    scanf("%s", info.date);

    if (addToList(list, info)) {
        printf("Payment added to list !\n");
    } else {
        printf("Error: List full, payment not added");
    }
}

int main(void) {
    paymentList list;
    initializeList(&list);
    
    int choice = 0;
    while (choice != 6) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPayments(&list);
                break;
            case 2:
                addPayment(&list);
                break;
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
    freeList(&list);
    return 0;
}