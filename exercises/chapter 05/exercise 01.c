#include <stdio.h>


void ch05_ex01(void) {
    int time_in_minutes;
    int minutes, hours;
    const int min_in_hour = 60;  // minutes in an hour

    printf("Enter time in minutes:\n");
    scanf("%d", &time_in_minutes);

    hours = 0;
    while (time_in_minutes > min_in_hour) {
        hours++;
        time_in_minutes -= min_in_hour;
    }

    minutes = time_in_minutes;

    printf("Entered time equals to %d hours and %d minutes.", hours, minutes);
}
