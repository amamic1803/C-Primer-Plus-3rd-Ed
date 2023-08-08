#include <stdio.h>


void ch07_ex10(void) {
    double tax;
    double income;
    double limit;
    const double TAX = 0.15;
    const double TAX_EX = 0.28;
    const int LIMIT1 = 17850;
    const int LIMIT2 = 23900;
    const int LIMIT3 = 29750;
    const int LIMIT4 = 14875;

    char input;

    while (1) {
        printf("*******************************\n"
               "Category:\n"
               "1) Single\n"
               "2) Head of Household\n"
               "3) Married, Joint\n"
               "4) Married, Separate\n"
               "5) quit\n"
               "*******************************\n");
        input = (char) getchar();
        while ((char) getchar() != '\n');
        switch(input) {
            case '1' : {
                limit = LIMIT1;
                break;
            }
            case '2' : {
                limit = LIMIT2;
                break;
            }
            case '3' : {
                limit = LIMIT3;
                break;
            }
            case '4' : {
                limit = LIMIT4;
                break;
            }
            case '5' : {
                goto out;
            }
            default: {
                printf("Please enter valid option!\n");
                continue;
            }
        }

        printf("Enter taxable income:\n$");
        scanf("%lf", &income);
        while ((char) getchar() != '\n');


        if (income > limit) {
            tax = TAX * limit + (income - limit) * TAX_EX;
        } else {
            tax = TAX * income;
        }

        printf("Total tax is: $%.2lf\n", tax);
    }
    out: ;
}
