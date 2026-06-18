#include "save.h"
#include <stdio.h>

int loadPayments(paymentList *list, const char *path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return 0;
    }
    paymentInfo info;

    while (fscanf(file, "%[^;];%lf;%[^;];%s\n", info.description, &info.amount, info.category,info.date) == 4) {
        addToList(list, info);
    }
    fclose(file);
    return 1;
}

int savePayments(const paymentList *list, const char *path) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        return 0;
    }

    for (size_t i = 0; i < list->counter; i++) {
        fprintf(file, "%s;%.2f;%s;%s\n",
        list->Objects[i].description,
        list->Objects[i].amount,
        list->Objects[i].category,
        list->Objects[i].date);
    }
    fclose(file);
    return 1;
}