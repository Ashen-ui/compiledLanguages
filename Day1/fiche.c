#include <stdio.h>

int main(void) {
	char name[] = "Luka";
	int age = 21;
	float height = 1.67;
	char initial = 'L';
	printf("+-------------------------------+\n");
	printf("|     FICHE D'IDENTITE          |\n");
	printf("+-------------------------------+\n");
	printf("| Prenom  : %s                |\n", name);
	printf("| Age     : %d                  |\n", age);
	printf("| Taille  : %.2f m              |\n", height);
	printf("| Initiale: %c                   |\n", initial);
	printf("+-------------------------------+\n");
	printf("| Code de sortie : 0 (succes)   |\n");
	printf("+-------------------------------+\n");
	return 0;
}
