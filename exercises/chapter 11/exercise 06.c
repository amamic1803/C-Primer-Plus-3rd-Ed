#include <stdio.h>
static char * str_n_cpy(char *s1, const char *s2, int n);


void ch11_ex06(void) {
    char orig[] = "Hello, world!";
    char copy1[40];
    char copy2[40];

    printf("String to be copied: %s\n", orig);
    str_n_cpy(copy1, orig, 5);
    printf("Result of str_n_cpy(copy1, orig, 5): %s\n", copy1);
    str_n_cpy(copy2, orig, 20);
    printf("Result of str_n_cpy(copy2, orig, 20): %s\n", copy2);
}

static char * str_n_cpy(char *s1, const char *s2, int n) {
    int i;
    int s2_end = 0;
    for (i = 0; i < n; i++) {
        if (s2[i] == '\0') {
            s2_end = 1;
        }
        if (s2_end) {
            s1[i] = '\0';
        } else {
            s1[i] = s2[i];
        }
    }
    s1[n] = '\0';
    return s1;
}