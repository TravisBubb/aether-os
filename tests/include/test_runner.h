#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

/**
 * @typedef test_func_t
 * @brief Type definition for a test case function
 */
typedef int (*test_func_t)(void);

/**
 * @brief A struct representing a single test case
 */
typedef struct {
  const char *name;
  test_func_t func;
} TestCase;

void register_test(const char *name, test_func_t test_func);
void run_tests(void);

#endif // TEST_RUNNER_H
