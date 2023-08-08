#include <stdio.h>


void ch07_ex07(void) {
    int worked_hours;
    double gross_pay;
    double tax_amount;
    const int PAY_RATE = 10;
    const double TAX_1 = 0.15;
    const double TAX_2 = 0.20;
    const double TAX_3 = 0.25;

    printf("Enter work hours:\n");
    scanf("%d", &worked_hours);

    if (worked_hours > 40) {
        gross_pay = (double) (40 * PAY_RATE) + (double) (worked_hours - 40) * 1.5 * PAY_RATE;
    } else {
        gross_pay = (double) (worked_hours * PAY_RATE);
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
