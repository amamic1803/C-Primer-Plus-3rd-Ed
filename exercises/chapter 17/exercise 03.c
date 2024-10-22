#include <stdio.h>
#include <stdlib.h>
#include "header 03.h"
static void showmoview(Item item);
static char * s_gets(char * st, int max);


void ch17_ex03(void) {
    List movies;
    Item temp;

    InitializeList(&movies);
    if (FullList(&movies)) {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n');
        if (!AddItem(temp, &movies)) {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if (FullList(&movies)) {
            fprintf(stderr, "The list is now full.\n");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }
    if (EmptyList(&movies))
        printf("No data entered. ");
    else {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmoview);
    }
    printf("Bye!\n");
}

static void showmoview(Item item) {
    printf("Movie: %s   Rating: %d\n", item.title, item.rating);
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


/* list.c -- functions supporting list operations */

static void InitializeList(List *plist) {
    plist->items = 0;
}

static BOOLEAN EmptyList(const List *plist) {
    return plist->items == 0;
}

static BOOLEAN FullList(const List *plist) {
    return plist->items == MAXSIZE;
}

[[maybe_unused]]
static unsigned int ListItems(const List *plist) {
    return plist->items;
}

static BOOLEAN AddItem(Item item, List *plist) {
    if (plist->items == MAXSIZE) {
        return False;
    } else {
        plist->entries[plist->items++] = item;
        return True;
    }
}

static void Traverse(List *plist, void (* pfun)(Item item)) {
    int i;

    for (i = 0; i < plist->items; i++)
        (*pfun)(plist->entries[i]);
}
