
include_guard(GLOBAL)

include($CACHE{LIBCFUNK_MODULE_DIR}/errno-h.cmake)
include($CACHE{LIBCFUNK_MODULE_DIR}/stddef-h.cmake)

# Generate <argz.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_ARGZ_H "1" CACHE STRING "")

check_include_file("argz.h" HAVE_ARGZ_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-argz-h.cmake)
endif ()
