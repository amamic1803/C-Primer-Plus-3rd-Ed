#include <stdio.h>
#include <string.h>
static void sreverse(char *str);


void ch11_ex08(void) {
    char str1[] = "Hello, world!";
    char str1_rev[] = "Hello, world!";
    char str2[] = "Hello, C!";
    char str2_rev[] = "Hello, C!";

    sreverse(str1_rev);
    sreverse(str2_rev);
    printf("\"%s\" reversed is \"%s\".\n", str1, str1_rev);
    printf("\"%s\" reversed is \"%s\".\n", str2, str2_rev);
}

static void sreverse(char *str) {
    char temp;
    int i;
    int len = (int) strlen(str);

    for (i = 0; i < (len / 2); i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}