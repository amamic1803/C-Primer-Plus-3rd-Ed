#include <stdio.h>


void ch08_ex03(void) {
    char ch;
    int count_low = 0, count_high = 0;

    printf("Enter text (EOF to quit):\n");

    while ((ch = (char) getchar()) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            count_low++;
        } else if (ch >= 'A' && ch <= 'Z') {
            count_high++;
        }
    }

    printf("There are %d lower case letters and %d upper case letters.\n", count_low, count_high);
}
