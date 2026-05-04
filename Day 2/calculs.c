#include <stdio.h>

int main(void) {
	int a = 17;
	int b = 5;
	int addition = a + b;
	int substraction = a-b;
	int multiplication = a*b;
	int division = a/b;
	int mod = a%b;
	printf("sum:%d\n sub:%d\n mult:%d\n div:%d\n mod:%d\n", addition,substraction,multiplication,division,mod);
	printf("float:%.2f\n", (float)a/b);
	return 0;
}
