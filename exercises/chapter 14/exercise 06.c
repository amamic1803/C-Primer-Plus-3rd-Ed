#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_PLAYERS 19
#define MAX_LINE 100
struct player {
    char first_name[20];
    char last_name[20];
    int at_bats;
    int hits;
    int walks;
    int RBI;
    float batting_average;
};
static void parse_lines(struct player *players, FILE *fp);
static void calc_batting_average(struct player *players);
static void show_player_data(struct player *players);
static void show_cumulative_data(struct player *players);


void ch14_ex06(void) {
    struct player players[NUM_PLAYERS];
    FILE *fp;
    char filename[40];
    int i;

    // initialize players
    for (i = 0; i < NUM_PLAYERS; i++) {
        players[i].first_name[0] = '\0';
        players[i].last_name[0] = '\0';
        players[i].at_bats = 0;
        players[i].hits = 0;
        players[i].walks = 0;
        players[i].RBI = 0;
        players[i].batting_average = 0.0f;
    }

    printf("Enter the name of the file to be read:\n");
    fgets(filename, 40, stdin);
    if (filename[strlen(filename) - 1] == '\n')
        filename[strlen(filename) - 1] = '\0';
    putchar('\n');

    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }

    parse_lines(players, fp);

    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
        exit(EXIT_FAILURE);
    }

    calc_batting_average(players);
    show_player_data(players);
    show_cumulative_data(players);
}

static void parse_lines(struct player *players, FILE *fp) {
    char line[MAX_LINE];
    char *token;
    int i;

    while (fgets(line, MAX_LINE, fp) != NULL) {
        token = strtok(line, " ");
        i = strtol(token, NULL, 10);

        token = strtok(NULL, " ");
        strcpy(players[i].first_name, token);

        token = strtok(NULL, " ");
        strcpy(players[i].last_name, token);

        token = strtok(NULL, " ");
        players[i].at_bats += strtol(token, NULL, 10);

        token = strtok(NULL, " ");
        players[i].hits += strtol(token, NULL, 10);

        token = strtok(NULL, " ");
        players[i].walks += strtol(token, NULL, 10);

        token = strtok(NULL, " ");
        players[i].RBI += strtol(token, NULL, 10);
    }
}

static void calc_batting_average(struct player *players) {
    int i;

    for (i = 0; i < NUM_PLAYERS; i++) {
        players[i].batting_average = (float) players[i].hits / (float) players[i].at_bats;
    }
}

static void show_player_data(struct player *players) {
    int i;

    for (i = 0; i < NUM_PLAYERS; i++) {
        if (players[i].first_name[0] != '\0')
            printf("PLAYER %02d:\nFirst name: %s\nLast name: %s\nAt bat: %d\nHits: %d\nWalks: %d\nRBI: %d\nBatting average %.3f\n\n",
                   i, players[i].first_name, players[i].last_name, players[i].at_bats, players[i].hits,
                   players[i].walks, players[i].RBI, players[i].batting_average);
    }
}

static void show_cumulative_data(struct player *players) {
    int i;
    int total_at_bats = 0;
    int total_hits = 0;
    int total_walks = 0;
    int total_RBI = 0;
    float total_batting_average;

    for (i = 0; i < NUM_PLAYERS; i++) {
        total_at_bats += players[i].at_bats;
        total_hits += players[i].hits;
        total_walks += players[i].walks;
        total_RBI += players[i].RBI;
    }

    total_batting_average = (float) total_hits / (float) total_at_bats;

    printf("CUMULATIVE DATA:\nAt bat: %d\nHits: %d\nWalks: %d\nRBI: %d\nBatting average %.3f\n\n",
           total_at_bats, total_hits, total_walks, total_RBI, total_batting_average);
}