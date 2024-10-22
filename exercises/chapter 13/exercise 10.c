#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM_LEN 15
static int get_num(long long int *num);


void ch13_ex10(void) {
    long long int num = 0;

    printf("Enter input: ");
    fflush(stdout);
    get_num(&num);
    printf("Number: %lld\n", num);
}

static int get_num(long long int *num) {
    char ch;
    int num_flag = 0;
    char num_str[MAX_NUM_LEN + 1];
    num_str[MAX_NUM_LEN] = '\0';
    int i = 0;
    int eof_found = 0;
    int error_found = 0;
    int prev_minus = 0;

    while (1) {
        ch = (char) getc(stdin);
        if (ch >= '0' && ch <= '9') {
            num_flag = 1;
            if (i < MAX_NUM_LEN) {
                if (prev_minus) {
                    num_str[i++] = '-';
                    prev_minus = 0;
                }
                num_str[i++] = ch;
            } else {
                fprintf(stderr, "Number is too long.\n");
                error_found = 1;
                break;
            }
        } else if (ch == '-' && num_flag == 0) {
            prev_minus = 1;
        } else {
            if (num_flag) {
                num_str[i] = '\0';
                *num = (long long int) strtoll(num_str, NULL, 10);
                ungetc(ch, stdin);
            }
            if (ch == EOF) {
                eof_found = 1;
            }
            if (num_flag || eof_found)
                break;
        }
    }

    if (!num_flag)
        error_found = 1;

    if (eof_found)
        return EOF;
    return error_found ? 0 : 1;
}
