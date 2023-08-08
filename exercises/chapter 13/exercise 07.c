#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int rollem(int sides);


void ch13_ex07(void) {
    int sets, dice, sides;
    int i, j, roll;

    srand((unsigned int) time(0));
    printf("Enter the number of sets; enter q to stop.\n");
    while (scanf("%d", &sets) == 1 && sets > 0) {
        printf("How many sides and how many dice?\n");
        scanf("%d %d", &sides, &dice);
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (i = 0; i < sets; i++) {
            roll = 0;
            for (j = 0; j < dice; j++)
                roll += rollem(sides);
            printf("%4d", roll);
            if ((i + 1) % 15 == 0)
                putchar('\n');
        }
        if (i % 15)
            putchar('\n');
        printf("How many sets? Enter q to stop.\n");
    }
}

static int rollem(int sides) {
    return rand() % sides + 1;
}