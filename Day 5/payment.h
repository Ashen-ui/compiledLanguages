#ifndef paymentHeader
#define paymentHeader
#include <stdio.h>

enum {
    descLength = 100,
    catLength = 40,
    dateLength = 11
};

typedef struct {
    char description[descLength];
    double amount;
    char category[catLength];
    char date[dateLength];
} paymentInfo;

typedef struct {
    paymentInfo *Objects;
    size_t counter;
    size_t capacity;
} paymentList;

void initializeList(paymentList *list);
void freeList(paymentList *list);
void displayPayments(const paymentList *list);
void filterByCategory(const paymentList *list, const char *category);
void totalByCategory(const paymentList *list);

int addToList(paymentList *list, paymentInfo info);
int removeFromList(paymentList *list, size_t index);
double listTotal(const paymentList *list);

#endif 