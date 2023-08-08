#include <stdio.h>


void ch07_ex09(void) {
    int input_int;
    int num;
    int i;
    int prime_flag;

    printf("Enter integer:\n");
    scanf("%d", &input_int);

    if (input_int >= 2) {
        printf("Primes smaller than or equal to %d are:", input_int);
        for (num = 2; num <= input_int; num++) {
            prime_flag = 1;
            for (i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    prime_flag = 0;
                    break;
                }
            }
            if (prime_flag) {
                printf(" %d", num);
            }
        }
        printf("\n");
    } else {
        printf("There are no primes smaller than %d.", input_int);
    }
}
