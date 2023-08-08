#include <stdio.h>
static char * search_string(char * string, char ch);


void ch11_ex04(void) {
    char string[] = "Hello, world!";
    char ch1 = 'o';
    char ch2 = 'z';
    char * result = search_string(string, ch1);
    char * result2 = search_string(string, ch2);
    printf("String: \"%s\"\n", string);
    if (result == NULL)
        printf("Character '%c' not found in string \"%s\".\n", ch1, string);
    else
        printf("Character '%c' found in string \"%s\" at position %d.\n", ch1, string, (int) (result - string));
    if (result2 == NULL)
        printf("Character '%c' not found in string \"%s\".\n", ch2, string);
    else
        printf("Character '%c' found in string \"%s\" at position %d.\n", ch2, string, (int) (result2 - string));
}

static char * search_string(char * string, char ch) {
    while (*string != '\0')
    {
        if (*string == ch)
            return string;
        string++;
    }
    return NULL;
}