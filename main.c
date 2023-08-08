#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercises.h"
static const char *get_filename(const char *full_filename);
static void help(const char *filename);
static void list(int chapters, const int *metadata);
static void run(int chapter, int exercise, int arg_count, char **arg_values);


int main(int argc, char *argv[]) {
    const int METADATA[] = EXERCISES;
    int chapters;
    const char *filename;
    int chapter_num, exercise_num;
    int help_flag = 0, list_flag = 0;
    int i;

    puts("******************************************************");
    puts("******       C Primer Plus, Third Edition       ******");
    puts("******************************************************");

    chapters = sizeof METADATA / sizeof METADATA[0];
    filename = get_filename(argv[0]);

    if (argc == 1) {
        fputs("\nInvalid number of arguments!\n\n", stderr);
        fprintf(stderr, "To get help run:\n%s --help\n\n", filename);
        return -1;
    }

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            help_flag = 1;
        } else if (strcmp(argv[i], "--list") == 0) {
            list_flag = 1;
        }
    }

    if (help_flag) {
        help(filename);
        return 0;
    } else if (list_flag) {
        list(chapters, METADATA);
        return 0;
    }

    if (argc < 3) {
        fputs("\nInvalid number of arguments!\n\n", stderr);
        fprintf(stderr, "To get help run:\n%s --help\n\n", filename);
        return -1;
    }

    // 0 if NaN
    chapter_num = (int) strtol(argv[1], NULL, 10);
    if (chapter_num < 1 || chapters < chapter_num) {
        fputs("\nInvalid chapter number!\n\n", stderr);
        fprintf(stderr, "To list available chapters run:\n%s --list\n\n", filename);
        return -1;
    }
    exercise_num = (int) strtol(argv[2], NULL, 10);
    if (exercise_num < 1 || METADATA[chapter_num - 1] < exercise_num) {
        fputs("\nInvalid exercise number!\n\n", stderr);
        fprintf(stderr, "To list available exercises run:\n%s --list\n\n", filename);
        return -1;
    }

    *(argv + 2) = *argv;

    run(chapter_num, exercise_num, argc - 2, argv + 2);

    return 0;
}

static const char *get_filename(const char *full_filename) {
    const char *short_filename;

    short_filename = strrchr(full_filename, '\\');
    if (short_filename == NULL) {
        short_filename = strrchr(full_filename, '/');
        if (short_filename == NULL) {
            short_filename = full_filename;
        } else {
            short_filename++;
        }
    } else {
        short_filename++;
    }

    return short_filename;
}

static void help(const char *filename) {
    putchar('\n');
    printf("Usage: %s [--help] [--list] chapter_number exercise_number [ARGS]\n", filename);
    putchar('\n');
    printf("Options:\n");
    printf("%4s%-15s%10s%s\n", "", "--help", "", "Show this usage information.");
    printf("%4s%-15s%10s%s\n", "", "--list", "", "Show the list of all exercises.");
    printf("%4s%-15s%10s%s\n", "", "chapter_number", "", "The number of the desired chapter.");
    printf("%4s%-15s%10s%s\n", "", "exercise_number", "", "The number of the desired exercise.");
    printf("%4s%-15s%10s%s\n", "", "ARGS", "", "Additional arguments to pass to exercise.");
    putchar('\n');
}

static void list(int chapters, const int *metadata) {
    int i, j;
    putchar('\n');
    for (i = 0; i < chapters; i++) {
        printf("Chapter %02d\n", i + 1);
        for (j = 1; j <= metadata[i]; j++) {
            printf("   Exercise %02d\n", j);
        }
    }
    putchar('\n');
}

static void run(int chapter, int exercise, int arg_count, char **arg_values) {
    printf("************    Chapter %02d Exercise %02d    ************\n", chapter, exercise);
    puts("******************************************************\n");
    switch (chapter) {
        case 1: {
            ch01_ex01();
            break;
        }
        case 2: {
            switch (exercise) {
                case 1: {
                    ch02_ex01();
                    break;
                }
                case 2: {
                    ch02_ex02();
                    break;
                }
                case 3: {
                    ch02_ex03();
                    break;
                }
                case 4: {
                    ch02_ex04();
                    break;
                }
                case 5: {
                    ch02_ex05();
                    break;
                }
                case 6: {
                    ch02_ex06();
                    break;
                }
                default: {
                    fprintf(stderr, "Error!");
                    break;
                }
            }
            break;
        }
        case 3: {
            switch (exercise) {
                case 1: {
                    ch03_ex01();
                    break;
                }
                case 2: {
                    ch03_ex02();
                    break;
                }
                case 3: {
                    ch03_ex03();
                    break;
                }
                case 4: {
                    ch03_ex04();
                    break;
                }
                case 5: {
                    ch03_ex05();
                    break;
                }
                case 6: {
                    ch03_ex06();
                    break;
                }
                default: {
                    fprintf(stderr, "Error!");
                    break;
                }
            }
            break;
        }
        case 4: {
            switch (exercise) {
                case 1: {
                    ch04_ex01();
                    break;
                }
                case 2: {
                    ch04_ex02();
                    break;
                }
                case 3: {
                    ch04_ex03();
                    break;
                }
                case 4: {
                    ch04_ex04();
                    break;
                }
                case 5: {
                    ch04_ex05();
                    break;
                }
                default: {
                    fprintf(stderr, "Error!");
                    break;
                }
            }
            break;
        }
        case 5: {
            switch (exercise) {
                case 1: {
                    ch05_ex01();
                    break;
                }
                case 2: {
                    ch05_ex02();
                    break;
                }
                case 3: {
                    ch05_ex03();
                    break;
                }
                case 4: {
                    ch05_ex04();
                    break;
                }
                case 5: {
                    ch05_ex05();
                    break;
                }
                case 6: {
                    ch05_ex06();
                    break;
                }
                default: {
                    fprintf(stderr, "Error!");
                    break;
                }
            }
            break;
        }
        case 6: {
            switch (exercise) {
                case 1: {
                    ch06_ex01();
                    break;
                }
                case 2: {
                    ch06_ex02();
                    break;
                }
                case 3: {
                    ch06_ex03();
                    break;
                }
                case 4: {
                    ch06_ex04();
                    break;
                }
                case 5: {
                    ch06_ex05();
                    break;
                }
                case 6: {
                    ch06_ex06();
                    break;
                }
                case 7: {
                    ch06_ex07();
                    break;
                }
                case 8: {
                    ch06_ex08();
                    break;
                }
                case 9: {
                    ch06_ex09();
                    break;
                }
                case 10: {
                    ch06_ex10();
                    break;
                }
                case 11: {
                    ch06_ex11();
                    break;
                }
                case 12: {
                    ch06_ex12();
                    break;
                }
                case 13: {
                    ch06_ex13();
                    break;
                }
                case 14: {
                    ch06_ex14();
                    break;
                }
                default: {
                    fprintf(stderr, "Error!");
                    break;
                }
            }
            break;
        }
        case 7: {
            switch (exercise) {
                case 1: {
                    ch07_ex01();
                    break;
                }
                case 2: {
                    ch07_ex02();
                    break;
                }
                case 3: {
                    ch07_ex03();
                    break;
                }
                case 4: {
                    ch07_ex04();
                    break;
                }
                case 5: {
                    ch07_ex05();
                    break;
                }
                case 6: {
                    ch07_ex06();
                    break;
                }
                case 7: {
                    ch07_ex07();
                    break;
                }
                case 8: {
                    ch07_ex08();
                    break;
                }
                case 9: {
                    ch07_ex09();
                    break;
                }
                case 10: {
                    ch07_ex10();
                    break;
                }
                default: {
                    fprintf(stderr, "Error!");
                    break;
                }
            }
            break;
        }
        case 8: {
            switch (exercise) {
                case 1: {
                    ch08_ex01();
                    break;
                }
                case 2: {
                    ch08_ex02();
                    break;
                }
                case 3: {
                    ch08_ex03();
                    break;
                }
                case 4: {
                    ch08_ex04();
                    break;
                }
                case 5: {
                    ch08_ex05();
                    break;
                }
                case 6: {
                    ch08_ex06();
                    break;
                }
                case 7: {
                    ch08_ex07();
                    break;
                }
                default: {
                    fprintf(stderr, "Error!");
                    break;
                }
            }
            break;
        }
        case 9: {
            switch (exercise) {
                case 1: {
                    ch09_ex01();
                    break;
                }
                case 2: {
                    ch09_ex02();
                    break;
                }
                case 3: {
                    ch09_ex03();
                    break;
                }
                case 4: {
                    ch09_ex04();
                    break;
                }
                case 5: {
                    ch09_ex05();
                    break;
                }
                case 6: {
                    ch09_ex06();
                    break;
                }
                case 7: {
                    ch09_ex07();
                    break;
                }
                case 8: {
                    ch09_ex08();
                    break;
                }
                case 9: {
                    ch09_ex09();
                    break;
                }
                default: {
                    fprintf(stderr, "Error!");
                    break;
                }
            }
            break;
        }
        case 10: {
            switch (exercise) {
                case 1: {
                    ch10_ex01();
                    break;
                }
                case 2: {
                    ch10_ex02();
                    break;
                }
                case 3: {
                    ch10_ex03();
                    break;
                }
                case 4: {
                    ch10_ex04();
                    break;
                }
                case 5: {
                    ch10_ex05();
                    break;
                }
                case 6: {
                    ch10_ex06();
                    break;
                }
                case 7: {
                    ch10_ex07();
                    break;
                }
                case 8: {
                    ch10_ex08();
                    break;
                }
                case 9: {
                    ch10_ex09();
                    break;
                }
                case 10: {
                    ch10_ex10();
                    break;
                }
                case 11: {
                    ch10_ex11();
                    break;
                }
                default: {
                    fprintf(stderr, "Error!");
                    break;
                }
            }
            break;
        }
        case 11: {
            switch (exercise) {
                case 1: {
                    ch11_ex01();
                    break;
                }
                case 2: {
                    ch11_ex02();
                    break;
                }
                case 3: {
                    ch11_ex03();
                    break;
                }
                case 4: {
                    ch11_ex04();
                    break;
                }
                case 5: {
                    ch11_ex05();
                    break;
                }
                case 6: {
                    ch11_ex06();
                    break;
                }
                case 7: {
                    ch11_ex07();
                    break;
                }
                case 8: {
                    ch11_ex08();
                    break;
                }
                case 9: {
                    ch11_ex09();
                    break;
                }
                case 10: {
                    ch11_ex10();
                    break;
                }
                case 11: {
                    ch11_ex11();
                    break;
                }
                case 12: {
                    ch11_ex12(arg_count, arg_values);
                    break;
                }
                case 13: {
                    ch11_ex13(arg_count, arg_values);
                    break;
                }
                case 14: {
                    ch11_ex14();
                    break;
                }
                case 15: {
                    ch11_ex15(arg_count, arg_values);
                    break;
                }
                default: {
                    fprintf(stderr,"Error!");
                    break;
                }
            }
            break;
        }
        case 12: {
            switch (exercise) {
                case 1: {
                    ch12_ex01(arg_count, arg_values);
                    break;
                }
                case 2: {
                    ch12_ex02(arg_count, arg_values);
                    break;
                }
                case 3: {
                    ch12_ex03(arg_count, arg_values);
                    break;
                }
                case 4: {
                    ch12_ex04();
                    break;
                }
                case 5: {
                    ch12_ex05(arg_count, arg_values);
                    break;
                }
                case 6: {
                    ch12_ex06(arg_count, arg_values);
                    break;
                }
                case 7: {
                    ch12_ex07();
                    break;
                }
                case 8: {
                    ch12_ex08();
                    break;
                }
                case 9: {
                    ch12_ex09(arg_count, arg_values);
                    break;
                }
                case 10: {
                    ch12_ex10();
                    break;
                }
                case 11: {
                    ch12_ex11();
                    break;
                }
                case 12: {
                    ch12_ex12();
                    break;
                }
                default: {
                    fprintf(stderr, "Error!");
                    break;
                }
            }
            break;
        }
        case 13: {
            switch (exercise) {
                case 1: {
                    ch13_ex01();
                    break;
                }
                case 2: {
                    ch13_ex02();
                    break;
                }
                case 3: {
                    ch13_ex03();
                    break;
                }
                case 4: {
                    ch13_ex04();
                    break;
                }
                case 5: {
                    ch13_ex05();
                    break;
                }
                case 6: {
                    ch13_ex06();
                    break;
                }
                case 7: {
                    ch13_ex07();
                    break;
                }
                case 8: {
                    ch13_ex08();
                    break;
                }
                case 9: {
                    ch13_ex09();
                    break;
                }
                case 10: {
                    ch13_ex10();
                    break;
                }
                case 11: {
                    ch13_ex11();
                    break;
                }
                default: {
                    fprintf(stderr,"Error!");
                    break;
                }
            }
            break;
        }
        case 14: {
            switch (exercise) {
                case 1: {
                    ch14_ex01();
                    break;
                }
                case 2: {
                    ch14_ex02();
                    break;
                }
                case 3: {
                    ch14_ex03();
                    break;
                }
                case 4: {
                    ch14_ex04();
                    break;
                }
                case 5: {
                    ch14_ex05();
                    break;
                }
                case 6: {
                    ch14_ex06();
                    break;
                }
                case 7: {
                    ch14_ex07();
                    break;
                }
                case 8: {
                    ch14_ex08();
                    break;
                }
                case 9: {
                    ch14_ex09();
                    break;
                }
                case 10: {
                    ch14_ex10();
                    break;
                }
                default: {
                    fprintf(stderr,"Error!");
                    break;
                }
            }
            break;
        }
        case 15: {
            switch (exercise) {
                case 1: {
                    ch15_ex01();
                    break;
                }
                case 2: {
                    ch15_ex02(arg_count, arg_values);
                    break;
                }
                case 3: {
                    ch15_ex03();
                    break;
                }
                case 4: {
                    ch15_ex04();
                    break;
                }
                case 5: {
                    ch15_ex05();
                    break;
                }
                case 6: {
                    ch15_ex06();
                    break;
                }
                default: {
                    fprintf(stderr,"Error!");
                    break;
                }
            }
            break;
        }
        case 16: {
            switch (exercise) {
                case 1: {
                    ch16_ex01();
                    break;
                }
                case 2: {
                    ch16_ex02();
                    break;
                }
                case 3: {
                    ch16_ex03();
                    break;
                }
                case 4: {
                    ch16_ex04();
                    break;
                }
                case 5: {
                    ch16_ex05();
                    break;
                }
                case 6: {
                    ch16_ex06();
                    break;
                }
                case 7: {
                    ch16_ex07();
                    break;
                }
                case 8: {
                    ch16_ex08();
                    break;
                }
                default: {
                    fprintf(stderr,"Error!");
                    break;
                }
            }
            break;
        }
        case 17: {
            switch (exercise) {
                case 1: {
                    ch17_ex01();
                    break;
                }
                case 2: {
                    ch17_ex02();
                    break;
                }
                case 3: {
                    ch17_ex03();
                    break;
                }
                case 4: {
                    ch17_ex04();
                    break;
                }
                case 5: {
                    ch17_ex05();
                    break;
                }
                case 6: {
                    ch17_ex06();
                    break;
                }
                case 7: {
                    ch17_ex07();
                    break;
                }
                case 8: {
                    ch17_ex08();
                    break;
                }
                default: {
                    fprintf(stderr,"Error!");
                    break;
                }
            }
            break;
        }
        default: {
            fprintf(stderr,"Error!");
            break;
        }
    }
}