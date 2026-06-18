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
    list->counter += 1;
    return 1;
}

int removeFromList(paymentList *list, size_t index) {
    if (index >= list->counter) {
        return 0;
    }
    for (size_t i = index; i+1 < list->counter; i++) {
        list->Objects[i] = list->Objects[i+1];
    }
    list->counter = list->counter - 1;
    return 1;
}

double listTotal(const paymentList *list) {
    double total = 0.0;
    for (size_t i = 0; i < list->counter; i++) {
        total += list->Objects[i].amount;
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

static int caseFilter(const char *case1, const char *case2) {
    int i = 0;
    while (case1[i] != '\0' && case2[i] != '\0') {
        char f1 = case1[i];
        char f2 = case2[i];

        if (f1 >= 'A' && f1 <= 'Z') {
            f1 += 32;
        }
        if (f2 >= 'A' && f2 <= 'Z') {
            f2 += 32;
        }
        if (f1 != f2) {
            return 0;
        }
        i++;
    }
    return case1[i] == case2[i];
}

void filterByCategory(const paymentList *list, const char *category) {
    int found = 0;
    double total = 0.0;

    for (size_t  i= 0; i < list->counter; i++) {
        if (caseFilter(list->Objects[i].category, category)) {
            printf("%zu. %s | %.2f | %s | %s\n", i+1,
            list->Objects[i].description,
            list->Objects[i].amount,
            list->Objects[i].category,
            list->Objects[i].date);
            total += list->Objects[i].amount;
            found++;
        }
    }

    if (found == 0) {
        printf("No payments found for \"%s\".\n", category);
    } else {
        printf("Total for \"%s\": %.2f (%d payments)\n", category, total, found);
    }
}

void totalByCategory(const paymentList *list) {
    if (list->counter == 0) {
        printf("No payments yet\n");
        return;
    }
    int *counted = calloc(list->counter, sizeof(int));
    if (counted == NULL) {
        printf("memory error\n");
        return;
    }
    printf("----- Total By Category -----\n");
    for (size_t i = 0; i < list->counter; i++) {
        if (counted[i] != 0) {
            continue;
        }

        double total = list->Objects[i].amount;
        counted[i] = 1;

        for (size_t j = i+1; j < list->counter; j++) {
            if (!counted[j] && caseFilter(list->Objects[j].category, list->Objects[i].category)) {
                total += list->Objects[j].amount;
                counted[j] = 1;
            }
        }
        printf("  %-15s : %.2f\n", list->Objects[i].category, total);
    }
    printf("  %-15s : %.2f\n", "Grand Total", listTotal(list));
    free(counted);
}