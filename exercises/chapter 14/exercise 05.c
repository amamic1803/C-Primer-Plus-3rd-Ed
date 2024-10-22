#include <stdio.h>
#define CSIZE 4
#define GRADES 3
struct name {
    char first[20];
    char second[20];
};
struct student {
    struct name name;
    float grade[GRADES];
    float average;
};
static void get_student_data(struct student *student, int count);
static void calculate_average(struct student *student, int count);
static void print_student_data(const struct student *student, int count);
static void print_class_average(struct student *student, int count);


void ch14_ex05(void) {
    struct student students[CSIZE] = {
        {{"John", "Doe"}, {0, 0, 0}, 0},
        {{"Jane", "Doe"}, {0, 0, 0}, 0},
        {{"Jack", "Doe"}, {0, 0, 0}, 0},
        {{"Jill", "Doe"}, {0, 0, 0}, 0}
    };
    get_student_data(students, CSIZE);
    calculate_average(students, CSIZE);
    print_student_data(students, CSIZE);
    print_class_average(students, CSIZE);
}

static void get_student_data(struct student *student, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("Enter %s %s's grades:\n", student[i].name.first, student[i].name.second);
        printf("Grade 1:\n");
        scanf("%f", &student[i].grade[0]);
        printf("Grade 2:\n");
        scanf("%f", &student[i].grade[1]);
        printf("Grade 3:\n");
        scanf("%f", &student[i].grade[2]);
        putchar('\n');
    }
}

static void calculate_average(struct student *student, int count) {
    int i;
    for (i = 0; i < count; i++) {
        student[i].average = (student[i].grade[0] + student[i].grade[1] + student[i].grade[2]) / GRADES;
    }
}

static void print_student_data(const struct student *student, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%s %s's grades:\n", student[i].name.first, student[i].name.second);
        printf("Grade 1: %.2f\n", student[i].grade[0]);
        printf("Grade 2: %.2f\n", student[i].grade[1]);
        printf("Grade 3: %.2f\n", student[i].grade[2]);
        printf("Average: %.2f\n\n", student[i].average);
    }
}

static void print_class_average(struct student *student, int count) {
    int i, j;
    float average;

    printf("Class average:\n");
    for (i = 0; i < GRADES; i++) {
        average = 0;
        for (j = 0; j < count; j++) {
            average += student[j].grade[i];
        }
        average /= (float) count;
        printf("Grade %d average: %.2f\n", i + 1, average);
    }
}
