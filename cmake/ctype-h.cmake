
include_guard(GLOBAL)

# Generate <ctype.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_CTYPE_H "1" CACHE INTERNAL "")

check_include_file("ctype.h" HAVE_CTYPE_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-ctype-h.cmake)
endif ()

