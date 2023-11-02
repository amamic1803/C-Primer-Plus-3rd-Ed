#include <stdio.h>
#include <string.h>
#define MAX_LINE_SIZE 100
static void remove_spaces(char *str);
static void gets_custom(char *str, int size);


void ch11_ex09(void) {
    char str[MAX_LINE_SIZE + 1];

    printf("Enter a string (empty line to quit):\n");

    gets_custom(str, MAX_LINE_SIZE + 1);
    while (strcmp(str, "") != 0) {
        remove_spaces(str);
        printf("%s\n", str);
        gets_custom(str, MAX_LINE_SIZE + 1);
    }
}

static void remove_spaces(char *str) {
    char *p = str;
    while (*str != '\0')
    {
        if (*str != ' ')
        {
            *p++ = *str;
        }
        str++;
    }
    *p = '\0';
}

static void gets_custom(char *str, int size) {
    int i = 0;
    char ch;
    while ((ch = (char) getchar()) != '\n' && i < size - 1) {
        str[i++] = ch;
    }
    str[i] = '\0';
}