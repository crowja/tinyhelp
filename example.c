#include <stdlib.h>
#include <stdio.h>
#include <math.h>                                /* testing the sine function */
#include "tinyhelp.h"

static void
test_near_zero(void)
{
   double      t = sin(0.0);
   printf("t is %e\n", t);
   fprintf_test_info(stdout, "test_near_zero", "testing sin near zero");
   ASSERT_DOUBLE_EQUAL(0.0, t);  /* being really strict */
}

static void
test_near_pi(void)
{
   double      t = sin(3.14159265);
   printf("t is %e\n", t);
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
