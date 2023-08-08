#include <stdio.h>
static int is_within(char ch, const char *str);


void ch11_ex05(void) {
    char str[] = "Hello, world!";
    char ch1 = 'o';
    char ch2 = 'z';
    printf("String: \"%s\"\n", str);
    printf("'%c' is %s in the string.\n", ch1, is_within(ch1, str) ? "found" : "not found");
    printf("'%c' is %s in the string.\n", ch2, is_within(ch2, str) ? "found" : "not found");
}

static int is_within(char ch, const char *str) {
    while (*str != '\0') {
        if (*str == ch)
            return 1;
        str++;
    }
    return 0;
}