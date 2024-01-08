
include_guard(GLOBAL)

# Don't generate this. We define static_assert in <config.h>.
set(LIBCFUNK_GENERATE_ASSERT_H "0" CACHE STRING "")

check_include_file("assert.h" HAVE_ASSERT_H)

if (HAVE_ASSERT_H)
  find_file(ASSERT_H_PATH NAMES "assert.h" PATHS ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
endif ()

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-assert-h.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-assert-c11.cmake)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-assert-c23.cmake)
endif ()

