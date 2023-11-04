
include_guard(GLOBAL)

# Generate <stdckdint.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDCKDINT_H "1" CACHE STRING "")

check_include_file("stdckdint" HAVE_STDCKDINT_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdckdint.cmake)
endif ()
