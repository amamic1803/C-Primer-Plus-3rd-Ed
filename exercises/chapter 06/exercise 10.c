#include <math.h>
#include <stdio.h>


void ch06_ex10(void) {
    int limit;
    int i;
    double current_val;

    printf("Enter limit:\n");
    scanf("%d", &limit);

    printf("Series 1:\n\nIteration   Value\n");
    for (i = 1, current_val = 0.0; i <= limit; i++) {
        current_val += 1.0 / (double) i;
        printf("%5d    %8.5lf\n", i, current_val);
    }

    printf("\n\n\n");

    printf("Series 2:\n\nIteration   Value\n");
    for (i = 1, current_val = 0.0; i <= limit; i++) {
        current_val -= pow(-1.0, i) / (double) i;
        printf("%5d    %8.5lf\n", i, current_val);
    }

    // series 1 does not appear to be converging
    // series 2 appears to be converging
}
