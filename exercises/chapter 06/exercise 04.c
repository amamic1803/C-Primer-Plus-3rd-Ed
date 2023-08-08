#include <stdio.h>


void ch06_ex04(void) {
    char start_char;
    const char alphabet_start = 'A';
    int i, j;
    int height;

    printf("Enter a capital letter:\n");
    scanf("%c", &start_char);

    height = start_char - alphabet_start + 1;
    for (i = 1; i <= height; i++) {
        for (j = 0; j < height - i; j++) {
            printf(" ");
        }
        for (j = 0; j < i; j++) {
            printf("%c", alphabet_start + j);
        }
        for (j = 1; j < i; j++) {
            printf("%c", alphabet_start + i - 1 - j);
        }
        printf("\n");
    }
}
