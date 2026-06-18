#include "payment.h"
#include "save.h"
#include <stdio.h>

static const char *saveFile = "saves/payments.csv";
static void menu(void)
{
    printf("\n===== Payment Manager =====\n");
    printf("1. Show all Payments\n");
    printf("2. Add a Payment\n");
    printf("3. Remove a Payment\n");
    printf("4. Filter by Category\n");
    printf("5. Total by Category\n");
    printf("6. Exit\n");
    printf("Choose an Option : \n");
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

    if (loadPayments(&list, saveFile) == 1) {
        printf("%zu payments loaded from file\n", list.counter);
    } else {
        printf("Couldn't find a save file\n");
    }
    
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
                if (list.counter == 0) {
                    printf("Nothing to remove\n");
                    break;
                }
                displayPayments(&list);
                int num = 0;
                printf("Number to remove : ");
                scanf("%d", &num);
                if (removeFromList(&list, (size_t)(num - 1))) {
                    printf("Payment removed\n");
                } else {
                    printf("Invalid number\n");
                }
                break;
            case 4:
            case 5:
                break;
            case 6:
                if (savePayments(&list, saveFile) == 1) {
                    printf("Saved to %s. Exiting\n", saveFile);
                } else {
                    printf("Couldn't save file\n");
                }
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    freeList(&list);
    return 0;
}