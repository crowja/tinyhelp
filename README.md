# tinyhelp 0.2.0.

Simple helpers in a single header file supporting Joe Walnes'
[tinytest.h](https://github.com/joewalnes/tinytest) C unit test framework.

## ASSERT macros

The tinytest.h framework provides the test macros `ASSERT()`,
`ASSERT_EQUALS()`, `ASSERT_STRING_EQUALS()`. Tinyhelp.h adds these:

*   `ASSERT_DOUBLE_CLOSE(a, b, tol)` for testing whether doubles `a` and `b`
    are within a tolerance of `tol`. Tested as `fabs(a - b) <= tol`.
*   `ASSERT_DOUBLE_EQUALS(a, b)` for testing if the doubles `a` and `b` are
    equal. Tested as `fabs(a - b) <= 2 * DBL_EPSILON`.
*   `ASSERT_FILE_EQUALS(a, b)` for testing if the contents of files `a` and
    `b` are the same.

## Functions

Tinyhelp.h also provides the helper functions:

```c

     static void  fprintf_test_info(FILE *out, char *name, const char *info)
     static int   doubles_are_close(double x, double y, double tol)
     static int   doubles_are_equal(double x, double y)
     static int   files_are_equal(char *fn1, char *fn2)

```

## Example

```c . . .

     #include "tinytest.h"
     #include "tinyhelp.h"

     static void
     test_near_zero(void)
     {
        double      t = sin(0.0);
        fprintf_test_info(stdout, "test_near_zero", "testing sin near zero");
        ASSERT_DOUBLE_EQUAL(0.0, t);  /* being really strict */
     }

     static void
     test_near_pi(void)
     {
        double      t = sin(3.14159265);
        fprintf_test_info(stdout, "test_near_pi", "testing sin near pi");
        ASSERT_DOUBLE_CLOSE(0.0, t, 0.001);
     }

     int
     main(void)
     {
        printf("%s\n", "My unit test suite");
        RUN(test_near_zero);
        RUN(test_near_pi);
        return TEST_REPORT();
     }

```
