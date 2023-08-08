#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header 04.h"
#define MIN_PER_HR 60.0
BOOLEAN newcustomer(double x);
Item customertime(long when);


void ch17_ex04(void) {
    Queue line;
    Queue line2;
    Item temp;
    int hours;
    int perhour;
    long cycle, cyclelimit;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    double min_per_cust;
    long line_wait = 0;

    InitializeQueue(&line);
    InitializeQueue(&line2);
    srand((unsigned int) time(0));
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = (long) MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (FullQueue(&line)) {
                if (FullQueue(&line2)) {
                    turnaways++;
                } else {
                    customers++;
                    temp = customertime(cycle);
                    EnQueue(temp, &line2);
                }
            } else {
                customers++;
                temp = customertime(cycle);
                EnQueue(temp, &line);
            }
        }
        if (wait_time <= 0 && (!EmptyQueue(&line) || !EmptyQueue(&line2))) {
            if (!EmptyQueue(&line)) {
                DeQueue(&temp, &line);
            } else {
                DeQueue(&temp, &line2);
            }
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if (wait_time > 0) {
            wait_time--;
        }
        sum_line += QueueItems(&line) + QueueItems(&line2);
    }

    if (customers > 0) {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("         turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f\n", (double) sum_line / cyclelimit);
        printf(" average wait time: %.2f minutes\n", (double) line_wait / served);
    } else {
        puts("No customers!");
    }
}

BOOLEAN newcustomer(double x) {
    if (rand() * x / RAND_MAX < 1) {
        return True;
    } else {
        return False;
    }
}

Item customertime(long when) {
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}


// queue.c -- Queue type implementation

static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

static void InitializeQueue(Queue * pq) {
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

static BOOLEAN FullQueue(const Queue * pq) {
    return pq->items == MAXQUEUE;
}

static BOOLEAN EmptyQueue(const Queue * pq) {
    return pq->items == 0;
}

static int QueueItems(const Queue * pq) {
    return pq->items;
}

static BOOLEAN EnQueue(Item item, Queue * pq) {
    Node * pnew;

    if (FullQueue(pq)) {
        return False;
    }
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL) {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (EmptyQueue(pq)) {
        pq->front = pnew;
    } else {
        pq->rear->next = pnew;
    }
    pq->rear = pnew;
    pq->items++;

    return True;
}

static BOOLEAN DeQueue(Item *pitem, Queue * pq) {
    Node * pt;

    if (EmptyQueue(pq)) {
        return False;
    }
    CopyToItem(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0) {
        pq->rear = NULL;
    }

    return True;
}

static void CopyToNode(Item item, Node * pn) {
    pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi) {
    *pi = pn->item;
}