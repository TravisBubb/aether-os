#ifndef TEST_ASSERT_H
#define TEST_ASSERT_H

#define assert(cond) \
    if (!(cond)) return 1;

#define assert_eq(a, b) \
    if ((a) != (b)) return 1;

#define assert_neq(a, b) \
    if ((a) == (b)) return 1;

#endif // TEST_ASSERT_H
