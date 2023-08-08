#include <stdio.h>


void ch07_ex05(void) {
    int even_ints = 0, odd_ints = 0;
    double even_avg = 0, odd_avg = 0;
    int input;

    printf("Enter integers (0 stops entering):\n");
    scanf("%d", &input);
    while (input != 0) {
        switch(input % 2) {
            case 0 : {
                even_ints++;
                even_avg += input;
                break;
            }
            case 1 : {
                odd_ints++;
                odd_avg += input;
                break;
            }
        }
        scanf("%d", &input);
    }

    even_avg /= (double) even_ints;
    odd_avg /= (double) odd_ints;

    printf("You entered %d odd and %d even integers.\n"
           "The average of odd integers is %.3lf and the average of even integers is %.3lf.\n",
           odd_ints, even_ints, odd_avg, even_avg);
}
