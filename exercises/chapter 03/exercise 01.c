#include <stdio.h>


void ch03_ex01(void) {
    unsigned short int test_var_1 = 65535;  // assuming 16-bit short int
    unsigned short int test_var_1_overflow;  // assuming 16-bit short int
    float test_var_2 = 1.11e38f;  // assuming 32-bit float
    float test_var_2_overflow;  // assuming 32-bit float
    float test_var_3 = -1.11e-45f;  // assuming 32-bit float
    float test_var_3_overflow;  // assuming 32-bit float

    test_var_1_overflow = test_var_1 + 1;
    printf("Unsigned short int before overflow: %d\nUnsigned short int after overflow: %d\n", test_var_1, test_var_1_overflow);
    test_var_2_overflow = test_var_2 * 10.0f;
    printf("Float before overflow: %e\nFloat after overflow: %e\n", test_var_2, test_var_2_overflow);
    test_var_3_overflow = test_var_3 / 10.0f;
    printf("Float before underflow: %e\nFloat after underflow: %e\n", test_var_3, test_var_3_overflow);
}