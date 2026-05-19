#include <stdio.h>

int main(void) {
    int grade_choice;
    printf("votre note de BAC ?: ");
    scanf("%d", &grade_choice);

    if (grade_choice < 0 || grade_choice > 20) {
        printf("Invalid number please stay in range of 0 to 20\n");
    }
    
    switch(grade_choice){
        case 0 ... 9:
            printf("Rejected\n");
            break;
        case 10 ... 11:
            printf("Admitted\n");
            break; 
        case 12 ... 13:
            printf("Admitted - Good Enough\n");
            break;
        case 14 ... 16:
            printf("Admitted - Good\n");
            break;
        case 17 ... 19:
            printf("Admitted - Really Good\n");
            break;
        case 20:
            printf("Admitted - Perfect\n");
            break;
        default:
            break;
    }
}