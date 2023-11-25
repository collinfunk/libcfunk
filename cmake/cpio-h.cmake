
include_guard(GLOBAL)

# Generate <cpio.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_CPIO_H "1" CACHE STRING "")

check_include_file("cpio.h" HAVE_CPIO_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-cpio-h.cmake)
endif ()

