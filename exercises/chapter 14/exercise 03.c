#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
static char * gets_custom(char *s, int max_len);
static void sort_by_title(struct book **libry_ptrs, int count);


void ch14_ex03(void) {
    struct book libry[MAXBKS];
    struct book *libry_ptrs[MAXBKS];
    int count = 0;
    int index;
    float total = 0;

    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && gets_custom(libry[count].title, MAXTITL) != NULL && libry[count].title[0] != '\0') {
        printf("Now enter the author.\n");
        gets_custom(libry[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &libry[count++].value);
        while (getchar() != '\n');
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    for (index = 0; index < count; index++)
        libry_ptrs[index] = &libry[index];

    sort_by_title(libry_ptrs, count);

    for (index = 0; index < count; index++)
        total += libry_ptrs[index]->value;

    printf("Here is the list of your books:\n");
    for (index = 0; index < count; index++)
        printf("%s by %s: $%.2f\n", (*libry_ptrs[index]).title, (*libry_ptrs[index]).author, (*libry_ptrs[index]).value);
    printf("\nThe total value of your books is $%.2f.\n", total);
}

static char * gets_custom(char *s, int max_len) {
    char c;
    char *initial = s;
    int i = 0;

    while ((c = (char) getchar()) != '\n' && c != EOF && i < max_len - 1) {
        *s++ = c;
        i++;
    }
    *s = '\0';

    if (initial == s && c != '\n')
        return NULL;
    else
        return initial;
}

static void sort_by_title(struct book **libry_ptrs, int count) {
    int i, j;
    struct book *temp;

    for (i = 0; i < count - 1; i++)
        for (j = i + 1; j < count; j++)
            if (strcmp(libry_ptrs[i]->title, (*libry_ptrs[j]).title) > 0) {
                temp = libry_ptrs[i];
                libry_ptrs[i] = libry_ptrs[j];
                libry_ptrs[j] = temp;
            }
}
