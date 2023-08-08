#include <math.h>
#include <stdio.h>
struct polar {
    double magnitude;
    double angle;
};
struct rect {
    double x;
    double y;
};
static struct rect polar_to_rect(struct polar p);
static const double DEG_TO_RAD = 3.14159265358979323846 / 180.0;


void ch16_ex03(void) {
    struct polar input;
    struct rect output;

    printf("Enter magnitude and angle in degrees (q to quit):\n");
    while (scanf("%lf %lf", &input.magnitude, &input.angle) == 2) {
        input.angle *= DEG_TO_RAD;
        output = polar_to_rect(input);
        printf("x = %.2f, y = %.2f\n", output.x, output.y);
        printf("Enter magnitude and angle in degrees (q to quit):\n");
    }
}

static struct rect polar_to_rect(struct polar p) {
    struct rect r;
    r.x = p.magnitude * cos(p.angle);
    r.y = p.magnitude * sin(p.angle);
    return r;
}