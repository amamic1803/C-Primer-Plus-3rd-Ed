#include <stdio.h>
#define MAX_LEN 80
static void fetch_input(char *input, int max_len);


void ch11_ex01(void) {
    char input[MAX_LEN + 1];

    printf("Enter text (max %d characters):\n", MAX_LEN);
    fetch_input(input, MAX_LEN);
    printf("\nYou entered:\n%s\n", input);
}

static void fetch_input(char *input, int max_len) {
    int count = 0;
    while (count < max_len) {
        *input = (char) getchar();
        if (*input == EOF) {
            *input = '\0';
            break;
        }
        count++;
        input++;
    }
    *input = '\0';
}
