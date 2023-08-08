#include <stdio.h>
#include <string.h>


void ch04_ex02(void) {
    char first_name[50];

    printf("Enter your first name:\n");
    scanf("%s", first_name);

    printf("\"%s\"\n", first_name);
    printf("\"%20s\"\n", first_name);
    printf("\"%-20s\"\n", first_name);
    printf("%*s\n", (int) strlen(first_name) + 3, first_name);
}