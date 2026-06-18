#ifndef saveHandler
#define saveHandler
#include "payment.h"

int loadPayments(paymentList *list, const char *path);
int savePayments(const paymentList *list, const char *path);

#endif