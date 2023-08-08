#include <stdio.h>
#include <stdlib.h>

typedef char Item;
typedef struct node {
    Item item;
    struct node *prev;
} Node;
typedef struct stack {
    Node *top;
    int size;
} Stack;
static void InitializeStack(Stack *ps);
static int StackSize(const Stack *ps);
static int StackPush(Stack *ps, Item item);
static int StackPop(Stack *ps, Item *pitem);



void ch17_ex05(void) {
    Stack stack;
    char ch;

    InitializeStack(&stack);
    puts("Enter a string:");
    while ((ch = (char) getchar()) != '\n' && ch != EOF) {
        if (StackPush(&stack, ch) == 0) {
            printf("Error: Stack is full\n");
            exit(EXIT_FAILURE);
        }
    }
    puts("Reversed string:");
    while (StackSize(&stack) > 0) {
        StackPop(&stack, &ch);
        putchar(ch);
    }
    putchar('\n');
}


// stack functions

static void InitializeStack(Stack *ps) {
    ps->top = NULL;
    ps->size = 0;
}

static int StackSize(const Stack *ps) {
    return ps->size;
}

static int StackPush(Stack *ps, Item item) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed in StackPush()\n");
        return 0;
    }
    new_node->item = item;
    new_node->prev = ps->top;
    ps->top = new_node;
    ps->size++;
    return 1;
}

static int StackPop(Stack *ps, Item *pitem) {
    Node *temp;

    if (ps->top == NULL) {
        fprintf(stderr, "Error: stack is empty in StackPop()\n");
        return 0;
    }
    *pitem = ps->top->item;
    temp = ps->top;
    ps->top = ps->top->prev;
    free(temp);
    ps->size--;
    return 1;
}