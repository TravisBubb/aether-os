#include "test_runner.h"
#include "logging.h"

#define MAX_TESTS 128

// A static registry of test cases
static TestCase test_registry[MAX_TESTS];
static int test_count = 0;

void register_test(const char *name, test_func_t test_func){
    if (test_count + 1 >= MAX_TESTS)
        return;

    TestCase t = {0};
    t.name = name;
    t.func = test_func;

    test_registry[test_count++] = t;
}

void run_tests(){
    TestCase t;
    int failure;

    LOG_INFO("Starting test execution...\n");

    for (int i = 0; i < test_count; i++) {
        t = test_registry[i];
        LOG_INFO("Executing test [%s]... ", t.name);

        failure = t.func();

        if (failure) {
            LOG_INFO("FAILED\n");
        } else {
            LOG_INFO("SUCCESS\n");
        }
    }
    
    LOG_INFO("Finished test execution...\n");
}
