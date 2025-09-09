#include <stdio.h>
#include <stdlib.h>
#define YES 1
#define NO 0
#define SOLID 0
#define DOTTED 1
#define DASHED 2
#define BLUE 4U
#define GREEN 2U
#define RED 1U
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)
const char *const colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};
static void set_property(unsigned int *box, unsigned int property, unsigned int value);
static unsigned int get_property(const unsigned int *box, unsigned int property);


void ch15_ex06(void) {
    unsigned int box = 0;
    set_property(&box, 0, YES);
    set_property(&box, 1, YELLOW);
    set_property(&box, 2, YES);
    set_property(&box, 3, GREEN);
    set_property(&box, 4, DASHED);

    printf("Box is %s.\n", get_property(&box, 0) == YES ? "opaque" : "transparent");
    printf("The border style is ");
    switch (get_property(&box, 4)) {
        case SOLID:
            printf("solid.\n");
            break;
        case DOTTED:
            printf("dotted.\n");
            break;
        case DASHED:
            printf("dashed.\n");
            break;
        default:
            printf("unknown type.\n");
    }
    printf("The fill color is %s.\n", colors[get_property(&box, 1)]);
    printf("The border color is %s.\n", colors[get_property(&box, 3)]);

    set_property(&box, 0, NO);
    set_property(&box, 1, WHITE);
    set_property(&box, 3, MAGENTA);
    set_property(&box, 4, SOLID);

    printf("After changes, box is %s.\n", get_property(&box, 0) == YES ? "opaque" : "transparent");
    printf("The border style is ");
    switch (get_property(&box, 4)) {
        case SOLID:
            printf("solid.\n");
            break;
        case DOTTED:
            printf("dotted.\n");
            break;
        case DASHED:
            printf("dashed.\n");
            break;
        default:
            printf("unknown type.\n");
    }
    printf("The fill color is %s.\n", colors[get_property(&box, 1)]);
    printf("The border color is %s.\n", colors[get_property(&box, 3)]);
}

static void set_property(unsigned int *box, unsigned int property, unsigned int value) {
    /* property 0: opaque
     * property 1: fill color
     * property 2: show border
     * property 3: border color
     * property 4: border style
     */
    /* bit 0: opaque
     * bit 1-3: fill color
     * bit 4: show border
     * bit 5-7: border color
     * bit 8-9: border style
     */

    switch (property) {
        case 0: {
            *box &= ~1U;
            *box |= value;
            break;
        }
        case 1: {
            value <<= 1U;
            *box &= ~0x0eU;
            *box |= value;
            break;
        }
        case 2: {
            value <<= 4U;
            *box &= ~0x10U;
            *box |= value;
            break;
        }
        case 3: {
            value <<= 5U;
            *box &= ~0xe0U;
            *box |= value;
            break;
        }
        case 4: {
            value <<= 8U;
            *box &= ~0x300U;
            *box |= value;
            break;
        }
        default: {
            fprintf(stderr, "Invalid property index.\n");
            exit(EXIT_FAILURE);
        }
    }
}

static unsigned int get_property(const unsigned int *box, unsigned int property) {
    /* property 0: opaque
     * property 1: fill color
     * property 2: show border
     * property 3: border color
     * property 4: border style
     */
    /* bit 0: opaque
     * bit 1-3: fill color
     * bit 4: show border
     * bit 5-7: border color
     * bit 8-9: border style
     */
    unsigned int result;

    switch (property) {
        case 0: {
            result = *box & 1U;
            break;
        }
        case 1: {
            result = (*box & 0xeU) >> 1U;
            break;
        }
        case 2: {
            result = (*box & 0x10U) >> 4U;
            break;
        }
        case 3: {
            result = (*box & 0xE0U) >> 5U;
            break;
        }
        case 4: {
            result = (*box & 0x300U) >> 8U;
            break;
        }
        default: {
            fprintf(stderr, "Invalid property index.\n");
            exit(EXIT_FAILURE);
        }
    }

    return result;
}
