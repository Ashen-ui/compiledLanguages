#include <stdio.h>
#include <stdlib.h>

int* creer_tableau(int n) { 
	int *tableau = (int *) malloc(n * sizeof(int));
	if (tableau == NULL) {
		return NULL;
	}
	for (int i = 0; i < n; i++) {
		tableau[i] = i; 
		return tableau;
	}
int main(void) { 
	int *t = creer_tableau(5); 
	if (t == NULL) {
		return 1;
	}
	printf("%d\n", t[0]);
	free(t);
}