#include <stdio.h>


void ch03_ex02(void) {
    unsigned int ascii_code;

    printf("Enter ASCII code:\n");
    scanf("%d", &ascii_code);
    printf("ASCII code %d represents %c.", ascii_code, ascii_code);
}