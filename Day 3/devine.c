#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showMenu() {
    printf("Difficulty\n");
    printf("1 - Easy\n");
    printf("2 - Medium\n");
    printf("3 - Hard\n");
}

int difficulty(int choice) {
    switch (choice) {
        case 1:
            return 50;
        case 2:
            return 100;
        case 3:
            return 1000;
        default:
            return 100;
    }
}

int gameLoop(int secret) {
    int div = 0;
    int attempt = 0;

    do {
        printf("Your guess ?: ");
        scanf("%d", &div);
        attempt++;

        if (div < secret) {
            puts("Too small!");
        }
        else if (div > secret) {
            puts("Too big!");
        }
    } while (div != secret);
    return attempt;
}

int main() {
    int choice;
    int limit;
    int secret;
    int score;

    srand(time(NULL));
    showMenu();
    printf("Your Choice ?: ");
    scanf("%d", &choice);

    limit = difficulty(choice);
    secret = rand() % limit + 1;
    score = gameLoop(secret);
    
    printf("Chad status in %d attempts.\n", score);
    return 0;
}