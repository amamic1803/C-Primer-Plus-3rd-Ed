#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 256
static int read_word(FILE *fp, char *word, int max_len);
typedef struct item {
    char word[MAX_STR_LEN];
    int count;
} Item;
typedef struct node {
    Item item;
    struct node *left;
    struct node *right;
} Node;
typedef struct binary_tree {
    Node *root;
} BinaryTree;
static void InitializeTree(BinaryTree *tree);
static void AddWord(const char *word, BinaryTree *tree);
static void AddWordInternal(const char *word, Node *node);
static void TraverseTree(const BinaryTree *tree, void (*pfun)(Item item));
static void TraverseTreeInternal(Node *node, void (*pfun)(Item item));

static void PrintItem(Item item);
static int SearchWord(const char *word, const BinaryTree *tree);
static int SearchWordInternal(const char *word, const Node *node);



void ch17_ex07(void) {
    char filename[MAX_STR_LEN];
    char word[MAX_STR_LEN];
    int choice;
    FILE *fp;
    BinaryTree tree;

    InitializeTree(&tree);

    puts("Enter filename:");
    fgets(filename, MAX_STR_LEN, stdin);
    if (filename[strlen(filename) - 1] == '\n')
        filename[strlen(filename) - 1] = '\0';

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while (read_word(fp, word, MAX_STR_LEN) == 1)
        AddWord(word, &tree);

    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
        exit(EXIT_FAILURE);
    }

    printf("\nChoose action:\n");
    printf("1) list all words and their occurrences\n");
    printf("2) search for word occurrences\n");
    printf("3) quit\n");
    printf("Enter choice:\n");
    while (scanf("%d", &choice) == 1) {
        while (getchar() != '\n');
        putchar('\n');
        switch (choice) {
            case 1:
                TraverseTree(&tree, PrintItem);
                break;
            case 2:
                puts("Enter word to search for:");
                fgets(word, MAX_STR_LEN, stdin);
                if (word[strlen(word) - 1] == '\n')
                    word[strlen(word) - 1] = '\0';
                printf("Occurrences of %s: %d\n", word, SearchWord(word, &tree));
                break;
            case 3:
                goto out;
            default:
                puts("Invalid choice");
                break;
        }
        printf("\nChoose action:\n");
        printf("1) list all words and their occurrences\n");
        printf("2) search for word occurrences\n");
        printf("3) quit\n");
        printf("Enter choice:\n");
    }
    out:;
}


static void PrintItem(Item item) {
    printf("%s\t%d\n", item.word, item.count);
}

static int SearchWord(const char *word, const BinaryTree *tree) {
    if (tree->root == NULL)
        return 0;
    return SearchWordInternal(word, tree->root);
}

static int SearchWordInternal(const char *word, const Node *node) {
    int cmp = strcmp(word, node->item.word);

    if (cmp == 0)
        return node->item.count;
    else if (cmp < 0) {
        if (node->left == NULL)
            return 0;
        else
            return SearchWordInternal(word, node->left);
    } else {
        if (node->right == NULL)
            return 0;
        else
            return SearchWordInternal(word, node->right);
    }
}

static int read_word(FILE *fp, char *word, int max_len) {
    char ch;
    int i = 0;

    while (isalnum(ch = (char) getc(fp)) == 0 && ch != EOF);
    if (ch == EOF)
        return 0;
    ungetc(ch, fp);

    while (isalnum(ch = (char) getc(fp)) != 0 && i < max_len - 1)
        word[i++] = (char) tolower(ch);
    word[i] = '\0';

    if (ch == EOF)
        return 0;
    else
        return 1;
}


static void InitializeTree(BinaryTree *tree) {
    tree->root = NULL;
}

static void AddWord(const char *word, BinaryTree *tree) {
    if (tree->root == NULL) {
        tree->root = (Node *) malloc(sizeof(Node));
        if (tree->root == NULL) {
            fprintf(stderr, "Can't allocate memory for root node\n");
            exit(EXIT_FAILURE);
        }
        strcpy(tree->root->item.word, word);
        tree->root->item.count = 1;
        tree->root->left = NULL;
        tree->root->right = NULL;
    } else {
        AddWordInternal(word, tree->root);
    }
}

static void AddWordInternal(const char *word, Node *node) {
    int cmp = strcmp(word, node->item.word);

    if (cmp == 0) {
        node->item.count++;
    } else if (cmp < 0) {
        if (node->left == NULL) {
            node->left = (Node *) malloc(sizeof(Node));
            if (node->left == NULL) {
                fprintf(stderr, "Can't allocate memory for left node\n");
                exit(EXIT_FAILURE);
            }
            strcpy(node->left->item.word, word);
            node->left->item.count = 1;
            node->left->left = NULL;
            node->left->right = NULL;
        } else {
            AddWordInternal(word, node->left);
        }
    } else {
        if (node->right == NULL) {
            node->right = (Node *) malloc(sizeof(Node));
            if (node->right == NULL) {
                fprintf(stderr, "Can't allocate memory for right node\n");
                exit(EXIT_FAILURE);
            }
            strcpy(node->right->item.word, word);
            node->right->item.count = 1;
            node->right->left = NULL;
            node->right->right = NULL;
        } else {
            AddWordInternal(word, node->right);
        }
    }
}

static void TraverseTree(const BinaryTree *tree, void (*pfun)(Item item)) {
    if (tree->root != NULL)
        TraverseTreeInternal(tree->root, pfun);
}

static void TraverseTreeInternal(Node *node, void (*pfun)(Item item)) {
    if (node->left != NULL)
        TraverseTreeInternal(node->left, pfun);
    (*pfun)(node->item);
    if (node->right != NULL)
        TraverseTreeInternal(node->right, pfun);
}