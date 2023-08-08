#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int get_days(char *month);
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


void ch14_ex01(void) {
    int i;

    for (i = 0; i < 12; i++) {
        printf("Days up to and including the month of %s: %d\n", months[i].name, get_days(months[i].abbrev));
    }
}

static int get_days(char *month) {
    int i, j;
    char input_abbrev[4];
    char working_abbrev[4];
    int sum = 0;

    if (strlen(month) != 3) {
        fputs("Invalid month name.\n", stderr);
        exit(EXIT_FAILURE);
    }

    strcpy(input_abbrev, month);
    for (i = 0; i < 3; i++) {
        input_abbrev[i] = (char) tolower(input_abbrev[i]);
    }

    for (i = 0; i < 12; i++) {
        strcpy(working_abbrev, months[i].abbrev);
        for (j = 0; j < 3; j++) {
            working_abbrev[j] = (char) tolower(working_abbrev[j]);
        }
        sum += months[i].days;
        if (strcmp(input_abbrev, working_abbrev) == 0) {
            break;
        }
    }
    return sum;
}