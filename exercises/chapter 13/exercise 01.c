#include <stdio.h>
#define NONUM 0
#define YESNUM 1
static int getarray(int array[], int limit);


void ch13_ex01(void) {
    int array[5];
    int index;
    index = getarray(array, 5);
    printf("The array contains %d elements.\n", index);
    for (int i = 0; i < index; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

static int getarray(int array[], int limit) {
    int num, status;
    int index = 0;
    char ch;

    printf("This program stops reading numbers after %d values or if # is encountered.\n", limit);
    printf("First value:\n");
    status = scanf("%d", &num);
    while (index < limit && status != EOF) {
        if (status == YESNUM) {
            array[index++] = num;
            printf("%d accepted.\n", num);
            if (index < limit) {
                printf("Next value:\n");
                status = scanf("%d", &num);
            }
        } else if (status == NONUM) {
            while ((ch = (char) getchar()) != '\n') {
                if (ch == '#') {
                    goto out;
                }
            }
            printf("That was no integer!\n");
            printf("Enter an integer to continue or non-numeric input to quit:\n");
            if ((status = scanf("%d", &num)) == NONUM) {
                break;
            }
        } else {
            printf("Oops! Program should never reach here!\n");
            break;
        }
    }
    out:
    if (index == limit) {
        printf("All %d elements of the array were filled.\n", limit);
    }
    return index;
}