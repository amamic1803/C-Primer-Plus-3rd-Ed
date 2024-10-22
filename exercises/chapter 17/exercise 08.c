#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 256
#define TRUE 1
#define FALSE 0
static char * s_gets(char * st, int max);
static char * s_gets(char * st, int max) {
    int i = 0;
    char ch;

    while (i < (max - 1) && (ch = (char) getchar()) != '\n' && ch != EOF)
        st[i++] = ch;

    st[i] = '\0';

    return ch != EOF ? st : NULL;
}


// doubly linked list (stores pet kinds and their counts)
typedef char Item_l[MAX_STR_LEN];
typedef struct node_l {
    Item_l item;
    int count;
    struct node_l *prev;
    struct node_l *next;
} Node_l;
typedef struct list {
    Node_l *head;
    Node_l *end;
    int size;
} List;


// binary search tree (stores pet names and doubly linked lists of their kinds)
typedef char Item_t[MAX_STR_LEN];
typedef struct node_t {
    Item_t item;
    List kinds;
    struct node_t *left;
    struct node_t *right;
} Node_t;
typedef struct tree {
    Node_t *root;
    int size;
} Tree;


// doubly linked list functions
static void ListInitialize(List *list);  // initialize a list
static int ListSize(const List *list);  // return number of items in list
static Node_l *ListContains(Item_l item, const List *list);  // return ptr to item if item is in list, NULL otherwise
static int ListAdd(Item_l item, List *list);  // add item to list, return 1 if successful, 0 otherwise
static int ListDelete(Item_l item, List *list);  // delete item from list, return 1 if successful, 0 otherwise
static void TraverseList(const List *list, Item_t item_t, void (*pfun)(Item_t item_t, Item_l item, int count));  // apply pfun to each item in list, passing parent item_t

static void ListInitialize(List *list) {
    list->head = NULL;
    list->end = NULL;
    list->size = 0;
}
static int ListSize(const List *list) {
    return list->size;
}
static Node_l *ListContains(Item_l item, const List *list) {
    Node_l *node;

    for (node = list->head; node != NULL; node = node->next)
        if (strcmp(node->item, item) == 0)
            return node;

    return NULL;
}
static int ListAdd(Item_l item, List *list) {
    Node_l *node;

    if ((node = ListContains(item, list)) != NULL) {
        node->count++;
        return TRUE;
    }

    if ((node = (Node_l *) malloc(sizeof(Node_l))) == NULL)
        return FALSE;
    strcpy(node->item, item);
    node->count = 1;
    node->prev = NULL;
    node->next = NULL;
    if (list->head == NULL)
        list->head = node;
    else {
        list->end->next = node;
        node->prev = list->end;
    }
    list->end = node;
    list->size++;

    return TRUE;
}
static int ListDelete(Item_l item, List *list) {
    Node_l *node;

    if ((node = ListContains(item, list)) == NULL)
        return FALSE;

    if (node->count > 1) {
        node->count--;
        return TRUE;
    }

    if (node == list->head) {
        list->head = node->next;
        if (list->head != NULL)
            list->head->prev = NULL;
    } else {
        node->prev->next = node->next;
        if (node->next != NULL)
            node->next->prev = node->prev;
    }
    if (node == list->end)
        list->end = node->prev;
    free(node);
    list->size--;

    return TRUE;
}
static void TraverseList(const List *list, Item_t item_t, void (*pfun)(Item_t item_t, Item_l item, int count)) {
    Node_l *node;

    for (node = list->head; node != NULL; node = node->next)
        (*pfun)(item_t, node->item, node->count);
}


// binary search tree functions
static void InitializeTree(Tree *tree);  // initialize a tree
static int TreeSize(const Tree *tree);  // return number of items in tree
static Node_t **TreeContains(Item_t item, const Tree *tree);  // return ptr to ptr to item if item is in tree, NULL otherwise
static int TreeAdd(Item_t item_t, Item_l item_l, Tree *tree);  // add item to tree, return 1 if successful, 0 otherwise
static int TreeDelete(Item_t item_t, Item_l item_l, Tree *tree);  // delete item from tree, return 1 if successful, 0 otherwise
static void TraverseTree(const Tree *tree, void (*pfun)(Item_t item_t, Item_l item, int count));  // apply pfun to each item in tree
static void TraverseTreeInternal(Node_t *node, void (*pfun)(Item_t item_t, Item_l item, int count));  // apply pfun to each item in tree

static void InitializeTree(Tree *tree) {
    tree->root = NULL;
    tree->size = 0;
}
static int TreeSize(const Tree *tree) {
    return tree->size;
}
static Node_t **TreeContains(Item_t item, const Tree *tree) {
    Node_t **node;
    int cmp;

    for (node = (Node_t**) &tree->root; *node != NULL; ) {
        cmp = strcmp(item, (*node)->item);
        if (cmp < 0)
            node = &(*node)->left;
        else if (cmp > 0)
            node = &(*node)->right;
        else {
            return node;
        }
    }

    return node;
}
static int TreeAdd(Item_t item_t, Item_l item_l, Tree *tree) {
    Node_t *node;
    Node_t *temp_node;
    int cmp;

    if ((node = *TreeContains(item_t, tree)) != NULL) {
        if (ListAdd(item_l, &node->kinds)) {
            tree->size++;
            return TRUE;
        } else {
            return FALSE;
        }
    }

    if ((node = (Node_t *) malloc(sizeof(Node_t))) == NULL)
        return FALSE;
    strcpy(node->item, item_t);
    ListInitialize(&node->kinds);
    ListAdd(item_l, &node->kinds);
    node->left = NULL;
    node->right = NULL;

    if (tree->root == NULL)
        tree->root = node;
    else {
        for (temp_node = tree->root; ; ) {
            cmp = strcmp(item_t, temp_node->item);
            if (cmp < 0) {
                if (temp_node->left == NULL) {
                    temp_node->left = node;
                    break;
                } else
                    temp_node = temp_node->left;
            } else if (cmp > 0) {
                if (temp_node->right == NULL) {
                    temp_node->right = node;
                    break;
                } else
                    temp_node = temp_node->right;
            } else {
                free(node);
                return FALSE;
            }
        }
    }
    tree->size++;

    return TRUE;
}
static int TreeDelete(Item_t item_t, Item_l item_l, Tree *tree) {
    Node_t *node;
    Node_t **node_addr;
    Node_t *left_node;
    Node_t *right_node;

    if ((node = *(node_addr = TreeContains(item_t, tree))) == NULL)
        return FALSE;

    if (ListDelete(item_l, &node->kinds)) {
        if (ListSize(&node->kinds) > 0) {
            tree->size--;
            return TRUE;
        }
    } else
        return FALSE;

    if (node->left == NULL && node->right == NULL) {
        free(node);
        *node_addr = NULL;
        tree->size--;
        return TRUE;
    } else if (node->left == NULL) {
        *node_addr = node->right;
        free(node);
        tree->size--;
        return TRUE;
    } else if (node->right == NULL) {
        *node_addr = node->left;
        free(node);
        tree->size--;
        return TRUE;
    }

    left_node = node->left;
    right_node = node->right;
    free(node);
    tree->size--;

    *node_addr = left_node;
    for (node = left_node; node->right != NULL; node = node->right);

    node->right = right_node;

    return TRUE;
}
static void TraverseTree(const Tree *tree, void (*pfun)(Item_t item_t, Item_l item, int count)) {
    Node_t *node;

    if ((node = tree->root) == NULL)
        return;
    TraverseTreeInternal(node, pfun);
}
static void TraverseTreeInternal(Node_t *node, void (*pfun)(Item_t item_t, Item_l item, int count)) {
    if (node->left != NULL)
        TraverseTreeInternal(node->left, pfun);
    TraverseList(&node->kinds, node->item, pfun);
    if (node->right != NULL)
        TraverseTreeInternal(node->right, pfun);
}


// core logic
static char menu(void);
static void addpet(Tree *pt);
static void droppet(Tree *pt);
static void showpets(const Tree *pt);
static void findpet(const Tree *pt);
static void printitem(Item_t item_t, Item_l item_l, int count);
static void uppercase(char *str);


void ch17_ex08(void) {
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 'a':
                addpet(&pets);
                putchar('\n');
                break;
            case 'l':
                showpets(&pets);
                putchar('\n');
                break;
            case 'f':
                findpet(&pets);
                putchar('\n');
                break;
            case 'n':
                printf("%d pets in club.\n", TreeSize(&pets));
                putchar('\n');
                break;
            case 'd':
                droppet(&pets);
                putchar('\n');
                break;
            default:
                puts("Switching error");
        }
    }
    puts("Bye.");
}


static char menu(void) {
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    puts("Enter your choice:");
    while ((ch = getchar()) != EOF) {
        while (getchar() != '\n');
        ch = tolower(ch);
        if (strchr("alrfndq", ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if (ch == EOF)
        ch = 'q';

    putchar('\n');

    return (char) ch;
}
static void addpet(Tree *pt) {
    Item_t item_t;
    Item_l item_l;

    puts("Please enter name of pet:");
    s_gets(item_t, MAX_STR_LEN);
    puts("Please enter pet kind:");
    s_gets(item_l, MAX_STR_LEN);

    uppercase(item_t);
    uppercase(item_l);

    if (!TreeAdd(item_t, item_l, pt))
        printf("Couldn't add %s (%s) to club\n", item_t, item_l);
}
static void droppet(Tree *pt) {
    Item_t item_t;
    Item_l item_l;

    puts("Please enter name of pet you wish to delete:");
    s_gets(item_t, MAX_STR_LEN);
    puts("Please enter pet kind:");
    s_gets(item_l, MAX_STR_LEN);

    uppercase(item_t);
    uppercase(item_l);

    if (!TreeDelete(item_t, item_l, pt))
        printf("Couldn't delete %s (%s) from club\n", item_t, item_l);
}
static void showpets(const Tree *pt) {
    if (pt->root == NULL)
        puts("No entries!");
    else
        TraverseTree(pt, printitem);
}
static void findpet(const Tree *pt) {
    Item_t item_t;
    Item_l item_l;
    Node_t *node;

    puts("Please enter name of pet you wish to find:");
    s_gets(item_t, MAX_STR_LEN);
    puts("Please enter pet kind:");
    s_gets(item_l, MAX_STR_LEN);

    uppercase(item_t);
    uppercase(item_l);

    if ((node = *TreeContains(item_t, pt)) == NULL)
        printf("%s the %s is not a member.\n", item_t, item_l);
    else {
        if (ListContains(item_l, &node->kinds) != NULL)
            printf("%s the %s is a member.\n", node->item, item_l);
        else
            printf("%s the %s is not a member.\n", node->item, item_l);
    }
}
static void printitem(Item_t item_t, Item_l item_l, int count) {
    int i;

    for (i = 0; i < count; i++)
        printf("Pet: %-19s  Kind: %-19s\n", item_t, item_l);
}
static void uppercase(char *str) {
    while (*str != '\0') {
        *str = (char) toupper(*str);
        str++;
    }
}
