int *tab = (int *) malloc(5 * sizeof(int));
for (int i = 0; i < 5; i++) {
    tab[i] = i * 10;
}
free(tab);