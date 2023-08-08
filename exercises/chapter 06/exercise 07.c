#include <stdio.h>


void ch06_ex07(void) {
    double fp1, fp2;
    int status;

    printf("Enter q to exit!\nEnter 2 floats: \n");
    status = scanf("%lf %lf", &fp1, &fp2);
    while (status == 2) {
        printf("(%.3lf - %.3lf) / (%.3lf * %.3lf) = %.3lf\n", fp1, fp2, fp1, fp2, (fp1 - fp2) / (fp1 * fp2));
        printf("Enter q to exit!\nEnter 2 floats: \n");
        status = scanf("%lf %lf", &fp1, &fp2);
    }
}
