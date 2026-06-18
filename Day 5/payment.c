#include "payment.h"
#include <stdio.h>
#include <stdlib.h>

static const int startCap = 10;

void initializeList(paymentList *list) {
    list->Objects = NULL;
    list->counter = 0;
    list->capacity = 0;
}

void freeList(paymentList *list) {
    free(list->Objects);
    list->Objects = NULL;
    list->counter = 0;
    list->capacity = 0;
}

static int capacity(paymentList *list) {
    if (list->counter < list->capacity) {
        return 1;
    }
    
    size_t newCap = 0;
    if (list->capacity == 0) {
        newCap = startCap;
    } else {
        newCap = list->capacity * 2;
    }

    paymentInfo *ref = realloc(list->Objects, newCap * sizeof(paymentInfo));
    if (ref == NULL) {
        return 0;
    }

    list->Objects = ref;
    list->capacity = newCap;
    return 1;
}

int addToList(paymentList *list, paymentInfo info) {
    if (capacity(list) == 0) {
        return 0;
    }

    list->Objects[list->counter] = info;
    list->counter = list->counter + 1;
    return 1;
}

double listTotal(const paymentList *list) {
    double total = 0.0;
    for (size_t i = 0; i < list->counter; i++) {
        total = total + list->Objects[i].amount;
    }
    return total;
}

void displayPayments(const paymentList *list) {
    if (list->counter == 0) {
        printf("No payments yet\n");
        return;
    }

    for (size_t i = 0; i < list->counter; i++) {
        printf("%zu. %s | %.2f | %s | %s\n",
                i+1,
                list->Objects[i].description,
                list->Objects[i].amount,
                list->Objects[i].category,
                list->Objects[i].date);
    }

    double finalAmount = listTotal(list);
    printf("Total : %.2f\n", finalAmount);
}