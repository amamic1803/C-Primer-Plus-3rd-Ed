#include <stdio.h>


void ch07_ex06(void) {
    char previous_char = ' ';
    char input_char;
    int seq_occurences = 0;

    printf("Enter text (# stops):\n");

    while ((input_char = (char) getchar()) != '#') {
        if (previous_char == 'e' && input_char == 'i') {
            seq_occurences++;
        }
        previous_char = input_char;
    }

    printf("The sequence \"ei\" appeared %d times.\n", seq_occurences);
}
