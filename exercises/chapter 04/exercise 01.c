#include <stdio.h>


void ch04_ex01(void) {
    char first_name[50];
    char last_name[50];

    printf("Enter your first name:\n");
    scanf("%s", first_name);
    printf("Enter you last name:\n");
    scanf("%s", last_name);

    printf("Hi: %s, %s", last_name, first_name);
}