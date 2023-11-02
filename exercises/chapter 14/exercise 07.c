#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
#define MAX_LINE 256
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
static char * gets_custom(char *s, int max_len);


void ch14_ex07(void) {
    struct book libry[MAXBKS];
    int count = 0;
    int index;
    FILE * pbooks;
    int size = sizeof(struct book);

    if ((pbooks = fopen("book.dat", "rb")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(EXIT_FAILURE);
    }
    rewind(pbooks);
    while (count < MAXBKS && fread(&libry[count], size, 1, pbooks) == 1) {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", libry[count].title, libry[count].author, libry[count].value);
        printf("Keep this entry? <y/n>\n");

        while (1) {
            switch (tolower(getchar())) {
                case 'y':
                    while (getchar() != '\n');
                    count++;

                    printf("Modify this entry? <y/n>\n");

                    while (1) {
                        switch (tolower(getchar())) {
                            case 'y':
                                while (getchar() != '\n');
                                printf("Enter the new title.\n");
                                gets_custom(libry[count - 1].title, MAX_LINE);
                                printf("Enter the new author.\n");
                                gets_custom(libry[count - 1].author, MAX_LINE);
                                printf("Enter the new value.\n");
                                scanf("%f", &libry[count - 1].value);
                                while (getchar() != '\n');
                                goto out;
                            case 'n':
                                while (getchar() != '\n');
                                goto out;
                            case '\n':
                                puts("Invalid input. Please enter y or n.");
                                break;
                            default:
                                while (getchar() != '\n');
                                puts("Invalid input. Please enter y or n.");
                                break;
                        }
                    }
                case 'n':
                    while (getchar() != '\n');
                    goto out;
                case '\n':
                    puts("Invalid input. Please enter y or n.");
                    break;
                default:
                    while (getchar() != '\n');
                    puts("Invalid input. Please enter y or n.");
                    break;
            }
        }
        out:;
    }
    if (count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && gets_custom(libry[count].title, MAX_LINE) != NULL && libry[count].title[0] != '\0') {
        puts("Now enter the author.");
        gets_custom(libry[count].author, MAX_LINE);
        puts("Now enter the value.");
        scanf("%f", &libry[count++].value);
        while (getchar() != '\n');
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    puts("Here is the list of your books:");
    for (index = 0; index < count; index++)
        printf("%s by %s: $%.2f\n", libry[index].title, libry[index].author, libry[index].value);
    pbooks = freopen("book.dat", "wb", pbooks);
    fwrite(&libry[0], size, count, pbooks);
    if (fclose(pbooks) != 0) {
        fprintf(stderr, "Error closing file\n");
        exit(EXIT_FAILURE);
    }
}

static char * gets_custom(char *s, int max_len) {
    char c;
    char *initial = s;
    int i = 0;

    while ((c = (char) getchar()) != '\n' && c != EOF && i < max_len - 1) {
        *s++ = c;
        i++;
    }
    *s = '\0';

    if (initial == s && c != '\n')
        return NULL;
    else
        return initial;
}