
include_guard(GLOBAL)

# Generate <err.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ERR_H "1" CACHE STRING "")

check_include_file("err.h" HAVE_ERR_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-err-h.cmake)
endif ()

