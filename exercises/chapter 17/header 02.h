#ifndef CH17_EX02_H
#define CH17_EX02_H

#define TSIZE 45
struct film {
    char title[TSIZE];
    int rating;
};

typedef struct film Item;
typedef enum boolean {False, True} BOOLEAN;
typedef struct node {
    Item item;
    struct node * next;
} Node;
typedef struct list {
    Node * head;
    Node * end;
} List;

static void InitializeList(List * plist);

static BOOLEAN EmptyList(List l);

static BOOLEAN FullList(List l);

static unsigned int ListItems(List l);

static BOOLEAN AddItem(Item item, List * plist);

static void Traverse(List l, void (* pfun)(Item item));

#endif