#ifndef CH17_EX03_H
#define CH17_EX03_H

#define TSIZE 45
struct film {
    char title[TSIZE];
    int rating;
};

typedef struct film Item;
typedef enum boolean {False, True} BOOLEAN;

#define MAXSIZE 100
typedef struct list {
    Item entries[MAXSIZE];
    int items;
} List;

static void InitializeList(List *plist);

static BOOLEAN EmptyList(const List *plist);

static BOOLEAN FullList(const List *plist);

static unsigned int ListItems(const List *plist);

static BOOLEAN AddItem(Item item, List *plist);

static void Traverse(List *plist, void (* pfun)(Item item));

#endif