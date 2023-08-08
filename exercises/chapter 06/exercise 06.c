#include <stdio.h>
#include <string.h>


void ch06_ex06(void) {
    char word[50];
    int i;

    printf("Enter a word:\n");
    scanf("%s", word);

    for (i = (int) strlen(word) - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    printf("\n");
}
