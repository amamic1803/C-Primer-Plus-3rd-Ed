#include <stdio.h>


void ch04_ex04(void) {
    float height;
    char name[50];

    printf("What is your name?\n");
    scanf("%s", name);
    printf("Enter your height (in inches):\n");
    scanf("%f", &height);

    printf("%s, you are %1.3f feet tall", name, height / 12.0);
}