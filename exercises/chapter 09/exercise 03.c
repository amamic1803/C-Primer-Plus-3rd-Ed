#include <stdio.h>
static void func(char ch, int a, int b);


void ch09_ex03(void) {
    char ch;
    int a, b;
    printf("Enter a character:\n");
    scanf("%c", &ch);
    printf("Enter columns:\n");
    scanf("%d", &a);
    printf("Enter rows:\n");
    scanf("%d", &b);
    printf("Output:\n");
    func(ch, a, b);
}

static void func(char ch, int a, int b) {
    int i, j;

    for (i = 0; i < b; i++) {
        for (j = 0; j < a; j++) {
            putchar(ch);
        }
        putchar('\n');
    }
}