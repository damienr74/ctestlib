```C
#include "test.h"

#include <stdio.h>
#include <stdlib.h>

static void test_assert_equals(void);
static void test_assert_not_equals(void);
static void test_assert_str_equals(void);
static void test_assert_comparator(void);
static void test_order_of_assert(void);

int main(void)
{
	test_assert_equals();
	test_assert_not_equals();
	test_assert_str_equals();
	test_assert_comparator();
	test_order_of_assert();
	END_TESTS;
}

static void test_assert_equals(void)
{
	TEST;
	assert_equals(2, 2+3-3, "%d");
	assert_equals(2, 3, "%d");
}

static void test_assert_not_equals(void)
{
	TEST;
	assert_equals(-1, 1, "%d");
	assert_not_equals(-1, -1, "%d");
}

static char *tostring(char *str) { return str; }

static void test_assert_str_equals(void)
{
	TEST;
	assert_str_equals("string1", "string1");
	assert_str_equals("string3", "string1");
}

static void test_assert_comparator(void)
{
	TEST;
	assert_comparator(strcmp, "string1", "string1", tostring);
	assert_comparator(strcmp, "string2", "string1", tostring);
}

static void test_order_of_assert(void)
{
	TEST;
	assert_comparator(strcmp, "next test is not run", "", tostring);
	assert_comparator(strcmp, "this test is not run", "", tostring);
}
```

```C
Running test test.c:24:test_assert_equals() 
 test.c:26:test_assert_equals() Assert Equals Expected >> 2 but was 3 <<
 test.c:26:test_assert_equals() Test Failed
Running testRunning test test.c:24:test_assert_equals() 
 test.c:26:test_assert_equals() Assert Equals Expected >> 2 but was 3 <<
 test.c:26:test_assert_equals() Test Failed
Running test test.c:31:test_assert_not_equals() 
 test.c:32:test_assert_not_equals() Assert Equals Expected >> -1 but was 1 <<
 test.c:32:test_assert_not_equals() Test Failed
Running test test.c:40:test_assert_str_equals() 
 test.c:42:test_assert_str_equals() Assert Equals Expected >> string3 but got string1 <<
 test.c:42:test_assert_str_equals() Test Failed
Running test test.c:47:test_assert_comparator() 
 test.c:49:test_assert_comparator() Comparator Expected >> string2 but got string1 <<
 test.c:49:test_assert_comparator() Test Failed
Running test test.c:54:test_order_of_assert() 
 test.c:55:test_order_of_assert() Comparator Expected >> next test is not run but got  <<
 test.c:55:test_order_of_assert() Test Failed

5 Tests Failed out of 5
```
