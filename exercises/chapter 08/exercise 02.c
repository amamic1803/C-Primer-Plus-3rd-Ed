#include <stdio.h>


void ch08_ex02(void) {
    int line_elements = 0;
    char ch;

    printf("Enter text (EOF to quit):\n");

    while ((ch = (char) getchar()) != EOF) {
        if (ch == '\n') {
            if (line_elements == 10) {
                printf("\n");
                line_elements = 1;
            } else if (line_elements != 0) {
                printf("  |  ");
                line_elements = 0;
            }
            printf("\\n: %d\n", '\n');
        } else if (ch == '\t') {
            if (line_elements == 10) {
                printf("\n");
                line_elements = 1;
            } else if (line_elements != 0) {
                printf("  |  ");
                line_elements++;
            } else {
                line_elements++;
            }
            printf("\\t: %d", '\t');
        } else if (ch == ' ') {
            if (line_elements == 10) {
                printf("\n");
                line_elements = 1;
            } else if (line_elements != 0) {
                printf("  |  ");
                line_elements++;
            } else {
                line_elements++;
            }
            printf("[space]: %d", line_elements);
        } else if (ch < ' ') {
            if (line_elements == 10) {
                printf("\n");
                line_elements = 1;
            } else if (line_elements != 0) {
                printf("  |  ");
                line_elements++;
            } else {
                line_elements++;
            }
            printf("^%c: %d", ch + 64, ch);
        } else {
            if (line_elements == 10) {
                printf("\n");
                line_elements = 1;
            } else if (line_elements != 0) {
                printf("  |  ");
                line_elements++;
            } else {
                line_elements++;
            }
            printf("%c: %d", ch, ch);
        }
    }
}
