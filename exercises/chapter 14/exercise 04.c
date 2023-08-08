#include <stdio.h>
#include <string.h>
#define MAX_FIELD_SIZE 20
#define ARRAY_SIZE 5
struct name_info {
    char first_name[MAX_FIELD_SIZE + 1];
    char middle_name[MAX_FIELD_SIZE + 1];
    char last_name[MAX_FIELD_SIZE + 1];
};
struct soc_sec_info {
    long long unsigned int soc_sec_num;
    struct name_info name;
};
static void print_array_of_structs(const struct soc_sec_info *array, int size);
static void print_struct(struct soc_sec_info soc_sec_struct);


void ch14_ex04(void) {
    int i;
    struct soc_sec_info soc_sec_array[ARRAY_SIZE] = {
        { 302039823, { "Dribble", "Middle", "Flossie" } },
        { 302039824, { "Antonio", "", "Mamic" } },
        { 302039825, { "Andre", "", "Hendrix" } },
        { 302039826, { "Howard", "Louis", "Porche" } },
        { 302039827, { "Floyd", "Carlos", "Cabrera" } }
    };
    printf("Printing array of structs:\n");
    print_array_of_structs(soc_sec_array, ARRAY_SIZE);
    putchar('\n');
    printf("Printing struct by struct:\n");
    for (i = 0; i < ARRAY_SIZE; i++)
        print_struct(soc_sec_array[i]);
}

static void print_array_of_structs(const struct soc_sec_info *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s", array[i].name.last_name);
        putchar(',');
        printf(" %s", array[i].name.first_name);
        if (strlen(array[i].name.middle_name) > 0) {
            putchar(' ');
            printf("%c.", array[i].name.middle_name[0]);
        }
        printf(" -- %llu\n", array[i].soc_sec_num);
    }
}

static void print_struct(struct soc_sec_info soc_sec_struct) {
    printf("%s", soc_sec_struct.name.last_name);
    putchar(',');
    printf(" %s", soc_sec_struct.name.first_name);
    if (strlen(soc_sec_struct.name.middle_name) > 0) {
        putchar(' ');
        printf("%c.", soc_sec_struct.name.middle_name[0]);
    }
    printf(" -- %llu\n", soc_sec_struct.soc_sec_num);
}