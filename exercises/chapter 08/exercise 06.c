#include <ctype.h>
#include <stdio.h>
static int getfirst(void);


void ch08_ex06(void) {
    printf("Enter text;\n");
    printf("First non-whitespace character is: %c\n", getfirst());
}

static int getfirst(void) {
    int ch;

    while (isspace(ch = getchar()));
    while (getchar() != '\n');

    return ch;
}
