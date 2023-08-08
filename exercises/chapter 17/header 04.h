#ifndef CH17_EX04_H
#define CH17_EX04_H

typedef struct item {
    long arrive;
    int processtime;
} Item;

#define MAXQUEUE 10

typedef enum boolean {False, True} BOOLEAN;

typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef struct queue {
    Node * front;
    Node * rear;
    int items;
} Queue;

static void InitializeQueue(Queue * pq);

static BOOLEAN FullQueue(const Queue * pq);

static BOOLEAN EmptyQueue(const Queue * pq);

static int QueueItems(const Queue * pq);

static BOOLEAN EnQueue(Item item, Queue * pq);

static BOOLEAN DeQueue(Item *pitem, Queue * pq);

#endif