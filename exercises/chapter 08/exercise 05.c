#include <math.h>
#include <stdio.h>


void ch08_ex05(void) {
    int guess = 50;
    char ch;
    double move = 25.0;

    printf("Pick an integer between 1 and 100. I will try to guess it.\n");
    printf("Respond with higher/lower/correct.\n");

    while (1) {
        printf("Uh...is your number %d?\n", guess);
        ch = (char) getchar();
        while ((char) getchar() != '\n');
        switch(ch) {
            case 'h' : {
                guess += (int) round(move);
                move /= 2.0;
                break;
            }
            case 'l' : {
                guess -= (int) round(move);
                move /= 2.0;
                break;
            }
            case 'c' : {
                printf("I knew I could do it!\n");
                goto out;
            }
            default: {
                printf("Please enter valid option!\n");
                continue;
            }
        }
    }
    out: ;
}
