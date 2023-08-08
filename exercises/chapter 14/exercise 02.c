#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct month_info {
    char name[10];
    char abbrev[4];
    int days;
    int month_num;
};
static struct month_info months[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};


void ch14_ex02(void) {
    int day, year;
    char month[10];
    int i, j;
    char *p;
    int sum = 0;

    printf("Enter day:\n");
    if (scanf("%d", &day) != 1) {
        printf("Invalid input.\n");
        exit(EXIT_FAILURE);
    }
    while (getchar() != '\n');

    printf("Enter month:\n");
    fgets(month, 10, stdin);
    if (month[strlen(month) - 1] == '\n')
        month[strlen(month) - 1] = '\0';
    p = month;
    while (*p != '\0') {
        *p = tolower(*p);
        p++;
    }
    month[0] = toupper(month[0]);

    printf("Enter year:\n");
    if (scanf("%d", &year) != 1) {
        printf("Invalid input.\n");
        exit(EXIT_FAILURE);
    }
    while (getchar() != '\n');

    for (i = 0; i < 12; i++) {
        if (strcmp(month, months[i].name) == 0 || strcmp(month, months[i].abbrev) == 0 || strtol(month, NULL, 10) == months[i].month_num)
            break;
    }

    if (i == 12) {
        printf("Invalid input.\n");
        exit(EXIT_FAILURE);
    }

    for (j = 0; j < i; j++)
        sum += months[j].days;
    sum += day;

    printf("Days since the beginning of the year: %d\n", sum);
}