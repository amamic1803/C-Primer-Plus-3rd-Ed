#include <stdio.h>
static int a_to_i(char *str);


void ch11_ex14(void) {
    int i;
    char *test_strings[] = {
            "123",
            "-123",
            "+123",
            "123abc",
            "abc123",
            "abc",
            "123abc456def",
            "abc+123abc456",
            "abc-123abc456def",
            "123abc-456def789",
    };

    puts("Testing a_to_i() function:");

    for (i = 0; i < 10; i++) {
        printf("%-16s == %d\n", test_strings[i], a_to_i(test_strings[i]));
    }
}

static int a_to_i(char *str) {
    int num = 0;
    int start = 0;
    int sign = 1;

    while (*str != '\0') {
        if (!start && *str == '-' && ('0' <= *(str + 1) && *(str + 1) <= '9')) {
            sign = -1;
            start = 1;
        } else if (!start && *str == '+' && ('0' <= *(str + 1) && *(str + 1) <= '9')) {
            start = 1;
        } else if ('0' <= *str && *str <= '9') {
            num = num * 10 + *str - '0';
            start = 1;
        } else if (start) {
            break;
        }

        str++;
    }

    return num * sign;
}