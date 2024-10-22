#include <stdio.h>
#include <stdlib.h>
#include "header 02.h"
static void showmoview(Item item);
static char * s_gets(char * st, int max);


void ch17_ex02(void) {
    List movies;
    Item temp;

    InitializeList(&movies);
    if (FullList(movies)) {
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
        if (FullList(movies)) {
            fprintf(stderr, "The list is now full.\nIt contains %d movies.\n", ListItems(movies));
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }
    if (EmptyList(movies))
        printf("No data entered. ");
    else {
        printf("Here is the movie list:\n");
        Traverse(movies, showmoview);
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

static void CopyToNode(Item item, Node * pnode);

static void InitializeList(List * plist) {
    plist->head = NULL;
    plist->end = NULL;
}

static BOOLEAN EmptyList(List l) {
    return l.head == NULL;
}

static BOOLEAN FullList(List) {
    Node * pt;
    BOOLEAN full;

    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
        full = True;
    else
        full = False;
    free(pt);
    return full;
}

static unsigned int ListItems(List l) {
    unsigned int count = 0;
    Node * pnode = l.head;

    while (pnode != NULL) {
        ++count;
        pnode = pnode->next;
    }
    return count;
}

static BOOLEAN AddItem(Item item, List * plist) {
    Node * pnew;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return False;
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (plist->head == NULL)
        plist->head = pnew;
    else {
        plist->end->next = pnew;
    }
    plist->end = pnew;
    return True;
}

static void Traverse(List l, void (* pfun)(Item item)) {
    Node * pnode = l.head;

    while (pnode != NULL) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

static void CopyToNode(Item item, Node * pnode) {
    pnode->item = item;
}