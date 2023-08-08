#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
struct film {
    char title[TSIZE];
    int rating;
    struct film * prev;
    struct film * next;
};
static char * s_gets(char * st, int max);


void ch17_ex01(void) {
    struct film * head = NULL;
    struct film * prev, * current;
    char input[TSIZE];

    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL) {
            head = current;
            current->prev = NULL;
        } else {
            prev->next = current;
            current->prev = prev;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n');
        puts("Enter next movie title (empty line to stop):");
        prev = current;
    }
    if (head == NULL)
        printf("No data entered.");
    else {
        printf("Here is the movie list:\n");
        prev = NULL;
        current = head;
        while (current != NULL) {
            printf("Movie: %s   Rating: %d\n", current->title, current->rating);
            prev = current;
            current = current->next;
        }
        printf("\nHere is the movie list in reverse order:\n");
        while (prev != NULL) {
            printf("Movie: %s   Rating: %d\n", prev->title, prev->rating);
            prev = prev->prev;
        }
    }
    printf("Bye!\n");
}

static char * s_gets(char * st, int max) {
    int i = 0;
    char ch;

    while (i < (max - 1) && (ch = (char) getchar()) != '\n' && ch != EOF)
        st[i++] = ch;

    st[i] = '\0';

    if (ch != EOF)
        return st;
    else
        return NULL;
}