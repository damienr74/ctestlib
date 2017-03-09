#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <string.h>

static int hasfailed = 0;
static int testcount = 0;

#define TEST_INFO fprintf(stderr, " %s:%d:%s() ", __FILE__, __LINE__, __func__);

#define TEST do {\
	testcount++;\
	fprintf(stderr, "Running test");\
	TEST_INFO\
	fprintf(stderr, "\n");\
} while (0);

#define END_TESTS do {\
	fprintf(stderr, "\n%d Tests Failed out of %d\n", hasfailed, testcount);\
	return hasfailed;\
} while (0);

#define FAIL_TEST do {\
	TEST_INFO\
	fprintf(stderr, "Test Failed\n");\
	++hasfailed;\
	return;\
} while (0);

#define assert_equals(val, exp, print) do {\
	int __expression = (exp);\
	if (__expression != val) {\
		TEST_INFO\
		char __message[] = "Assert Equals Expected >> "print" but was "\
			print" <<\n";\
		fprintf(stderr, __message, (val), __expression);\
		FAIL_TEST\
	}\
} while (0)

#define assert_not_equals(val, exp, print) do {\
	int __expression = (exp);\
	if (__expression == val) {\
		TEST_INFO\
		char __message[] = "Assert Not Equals Expected not >> "print\
			" but was "print" <<\n";\
		fprintf(stderr, __message, (val), __expression);\
		FAIL_TEST\
	}\
} while (0)

#define assert_str_equals(str1, str2) do {\
	if (strcmp(str1, str2)) {\
		TEST_INFO\
		char __message[] = "Assert Equals Expected >> %s but got %s <<\n";\
		fprintf(stderr, __message, str1, str2);\
		FAIL_TEST\
	}\
} while (0)

#define assert_comparator(comparator, elem1, elem2, tosring) do {\
	if (comparator(elem1, elem2)) {\
		TEST_INFO\
		char __message[] = "Comparator Expected >> %s but got %s <<\n";\
		fprintf(stderr, __message, tosring(elem1), tosring(elem2));\
		FAIL_TEST\
	}\
} while (0)

#endif
