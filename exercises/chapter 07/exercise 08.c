#include <stdio.h>


void ch07_ex08(void) {
    int worked_hours;
    double gross_pay;
    double tax_amount;
    double pay_rate;
    const double TAX_1 = 0.15;
    const double TAX_2 = 0.20;
    const double TAX_3 = 0.25;
    char input;

    while (1) {
        printf("*****************************************************************\n"
               "Enter the number corresponding to the desired pay rate or action:\n"
               "1) $8.75/hr                              2) $9.33/hr\n"
               "3) $10.00/hr                             4) $11.20/hr\n"
               "5) quit\n"
               "*****************************************************************\n");
        input = (char) getchar();
        while ((char) getchar() != '\n');
        switch(input) {
            case '1' : {
                pay_rate = 8.75;
                break;
            }
            case '2' : {
                pay_rate = 9.33;
                break;
            }
            case '3' : {
                pay_rate = 10.0;
                break;
            }
            case '4' : {
                pay_rate = 11.20;
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

        printf("Enter work hours:\n");
        scanf("%d", &worked_hours);
        while ((char) getchar() != '\n');


        if (worked_hours > 40) {
            gross_pay = (double) (40 * pay_rate) + (double) (worked_hours - 40) * 1.5 * pay_rate;
        } else {
            gross_pay = (double) (worked_hours * pay_rate);
        }

        if (gross_pay <= 300) {
            tax_amount = TAX_1 * gross_pay;
        } else if (gross_pay <= 450) {
            tax_amount = TAX_1 * 300 + (gross_pay - 300) * TAX_2;
        } else {
            tax_amount = TAX_1 * 300 + 150 * TAX_2 + (gross_pay - 450) * TAX_3;
        }

        printf("Gross pay: %.2lf\nTaxes: %.2lf\nNet pay: %.2lf\n", gross_pay, tax_amount, gross_pay - tax_amount);
    }
    out: ;
}
