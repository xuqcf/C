#ifndef EXERCISE_H
#define EXERCISE_H

#include "munit.h"
#include <stdint.h>

#define munit_case(type, name, ...)                                            \
  static MunitResult name(const MunitParameter params[], void *user_data) {    \
    (void)params;                                                              \
    (void)user_data;                                                           \
    __VA_ARGS__ return MUNIT_OK;                                               \
  }

#define munit_test(path, func)                                                 \
  {(char *)(path), func, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_null_test {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}

#define munit_suite(name, tests)                                               \
  {(char *)(name), tests, NULL, 1, MUNIT_SUITE_OPTION_NONE}

void swap(void *vp1, void *vp2, size_t size);
#define assert_int(a, op, b, msg) munit_assert_int(a, op, b, msg)
#define assert_true(expr) munit_assert_true(expr)

#undef munit_assert_not_null
#define munit_assert_not_null(ptr, msg) munit_assert_ptr(ptr, !=, NULL)

#undef munit_assert_int
#define munit_assert_int(a, op, b, msg) munit_assert_type(int, "d", a, op, b)

#undef munit_assert_float
#define munit_assert_float(a, op, b, msg)                                      \
  munit_assert_type(float, "f", a, op, b)

#undef assert_string_equal
#define assert_string_equal(a, b, msg) munit_assert_string_equal(a, b, msg)
#undef assert_uint16
#define assert_uint16(a, op, b, msg) munit_assert_uint16(a, op, b)

#undef munit_assert_size
#define munit_assert_size(a, op, b, msg)                                       \
  munit_assert_type(size_t, MUNIT_SIZE_MODIFIER "u", a, op, b)
#undef munit_assert_uint8
#define munit_assert_uint8(a, op, b, msg)                                      \
  munit_assert_type(munit_uint8_t, PRIu8, a, op, b)
#undef munit_assert_uint16
#define munit_assert_uint16(a, op, b, msg)                                     \
  munit_assert_type(munit_uint16_t, PRIu16, a, op, b)
#undef munit_assert_uint32
#define munit_assert_uint32(a, op, b, msg)                                     \
  munit_assert_type(munit_uint32_t, PRIu32, a, op, b)
#undef munit_assert_ptr_not_equal
#define munit_assert_ptr_not_equal(a, b, msg) munit_assert_ptr(a, !=, b)

#undef munit_assert_string_equal
#define munit_assert_string_equal(a, b, msg)                                   \
  do {                                                                         \
    const char *munit_tmp_a_ = a;                                              \
    const char *munit_tmp_b_ = b;                                              \
    if (MUNIT_UNLIKELY(strcmp(munit_tmp_a_, munit_tmp_b_) != 0)) {             \
      munit_errorf("assertion failed: string %s == %s (\"%s\" == \"%s\")", #a, \
                   #b, munit_tmp_a_, munit_tmp_b_);                            \
    }                                                                          \
    MUNIT_PUSH_DISABLE_MSVC_C4127_                                             \
  } while (0) MUNIT_POP_DISABLE_MSVC_C4127_

#endif
