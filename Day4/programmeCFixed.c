#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const char *name = "Alexandre";
    char *nom = (char *) malloc(strlen(name) + 1);
    if (nom == NULL) {
	    return 1;
	}
    strcpy(nom, name);
    printf("%s\n", nom);
    free(nom);
    return 0;
}