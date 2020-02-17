# tinyhelp 0.1.0.

Simple helpers supporting Joe Walnes'
[tinytest.h](https://github.com/joewalnes/tinytest) C unit test framework.

## ASSERT macros

The tinytest.h framework provides the ASSERT macros ASSERT(), ASSERT\_EQUALS(),
ASSERT\_STRING\_EQUALS(). Tinyhelp.h adds these:

*   ASSERT\_DOUBLE\_CLOSE(a, b, tol) for testing whether doubles a and b are
    within a tolerance of tol. Tested as fabs(a - b) <= tol.
*   ASSERT\_DOUBLE\_EQUAL(a, b) for testing if double a and b are equal. Tested
    as fabs(a - b) <= 2 * DBL\_EPSILON.

## Functions

Tinyhelp.h also provides the function

*   fprintf\_test\_info() for printing brief information about a unit test; see
    below.

## Example

```c

     #include <stdlib.h>
     #include <stdio.h>
     #include <math.h>                   /* we're testing the sine function */
     #include "tinytest.h"
     #include "tinyhelp.h"
     
     static void test01(void) {
        double t = sin(0.0);
        fprintf_test_info(stdout, "test01", "testing sin() at zero");
        ASSERT_DOUBLE_EQUALS(0.0, t);    /* really strict at zero */
     }
     
     static void test02(void) {
        double t = sin(3.14159265);
        fprintf_test_info(stdout, "test02", "testing sin() near pi");
        ASSERT_DOUBLE_CLOSE(0.0, t, 0.001);
     }
     
     int main(void)
     {
        printf("%s\n", "My unit test suite for the sine function");
        RUN(test01);
        RUN(test02);
        return TEST_REPORT();
     }

```
