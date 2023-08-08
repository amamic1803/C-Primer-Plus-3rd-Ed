#include <stdio.h>
#include <string.h>

void ch04_ex05(void) {
    char first_name[50];
    char last_name[50];

    printf("Enter your first name:\n");
    scanf("%s", first_name);
    printf("Enter your last name:\n");
    scanf("%s", last_name);

    printf("%s %s\n", first_name, last_name);
    printf("%*d %*d\n",
           (int) strlen(first_name),
           (int) strlen(first_name),
           (int) strlen(last_name),
           (int) strlen(last_name));
    printf("%s %s\n", first_name, last_name);
    printf("%-*d %-*d\n",
           (int) strlen(first_name),
           (int) strlen(first_name),
           (int) strlen(last_name),
           (int) strlen(last_name));
}