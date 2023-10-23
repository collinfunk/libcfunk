
include_guard(GLOBAL)

# Generate <error.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ERROR_H "1" CACHE INTERNAL "")

check_include_file("error.h" HAVE_ERROR_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-error-h.cmake)
endif ()

