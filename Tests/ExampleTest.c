#include <unity.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void testEmpty(void) {
}

int main(void) {
  UNITY_BEGIN();
 
  RUN_TEST(testEmpty);
 
  return UNITY_END();
}
