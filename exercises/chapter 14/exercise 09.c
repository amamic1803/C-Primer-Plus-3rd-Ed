#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 20
#define FLIGHTS 4
#define SEATS 12
#define FILENAME "flights_seats.dat"
struct seat {
    int id;
    int booked;
    char last_name[MAX_NAME_LEN];
    char first_name[MAX_NAME_LEN];
};
static int empty_seats(struct seat *seats);
static void process_flight(struct seat *seats);


void ch14_ex09(void) {
    FILE *fp;
    struct seat seats[FLIGHTS][SEATS];
    int i, j;
    char choice;

    if ((fp = fopen(FILENAME, "r+b")) == NULL) {
        if ((fp = fopen(FILENAME, "wb")) == NULL) {
            printf("Can't create %s file.\n", FILENAME);
            exit(EXIT_FAILURE);
        }
        for (j = 0; j < FLIGHTS; j++)
            for (i = 0; i < SEATS; i++) {
                seats[j][i].id = i + 1;
                seats[j][i].booked = 0;
                seats[j][i].last_name[0] = '\0';
                seats[j][i].first_name[0] = '\0';
            }
    } else {
        fread(seats, sizeof(struct seat), SEATS * FLIGHTS, fp);
    }

    while (1) {
        printf("Choose a flight:\n");
        printf("a) Flight 102\n");
        printf("b) Flight 311\n");
        printf("c) Flight 444\n");
        printf("d) Flight 519\n");
        printf("e) Quit\n");
        printf("Enter your choice:\n");

        choice = (char) tolower(getchar());
        if (choice != '\n')
            while (getchar() != '\n');
        putchar('\n');

        switch (choice) {
            case 'a': {
                process_flight(seats[0]);
                break;
            }
            case 'b': {
                process_flight(seats[1]);
                break;
            }
            case 'c': {
                process_flight(seats[2]);
                break;
            }
            case 'd': {
                process_flight(seats[3]);
                break;
            }
            case 'e': {
                goto out_flights;
            }
            default: {
                printf("Invalid choice.\n\n");
                break;
            }
        }
    }
    out_flights:;

    rewind(fp);
    fwrite(seats, sizeof(struct seat), SEATS * FLIGHTS, fp);
    if (fclose(fp) != 0) {
        printf("Error in closing file %s.\n", FILENAME);
        exit(EXIT_FAILURE);
    }
}

static int empty_seats(struct seat *seats) {
    int i;
    int empty_seats = 0;
    for (i = 0; i < SEATS; i++)
        if (seats[i].booked == 0)
            empty_seats++;
    return empty_seats;
}

static void process_flight(struct seat *seats) {
    struct seat *temp;
    int seat_id;
    char last_name[MAX_NAME_LEN];
    char first_name[MAX_NAME_LEN];
    struct seat *seats_ptrs[SEATS];
    int i, j;
    char choice;

    for (i = 0; i < SEATS; i++)
        seats_ptrs[i] = &seats[i];

    while (1) {
        printf("To choose a function, enter its letter label:\n");
        printf("a) Show number of empty seats\n");
        printf("b) Show list of empty seats\n");
        printf("c) Show alphabetical list of seats\n");
        printf("d) Assign a customer to a seat assignment\n");
        printf("e) Delete a seat assignment\n");
        printf("f) Back\n");
        printf("Enter your choice:\n");

        choice = (char) tolower(getchar());
        if (choice != '\n')
            while (getchar() != '\n');

        switch (choice) {
            case 'a':
                printf("\nThere are %d empty seats.\n\n", empty_seats(seats));
                break;
            case 'b':
                printf("\nEmpty seats:\n");
                for (i = 0; i < SEATS; i++) {
                    if (seats[i].booked == 0) {
                        printf(" - seat %02d\n", seats[i].id);
                    }
                }
                putchar('\n');
                break;
            case 'c':
                printf("\nAlphabetical list of seats:\n");
                for (i = 0; i < SEATS; i++) {
                    for (j = i + 1; j < SEATS; j++) {
                        if (strcmp(seats_ptrs[i]->last_name, seats_ptrs[j]->last_name) > 0) {
                            temp = seats_ptrs[i];
                            seats_ptrs[i] = seats_ptrs[j];
                            seats_ptrs[j] = temp;
                        }
                    }
                }
                for (i = 0; i < SEATS; i++) {
                    if (seats_ptrs[i]->booked == 1) {
                        printf(" - seat %02d: %s, %s\n", seats_ptrs[i]->id, seats_ptrs[i]->last_name, seats_ptrs[i]->first_name);
                    }
                }
                putchar('\n');
                break;
            case 'd':
                putchar('\n');
                if (empty_seats(seats) == 0) {
                    printf("Sorry, all seats are booked.\n\n");
                    break;
                }
                printf("Enter the seat id:\n");
                scanf("%d", &seat_id);
                while (getchar() != '\n');
                if (seat_id < 1 || seat_id > SEATS) {
                    printf("Invalid seat id.\n\n");
                    break;
                }
                if (seats[seat_id - 1].booked == 1) {
                    printf("That seat is already booked.\n\n");
                    break;
                }

                printf("Enter the customer's first name:\n");
                fgets(first_name, MAX_NAME_LEN, stdin);
                if (first_name[strlen(first_name) - 1] == '\n')
                    first_name[strlen(first_name) - 1] = '\0';

                printf("Enter the customer's last name:\n");
                fgets(last_name, MAX_NAME_LEN, stdin);
                if (last_name[strlen(last_name) - 1] == '\n')
                    last_name[strlen(last_name) - 1] = '\0';

                putchar('\n');

                seats[seat_id - 1].booked = 1;
                strcpy(seats[seat_id - 1].first_name, first_name);
                strcpy(seats[seat_id - 1].last_name, last_name);

                break;
            case 'e':
                printf("\nEnter the seat id:\n");
                scanf("%d", &seat_id);
                while (getchar() != '\n');
                if (seat_id < 1 || seat_id > SEATS) {
                    printf("Invalid seat id.\n\n");
                    break;
                }
                if (seats[seat_id - 1].booked == 0) {
                    printf("That seat is not booked.\n\n");
                    break;
                }

                seats[seat_id - 1].booked = 0;
                putchar('\n');

                break;
            case 'f':
                putchar('\n');
                goto out;
            default:
                printf("\nInvalid choice.\n\n");
                break;
        }
    }
    out:;
}