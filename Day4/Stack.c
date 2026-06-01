#include <stdio.h>
void afficher(void) {
    int a = 10;
    int b = 20;
    int c = 30;
    printf("a : valeur=%d, adresse=%p\n", a, (void*)&a);
    printf("b : valeur=%d, adresse=%p\n", b, (void*)&b);
    printf("c : valeur=%d, adresse=%p\n", c, (void*)&c);
    // a, b, c sont detruites automatiquement a la sortie de l
}
int main(void) {
    afficher();
    afficher();   // les adresses peuvent etre reutilisees !
    return 0;
}