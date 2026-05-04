#include <stdio.h>

int main(void) {
	int age;
	float grade;
	char name[10];

	printf("What is your name ?\n");
	scanf("%10s", name);

	printf("How old are you ?\n");
	scanf("%d", &age);

	printf("What's your average grade ? (floatpoint)\n");
	scanf("%f", &grade);

	printf("Hello %s, you're %d years old and your average grade of %.2f will be used for ai training ! be happy before the end !\n", name, age, grade);
	return 0;
}
