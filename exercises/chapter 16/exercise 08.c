#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 10
struct names {
    char first[40];
    char last[40];
};
static void showarray(const struct names *ar, int n);
static int mycomp(const void *p1, const void *p2);


void ch16_ex08(void) {
    struct names vals[NUM] = {
        {"John", "Smith"},
        {"Jane", "Smith"},
        {"John", "Doe"},
        {"Jane", "Doe"},
        {"John", "Jones"},
        {"Jane", "Jones"},
        {"John", "Davis"},
        {"Jane", "Davis"},
        {"John", "Johnson"},
        {"Jane", "Johnson"}
    };

    puts("Random list:");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(struct names), mycomp);
    puts("\nSorted list:");
    showarray(vals, NUM);
}

static void showarray(const struct names *ar, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%s %s\n", ar[i].first, ar[i].last);
}

static int mycomp(const void *p1, const void *p2) {
    const struct names *a1 = (const struct names *) p1;
    const struct names *a2 = (const struct names *) p2;
    int res;

    res = strcmp(a1->last, a2->last);
    if (res != 0)
        return res;
    else
        return strcmp(a1->first, a2->first);
}