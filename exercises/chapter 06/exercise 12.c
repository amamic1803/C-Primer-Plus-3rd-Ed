#include <stdio.h>


void ch06_ex12(void) {
    char line[50];
    int i;
    char current_char;

    printf("Enter text:\n");
    scanf("%c", &current_char);
    i = 0;

    while (current_char != '\n') {
        line[i] = current_char;
        i++;
        scanf("%c", &current_char);
    }
    i--;
    printf("Reverse text:\n");
    for ( ; i >= 0; i--) {
        printf("%c", line[i]);
    }
    printf("\n");
}
