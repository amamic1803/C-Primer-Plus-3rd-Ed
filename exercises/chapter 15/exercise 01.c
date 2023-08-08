#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BIN_LEN 512
static int str_to_int(const char *str);


void ch15_ex01(void) {
    char str[MAX_BIN_LEN + 1];

    printf("Enter a binary number (empty line to quit):\n");
    while (fgets(str, MAX_BIN_LEN + 1, stdin) != NULL && str[0] != '\n' && str[0] != '\0') {
        str[strlen(str) - 1] = '\0';
        printf("%s in binary equals to %d in decimal.\n", str, str_to_int(str));
        printf("Enter a binary number (empty line to quit):\n");
    }
}

static int str_to_int(const char *str) {
    int result = 0;

    if (strlen(str) > (sizeof(int) * 8)) {
        printf("The string is too long.\n");
        return 0;
    }

    while (*str != '\0') {
        if (*str != '0' && *str != '1') {
            fprintf(stderr, "The string is not a binary number.\n");
            exit(EXIT_FAILURE);
        }
        result <<= 1;
        result |= *str - '0';
        str++;
    }

    return result;
}