
include_guard(GLOBAL)

# Generate <stdnoreturn.h> at libcfunk-final.cmake
set(LIBCFUNK_GENERATE_STDNORETURN_H "1" CACHE STRING "")

check_include_file("stdnoreturn.h" HAVE_STDNORETURN_H)

if (LIBCFUNK_ENABLE_TESTS)
  include($CACHE{LIBCFUNK_MODULE_DIR}/test-stdnoreturn-h.cmake)
endif ()

