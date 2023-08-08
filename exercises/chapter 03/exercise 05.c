#include <stdio.h>


void ch03_ex05(void) {
    int age;
    double age_in_secs;

    printf("Enter your age:\n");
    scanf("%d", &age);
    age_in_secs = age * 3.156e7;
    printf("You are %.0f seconds old.", age_in_secs);
}